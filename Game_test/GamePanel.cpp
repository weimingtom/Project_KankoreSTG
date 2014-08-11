#include "GamePanel.h"
#include "PanelControler.h"
#include "Shipcontroller.h"

extern PanelControler controler;
extern  Shiptable *table;
GamePanel::GamePanel(int id) : GUIPanel(id){;}
GamePanel::~GamePanel()
{
	delete PlayGroundTarget;
	delete ill;
	delete cursor_spr;
	delete mapReader;
	delete myship;
	delete shiptest;
	delete shiptest2;
	delete shiptest3;
}
bool GamePanel::stopFlag = false;

bool GamePanel::InitResource()
{
	//初始化背景資源
	stopFlag = false;
	Background.tex = hge->Texture_Load("meterial/background/Game_Play_bg.png");
	if (Background.tex != 0)
	{
		Background.blend=BLEND_ALPHABLEND | BLEND_ZWRITE;
		//設置紋理貼圖區域，指定整個TARGET渲染區域
		Background.v[0].x=0;  Background.v[0].y=0;
		Background.v[1].x=1280;  Background.v[1].y=0;
		Background.v[2].x=1280;  Background.v[2].y=960;
		Background.v[3].x=0;  Background.v[3].y=960;
		//設置圖片像素範圍，填滿渲染
		Background.v[0].tx=0;					Background.v[0].ty=0;
		Background.v[1].tx=0.625;				Background.v[1].ty=0;
		Background.v[2].tx=0.625;				Background.v[2].ty=0.937;
		Background.v[3].tx=0;					Background.v[3].ty=0.937;
		//設置圖片透明度
		for (int i=0;i<4;i++)
		{
			Background.v[i].z=0.0f;
			Background.v[i].col=0xFFFFFFFF;
		}
	}
	//初始化遊戲邊界
	width = 800;
	height = 900;
	target=hge->Target_Create(width,height,false);
	PlayGroundTarget = new hgeSprite(hge->Target_GetTexture(target),0,0,width,height);
	PlayGroundTarget->SetBlendMode(BLEND_ALPHABLEND | BLEND_ZWRITE);
	ill = new hgeSprite(hge->Texture_Load("meterial/ill/ill_kongou.png"),0,0,600,800);
	ill->SetColor(ARGB(128,0,0,0));
	//初始化選單
	cursor_tex = hge->Texture_Load("cursor.png");
	cursor_spr=new hgeSprite(cursor_tex,0,0,32,32);
	gui->AddCtrl(new hgeGUIMenuItem(1,HgeFont,0,hge->System_GetState(HGE_SCREENWIDTH)/2,400,0.0f,"Resume"));
	gui->AddCtrl(new hgeGUIMenuItem(2,HgeFont,0,hge->System_GetState(HGE_SCREENWIDTH)/2,500,0.2f,"Exit"));
	gui->Enter();
	gui->ShowCtrl(1,false);
	gui->EnableCtrl(1,false);
	gui->ShowCtrl(2,false);
	gui->EnableCtrl(2,false);
	gui->SetCursor(0);
	hge->System_SetState(HGE_FOCUSLOSTFUNC,GamePanel::SystemLostFoucus);

	//初始化紅色遮罩
	Mask.tex=0;
	Mask.blend = (BLEND_ALPHABLEND | BLEND_ZWRITE | BLEND_ALPHAADD);
	//設置紋理貼圖區域，指定整個螢幕渲染區域
	Mask.v[0].x=0;  Mask.v[0].y=0;
	Mask.v[1].x=1280;  Mask.v[1].y=0;
	Mask.v[2].x=1280;  Mask.v[2].y=960;
	Mask.v[3].x=0;  Mask.v[3].y=960;
	for (int i=0;i<4;i++)
	{
		Mask.v[i].z=0.0f;
		Mask.v[i].col=ARGB(160,0,0,20);
	}
	//初始化我方角色物件
	myship = new Kongo();
	myship->setEquipData(0,1,2,3);
	//初始化所有角色資源
	table = new Shiptable();
	Shipcontroller::loadShip();
	//初始化腳本資源
	mapReader = new MapScript("D:\\HGE\\Game_test\\Debug\\script\\map\\map_1_1.txt");
	mapReader->ScriptRead();
	return false;
}

void GamePanel::RenderTarget()
{
	hge->Gfx_BeginScene(target);
	hge->Gfx_Clear(0);
	Shipcontroller::renderShip();
	hge->Gfx_EndScene();
}
void GamePanel::RenderFucn()
{
	RenderTarget();
	hge->Gfx_BeginScene();
	//顯示背景
	hge->Gfx_Clear(0);
	if (Background.tex!=0)
		hge->Gfx_RenderQuad(&Background);
	else
		ChFont->Print(100,100,"No Background.");
	ill->Render(700,400);
	//顯示遊戲畫面
	PlayGroundTarget->Render(10,20);
	//遊戲資訊
	ChFont->Print(820,100,"ＰＯＩＮＴ：００００００００");
	ChFont->Print(820,180,"ＬＩＦＥ：００００００００");
	ChFont->Print(1100,900,"ＦＰＳ:%d",hge->Timer_GetFPS());
	//ESC選單
	if (stopFlag)
		hge->Gfx_RenderQuad(&Mask);
	gui->Render();
	hge->Gfx_EndScene();
}
bool GamePanel::FrameFucn()
{
	//角色物件控制
	if (!stopFlag)
		Shipcontroller::frameShip();
	//ESC鍵功能
	if (hge->Input_KeyDown(HGEK_ESCAPE))
	{
		stopFlag = !stopFlag;
	}
	//GUI控制功能實作
	int id = gui->Update(hge->Timer_GetDelta());
	switch (id)
	{
	case 1:
		stopFlag = !stopFlag;
		break;
	case 2:
		mapReader->Stop();
		Shipcontroller::deleteShip();
		//delete mapReader;
		controler.SetCurrentPanel(new HomePanel(1));
		return false;
	default:
		break;
	}
	if (checkFlagChange())
	{
		gui->ShowCtrl(1,stopFlag);
		gui->EnableCtrl(1,stopFlag);
		gui->ShowCtrl(2,stopFlag);
		gui->EnableCtrl(2,stopFlag);
		gui->SetFocus(1);
		if (stopFlag)
		{
			mapReader->PauseRead();
			gui->SetCursor(cursor_spr);
			gui->Enter();
		}
		else
		{
			mapReader->StartRead();
			gui->SetCursor(0);
			gui->Leave();
		}
	}

	return false;
}
bool GamePanel::checkFlagChange()
{
	static bool check = 0;
	if (check == stopFlag)
		return false;
	else
		check = stopFlag;
	return true;
}
bool GamePanel::SystemLostFoucus()
{
	stopFlag = true;
	MapScript::PauseRead();
	return false;
}

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
	//��l�ƭI���귽
	stopFlag = false;
	Background.tex = hge->Texture_Load("meterial/background/Game_Play_bg.png");
	if (Background.tex != 0)
	{
		Background.blend=BLEND_ALPHABLEND | BLEND_ZWRITE;
		//�]�m���z�K�ϰϰ�A���w���TARGET��V�ϰ�
		Background.v[0].x=0;  Background.v[0].y=0;
		Background.v[1].x=1280;  Background.v[1].y=0;
		Background.v[2].x=1280;  Background.v[2].y=960;
		Background.v[3].x=0;  Background.v[3].y=960;
		//�]�m�Ϥ������d��A�񺡴�V
		Background.v[0].tx=0;					Background.v[0].ty=0;
		Background.v[1].tx=0.625;				Background.v[1].ty=0;
		Background.v[2].tx=0.625;				Background.v[2].ty=0.937;
		Background.v[3].tx=0;					Background.v[3].ty=0.937;
		//�]�m�Ϥ��z����
		for (int i=0;i<4;i++)
		{
			Background.v[i].z=0.0f;
			Background.v[i].col=0xFFFFFFFF;
		}
	}
	//��l�ƹC�����
	width = 800;
	height = 900;
	target=hge->Target_Create(width,height,false);
	PlayGroundTarget = new hgeSprite(hge->Target_GetTexture(target),0,0,width,height);
	PlayGroundTarget->SetBlendMode(BLEND_ALPHABLEND | BLEND_ZWRITE);
	ill = new hgeSprite(hge->Texture_Load("meterial/ill/ill_kongou.png"),0,0,600,800);
	ill->SetColor(ARGB(128,0,0,0));
	//��l�ƿ��
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

	//��l�Ƭ���B�n
	Mask.tex=0;
	Mask.blend = (BLEND_ALPHABLEND | BLEND_ZWRITE | BLEND_ALPHAADD);
	//�]�m���z�K�ϰϰ�A���w��ӿù���V�ϰ�
	Mask.v[0].x=0;  Mask.v[0].y=0;
	Mask.v[1].x=1280;  Mask.v[1].y=0;
	Mask.v[2].x=1280;  Mask.v[2].y=960;
	Mask.v[3].x=0;  Mask.v[3].y=960;
	for (int i=0;i<4;i++)
	{
		Mask.v[i].z=0.0f;
		Mask.v[i].col=ARGB(160,0,0,20);
	}
	//��l�Ƨڤ訤�⪫��
	myship = new Kongo();
	myship->setEquipData(0,1,2,3);
	//��l�ƩҦ�����귽
	table = new Shiptable();
	Shipcontroller::loadShip();
	//��l�Ƹ}���귽
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
	//��ܭI��
	hge->Gfx_Clear(0);
	if (Background.tex!=0)
		hge->Gfx_RenderQuad(&Background);
	else
		ChFont->Print(100,100,"No Background.");
	ill->Render(700,400);
	//��ܹC���e��
	PlayGroundTarget->Render(10,20);
	//�C����T
	ChFont->Print(820,100,"�ޢݢעܢ�G����������������");
	ChFont->Print(820,180,"�ڢעԢӡG����������������");
	ChFont->Print(1100,900,"�Ԣޢ�:%d",hge->Timer_GetFPS());
	//ESC���
	if (stopFlag)
		hge->Gfx_RenderQuad(&Mask);
	gui->Render();
	hge->Gfx_EndScene();
}
bool GamePanel::FrameFucn()
{
	//���⪫�󱱨�
	if (!stopFlag)
		Shipcontroller::frameShip();
	//ESC��\��
	if (hge->Input_KeyDown(HGEK_ESCAPE))
	{
		stopFlag = !stopFlag;
	}
	//GUI����\���@
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

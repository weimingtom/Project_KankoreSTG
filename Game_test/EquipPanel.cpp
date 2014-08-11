#include "EquipPanel.h"
#include "PanelControler.h"
#include "GfxFont.h"
extern PanelControler controler;

EquipPanel::EquipPanel(int id):GUIPanel(id){};

static int lastid=0;
static int nowID=24;
static int j;

EquipPanel::~EquipPanel()
{
	delete spr;
	delete person;
	delete Bar_Top;
	delete naka_buy;
	delete shimakaze_buy;
	delete kongo_buy;
	delete agano_buy;
}

void EquipPanel::RenderFucn()
{
	// Render graphics
	//呼叫「hgeGUI::Render」繪製選單
	hge->Gfx_BeginScene();
	hge->Gfx_RenderQuad(&quad);
	Bar_Top->Render(0,65);

	if(lastid == 24 || (nowID == 24))
	{
		naka_buy->RenderEx( (hge->System_GetState(HGE_SCREENWIDTH)*0.52), 250, 0, 1.0f, 1.0f);
	}
	else if(lastid == 25 || (nowID == 25))
	{
		shimakaze_buy->RenderEx( (hge->System_GetState(HGE_SCREENWIDTH)*0.50), 250, 0, 1.0f, 1.0f);
	}
	else if(lastid == 26 || (nowID == 26))
	{
		kongo_buy->RenderEx( (hge->System_GetState(HGE_SCREENWIDTH)*0.50), 250, 0, 1.0f, 1.0f);
	}
	else if(lastid == 27 || (nowID == 27))
	{
		agano_buy->RenderEx( (hge->System_GetState(HGE_SCREENWIDTH)*0.48), 250, 0, 1.0f, 1.0f);
	}
	else {}

	if(gui->GetCtrl(24)->bVisible)
	{
		//ChFont->Print(680,680,"#K數值變化：");
		ChFont->Print(380,190,"#K裝備");
		ChFont->Print(280,270,"#K12 cm 單裝砲");
		ChFont->Print(280,310,"#K12.7 cm 連裝砲");
		ChFont->Print(280,350,"#K14 cm 單裝砲");
		ChFont->Print(280,390,"#K35.6 cm 連裝砲");
		ChFont->Print(280,430,"#K41 cm 連裝砲");
		ChFont->Print(280,470,"#K10 cm 連裝高角砲");
		ChFont->Print(280,510,"#K12.7 cm 連裝高角砲");
		ChFont->Print(280,550,"#K61 cm 三連裝魚雷");
		ChFont->Print(280,590,"#K61 cm 四連裝魚雷");
		ChFont->Print(280,630,"#K強化型艦本式缶");
	}

	HgeFont->SetColor(0xFF00FF00);	//0xFFFFFFFF 
	HgeFont->printf(5, 5, HGETEXT_LEFT, "dt:%.3f\nFPS:%d", hge->Timer_GetDelta(), hge->Timer_GetFPS());
	ChFont->Print(900,80,"#W金錢：#W%d",controler.GetAdmiral()->getMoney());
	if (!gui->GetCtrl(49)->bVisible)
		ChFont->Print(800,800,"#K所需金額：%d",SumOnScreen);
	gui->Render();
	hge->Gfx_EndScene();
}

bool EquipPanel::FrameFucn()
{
	float dt=hge->Timer_GetDelta();
	static float t=0.0f;
	float tx,ty;
	int id;
	//static int lastid=0;

	// If ESCAPE was pressed, tell the GUI to finish
	if(hge->Input_GetKeyState(HGEK_ESCAPE)) { lastid=5; gui->Leave();return 1; }

		
	// We update the GUI and take an action if
	// one of the menu items was selected
	int item_Sum = 0;
	for (int i = 39 ; i < 49 ; i++)
	{
		if (gui->GetCtrl(i)->bVisible)
		{
			item_Sum+=2500;
		}
	}
	SumOnScreen = item_Sum;
	if (item_Sum > controler.GetAdmiral()->getMoney())
	{
		gui->EnableCtrl(28,false);
	}
	else
	{
		gui->EnableCtrl(28,true);
	}
	id=gui->Update(dt);
	if(id == -1)
	{
		switch(lastid)
		{
			//Exit
			case 3: 
				return true;
				break;
			case 9:
				//back
				gui->ShowCtrl(19,true);
				gui->EnableCtrl(19,true);

				//new item
				gui->ShowCtrl(24,true);
				gui->EnableCtrl(24,true);
				gui->ShowCtrl(25,true);
				gui->EnableCtrl(25,true);
				gui->ShowCtrl(26,true);
				gui->EnableCtrl(26,true);
				gui->ShowCtrl(27,true);
				gui->EnableCtrl(27,true);
				//buy-button
				gui->ShowCtrl(28,true);
				gui->EnableCtrl(28,true);
				//Checkbox
				gui->ShowCtrl(29,true);
				gui->EnableCtrl(29,true);
				gui->ShowCtrl(30,true);
				gui->EnableCtrl(30,true);
				gui->ShowCtrl(31,true);
				gui->EnableCtrl(31,true);
				gui->ShowCtrl(32,true);
				gui->EnableCtrl(32,true);
				gui->ShowCtrl(33,true);
				gui->EnableCtrl(33,true);
				gui->ShowCtrl(34,true);
				gui->EnableCtrl(34,true);
				gui->ShowCtrl(35,true);
				gui->EnableCtrl(35,true);
				gui->ShowCtrl(36,true);
				gui->EnableCtrl(36,true);
				gui->ShowCtrl(37,true);
				gui->EnableCtrl(37,true);
				gui->ShowCtrl(38,true);
				gui->EnableCtrl(38,true);


				gui->SetFocus(1);
				gui->Enter();
				break;

			//Return
			case 19:
				controler.SetCurrentPanel(new HomePanel(2));
				return false;
			//購買時的人物選擇按鈕
			case 24:
				nowID = 24;
				gui->SetFocus(1);
				gui->Enter();
				break;
			case 25:
				nowID = 25;
				gui->SetFocus(1);
				gui->Enter();
				break;
			case 26:
				nowID = 26;
				gui->SetFocus(1);
				gui->Enter();
				break;
			case 27:
				nowID = 27;


				gui->SetFocus(1);
				gui->Enter();
				break;
			//buy-button(決定)
			case 28:
				CheckItem();
				for(int i=24; i<49; i++)
				{
					gui->ShowCtrl(i,false);
					gui->EnableCtrl(i,false);
				}
				gui->ShowCtrl(19,false);
				gui->EnableCtrl(19,false);
				//YSE NO button
				gui->ShowCtrl(49,true);
				gui->EnableCtrl(49,true);
				gui->ShowCtrl(50,true);
				gui->EnableCtrl(50,true);
				Lock_Sum=item_Sum;
				nowID = 0;

				gui->SetFocus(1);
				gui->Enter();
				break;
			//Checkbox
			case 29:
				gui->ShowCtrl(29,false);
				gui->EnableCtrl(29,false);
				gui->ShowCtrl(39,true);
				gui->EnableCtrl(39,true);


				gui->SetFocus(1);
				gui->Enter();
				break;
			case 30:
				gui->ShowCtrl(30,false);
				gui->EnableCtrl(30,false);
				gui->ShowCtrl(40,true);
				gui->EnableCtrl(40,true);

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 31:
				gui->ShowCtrl(31,false);
				gui->EnableCtrl(31,false);
				gui->ShowCtrl(41,true);
				gui->EnableCtrl(41,true);

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 32:
				gui->ShowCtrl(32,false);
				gui->EnableCtrl(32,false);
				gui->ShowCtrl(42,true);
				gui->EnableCtrl(42,true);

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 33:
				gui->ShowCtrl(33,false);
				gui->EnableCtrl(33,false);
				gui->ShowCtrl(43,true);
				gui->EnableCtrl(43,true);

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 34:
				gui->ShowCtrl(34,false);
				gui->EnableCtrl(34,false);
				gui->ShowCtrl(44,true);
				gui->EnableCtrl(44,true);

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 35:
				gui->ShowCtrl(35,false);
				gui->EnableCtrl(35,false);
				gui->ShowCtrl(45,true);
				gui->EnableCtrl(45,true);

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 36:
				gui->ShowCtrl(36,false);
				gui->EnableCtrl(36,false);
				gui->ShowCtrl(46,true);
				gui->EnableCtrl(46,true);
				
				gui->SetFocus(1);
				gui->Enter();
				break;
			case 37:
				gui->ShowCtrl(37,false);
				gui->EnableCtrl(37,false);
				gui->ShowCtrl(47,true);
				gui->EnableCtrl(47,true);

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 38:
				gui->ShowCtrl(38,false);
				gui->EnableCtrl(38,false);
				gui->ShowCtrl(48,true);
				gui->EnableCtrl(48,true);

				gui->SetFocus(1);
				gui->Enter();
				break;
			//Checkbox_yes
			case 39:
				gui->ShowCtrl(29,true);
				gui->EnableCtrl(29,true);
				gui->ShowCtrl(39,false);
				gui->EnableCtrl(39,false);

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 40:
				gui->ShowCtrl(30,true);
				gui->EnableCtrl(30,true);
				gui->ShowCtrl(40,false);
				gui->EnableCtrl(40,false);

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 41:
				gui->ShowCtrl(31,true);
				gui->EnableCtrl(31,true);
				gui->ShowCtrl(41,false);
				gui->EnableCtrl(41,false);

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 42:
				gui->ShowCtrl(32,true);
				gui->EnableCtrl(32,true);
				gui->ShowCtrl(42,false);
				gui->EnableCtrl(42,false);

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 43:
				gui->ShowCtrl(33,true);
				gui->EnableCtrl(33,true);
				gui->ShowCtrl(43,false);
				gui->EnableCtrl(43,false);

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 44:
				gui->ShowCtrl(34,true);
				gui->EnableCtrl(34,true);
				gui->ShowCtrl(44,false);
				gui->EnableCtrl(44,false);

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 45:
				gui->ShowCtrl(35,true);
				gui->EnableCtrl(35,true);
				gui->ShowCtrl(45,false);
				gui->EnableCtrl(45,false);

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 46:
				gui->ShowCtrl(36,true);
				gui->EnableCtrl(36,true);
				gui->ShowCtrl(46,false);
				gui->EnableCtrl(46,false);

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 47:
				gui->ShowCtrl(37,true);
				gui->EnableCtrl(37,true);
				gui->ShowCtrl(47,false);
				gui->EnableCtrl(47,false);

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 48:
				gui->ShowCtrl(38,true);
				gui->EnableCtrl(38,true);
				gui->ShowCtrl(48,false);
				gui->EnableCtrl(48,false);

				gui->SetFocus(1);
				gui->Enter();
				break;
			//Yes No button(確認是否購買)
			case 49:
				
				controler.GetAdmiral()->setMoney(controler.GetAdmiral()->getMoney()-Lock_Sum);
				for (int i = 0 ; i<80 ;i++)
				{
					if (CheckItemList[i] == 1)
						controler.GetAdmiral()->addEquipInventory(i,1);
				}
				controler.GetAdmiral()->Saving();
				controler.SetCurrentPanel(new HomePanel(2));
				return false;
			case 50:
				controler.SetCurrentPanel(new HomePanel(2));
				return false;
		}
	}
	else if(id) { lastid=id; gui->Leave(); }


	// Here we update our background animation
	t+=dt;
	tx=50*cosf(t/60);
	ty=50*sinf(t/60);

	quad.v[0].tx=tx;        quad.v[0].ty=ty;
	quad.v[1].tx=tx+800/64; quad.v[1].ty=ty;
	quad.v[2].tx=tx+800/64; quad.v[2].ty=ty+600/64;
	quad.v[3].tx=tx;        quad.v[3].ty=ty+600/64;
	return false;
}

bool EquipPanel::FreeFucn()
{
	// Delete created objects and free loaded resources
	//關閉程式時，釋放GUI和資源
	delete spr;
	hge->Effect_Free(snd);
	hge->Texture_Free(tex);
	hge->Texture_Free(quad.tex);
	return false;
}

bool EquipPanel::InitResource()
{
	// Load sound and textures
	quad.tex=hge->Texture_Load("sea3.png");
	tex=hge->Texture_Load("cursor.png");
	person = new hgeSprite(hge->Texture_Load("landwind.png"),0.832,0.5859,426,600);
	naka_buy = new hgeSprite(hge->Texture_Load("naka_buy.png"), 0.43, 0.78, 220, 400);
	shimakaze_buy = new hgeSprite(hge->Texture_Load("shimakaze_buy.png"), 0.586, 0.78, 300, 400);
	kongo_buy = new hgeSprite(hge->Texture_Load("kongo_buy.png"), 0.586, 0.78, 300, 400);
	agano_buy = new hgeSprite(hge->Texture_Load("agano_buy.png"), 0.586, 0.78, 300, 400);
	snd=hge->Effect_Load("menu.wav");
	if(!quad.tex || !tex || !snd)
	{
		// If one of the data files is not found, display
		// an error message and shutdown.
		MessageBox(NULL, "Can't load BG.PNG, CURSOR.PNG or MENU.WAV", "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		hge->System_Shutdown();
		hge->Release();
		return 0;
	}

	// Set up the quad we will use for background animation
	quad.blend=BLEND_ALPHABLEND | BLEND_COLORMUL | BLEND_NOZWRITE;

	for(int i=0;i<4;i++)
	{
		// Set up z-coordinate of vertices
		quad.v[i].z=0.5f;
		// Set up color. The format of DWORD col is 0xAARRGGBB
		quad.v[i].col=0xFFFFFFFF;	//0xFFFFFFFF	這就是背景顏色!!!
	}

	quad.v[0].x=0; quad.v[0].y=0; 
	quad.v[1].x=1280; quad.v[1].y=0; 
	quad.v[2].x=1280; quad.v[2].y=960; 
	quad.v[3].x=0; quad.v[3].y=960; 


	// Load the font, create the cursor sprite
	//HgeFont=new hgeFont("font1.fnt");
	HgeFont->SetScale(1.5f);
	spr=new hgeSprite(tex,0,0,32,32);

	// Create and initialize the GUI
	//產生GUI並加入選單項目進去。
	//Top Bar
	Bar_Top =  new hgeSprite (0,0,0,hge->System_GetState(HGE_SCREENWIDTH),70);
	Bar_Top->SetColor(ARGB(255,48,46,42),0);
	Bar_Top->SetColor(ARGB(200,48,46,42),1);
	Bar_Top->SetColor(ARGB(255,48,46,42),2);
	Bar_Top->SetColor(ARGB(200,48,46,42),3);

	//gui->AddCtrl(new hgeGUIMenuItem(1,HgeFont,snd,hge->System_GetState(HGE_SCREENWIDTH)/2,600,0.0f,"Start Game"));
	TEX_BUTTON = hge->Texture_Load("kankore_logo.png");
	//出擊

	//*************

	//建造

	//*************

	//購買
	gui->AddCtrl(new hgeGUIButton(24, (hge->System_GetState(HGE_SCREENWIDTH)*0.46),170,64,64,hge->Texture_Load("number1.png"),0.5,0.5));
	gui->ShowCtrl(24,true);
	gui->EnableCtrl(24,true);
	gui->AddCtrl(new hgeGUIButton(25, (hge->System_GetState(HGE_SCREENWIDTH)*0.54),170,64,64,hge->Texture_Load("number2.png"),0.5,0.5));
	gui->ShowCtrl(25,true);
	gui->EnableCtrl(25,true);
	gui->AddCtrl(new hgeGUIButton(26, (hge->System_GetState(HGE_SCREENWIDTH)*0.62),170,64,64,hge->Texture_Load("number3.png"),0.5,0.5));
	gui->ShowCtrl(26,true);
	gui->EnableCtrl(26,true);
	gui->AddCtrl(new hgeGUIButton(27, (hge->System_GetState(HGE_SCREENWIDTH)*0.70),170,64,64,hge->Texture_Load("number4.png"),0.5,0.5));
	gui->ShowCtrl(27,true);
	gui->EnableCtrl(27,true);
	//Buy-button
	gui->AddCtrl(new hgeGUIButton(28, (hge->System_GetState(HGE_SCREENWIDTH)*0.35),800,236,89,hge->Texture_Load("buy.png"),0.92,0.695));
	gui->ShowCtrl(28,true);
	gui->EnableCtrl(28,true);
	//Checkbox
	gui->AddCtrl(new hgeGUIButton(29, 220,265,50,45,hge->Texture_Load("checkbox.png"),0.78,0.70));
	gui->ShowCtrl(29,true);
	gui->EnableCtrl(29,true);
	gui->AddCtrl(new hgeGUIButton(30, 220,305,50,45,hge->Texture_Load("checkbox.png"),0.78,0.70));
	gui->ShowCtrl(30,true);
	gui->EnableCtrl(30,true);
	gui->AddCtrl(new hgeGUIButton(31, 220,345,50,45,hge->Texture_Load("checkbox.png"),0.78,0.70));
	gui->ShowCtrl(31,true);
	gui->EnableCtrl(31,true);
	gui->AddCtrl(new hgeGUIButton(32, 220,385,50,45,hge->Texture_Load("checkbox.png"),0.78,0.70));
	gui->ShowCtrl(32,true);
	gui->EnableCtrl(32,true);
	gui->AddCtrl(new hgeGUIButton(33, 220,425,50,45,hge->Texture_Load("checkbox.png"),0.78,0.70));
	gui->ShowCtrl(33,true);
	gui->EnableCtrl(33,true);
	gui->AddCtrl(new hgeGUIButton(34, 220,465,50,45,hge->Texture_Load("checkbox.png"),0.78,0.70));
	gui->ShowCtrl(34,true);
	gui->EnableCtrl(34,true);
	gui->AddCtrl(new hgeGUIButton(35, 220,505,50,45,hge->Texture_Load("checkbox.png"),0.78,0.70));
	gui->ShowCtrl(35,true);
	gui->EnableCtrl(35,true);
	gui->AddCtrl(new hgeGUIButton(36, 220,545,50,45,hge->Texture_Load("checkbox.png"),0.78,0.70));
	gui->ShowCtrl(36,true);
	gui->EnableCtrl(36,true);
	gui->AddCtrl(new hgeGUIButton(37, 220,585,50,45,hge->Texture_Load("checkbox.png"),0.78,0.70));
	gui->ShowCtrl(37,true);
	gui->EnableCtrl(37,true);
	gui->AddCtrl(new hgeGUIButton(38, 220,625,50,45,hge->Texture_Load("checkbox.png"),0.78,0.70));
	gui->ShowCtrl(38,true);
	gui->EnableCtrl(38,true);
	//checkbox_yes
	for(int i=39; i<49; i++)
	{
		gui->AddCtrl(new hgeGUIButton(i, 220,265+(i-39)*40,50,49,hge->Texture_Load("checkedbox_yes.png"),0.78,0.765));
		gui->ShowCtrl(i,false);
		gui->EnableCtrl(i,false);
	}
	//Yes and No
	gui->AddCtrl(new hgeGUIButton(49, (hge->System_GetState(HGE_SCREENWIDTH)*0.5-100), (hge->System_GetState(HGE_SCREENHEIGHT)*0.5), 100,42,hge->Texture_Load("yes.png"),0.78,0.656));
	gui->ShowCtrl(49,false);
	gui->EnableCtrl(49,false);

	gui->AddCtrl(new hgeGUIButton(50, (hge->System_GetState(HGE_SCREENWIDTH)*0.5+100), (hge->System_GetState(HGE_SCREENHEIGHT)*0.5), 100,42,hge->Texture_Load("no.png"),0.78,0.656));
	gui->ShowCtrl(50,false);
	gui->EnableCtrl(50,false);
	//*************
	
	//Back
	gui->AddCtrl(new hgeGUIButton(19,(hge->System_GetState(HGE_SCREENWIDTH)*0.86),800,128,128,hge->Texture_Load("back.png"), 0.5, 0.5));
	gui->ShowCtrl(19,true);
	gui->EnableCtrl(19,true);
	//***********


	//設置GUI的導航模式、滑鼠指標的圖示以及預設的選取項目。
	gui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	gui->SetCursor(spr);
	gui->SetFocus(1);
	gui->Enter();
	return false;
}
void EquipPanel::CheckItem()
{
	for (int i = 39;i<49;i++)
	{
		switch(i)
		{
		case 39:
			CheckItemList[TANSOUHOU_120MM]=gui->GetCtrl(i)->bVisible;
			break;
		case 40:
			CheckItemList[TANSOUHOU_127MM]=gui->GetCtrl(i)->bVisible;
			break;
		case 41:
			CheckItemList[TANSOUHOU_140MM]=gui->GetCtrl(i)->bVisible;
			break;
		case 42:
			CheckItemList[RENSOUHOU_356MM]=gui->GetCtrl(i)->bVisible;
			break;
		case 43:
			CheckItemList[RENSOUHOU_410MM]=gui->GetCtrl(i)->bVisible;
			break;
		case 44:
			CheckItemList[KOUKAKUHHOU_REN_100MM]=gui->GetCtrl(i)->bVisible;
			break;
		case 45:
			CheckItemList[KOUKAKUHHOU_REN_127MM]=gui->GetCtrl(i)->bVisible;
			break;
		case 46:
			CheckItemList[GYORAI_SANREN_610MM]=gui->GetCtrl(i)->bVisible;
			break;
		case 47:
			CheckItemList[GYORAI_YONREN_610MM]=gui->GetCtrl(i)->bVisible;
			break;
		case 48:
			CheckItemList[PONSHIKIKAN]=gui->GetCtrl(i)->bVisible;
			break;
		}
	}
}
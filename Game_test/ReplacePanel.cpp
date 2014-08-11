#include "ReplacePanel.h"
#include "PanelControler.h"
#include "GfxFont.h"
extern PanelControler controler;

ReplacePanel::ReplacePanel(int id):GUIPanel(id){};

static int lastid=0;
static int nowID=24;
static int j;
static int nowPosition=0;

ReplacePanel::~ReplacePanel()
{
	delete spr;
	delete person;
	delete Bar_Top;
	delete naka_buy;
	delete shimakaze_buy;
	delete kongo_buy;
	delete agano_buy;
	delete tenCM;
}

void ReplacePanel::RenderFucn()
{
	// Render graphics
	//呼叫「hgeGUI::Render」繪製選單
	hge->Gfx_BeginScene();
	hge->Gfx_RenderQuad(&quad);
	Bar_Top->Render(0,65);
	
	/*if (gui->GetCtrl(7)->bVisible)
	{
		person->RenderEx((hge->System_GetState(HGE_SCREENWIDTH)*1.2)/2, 200, 0, 1.0f, 1.0f);
	}*/
	if(lastid == 24 || (nowID == 24))
	{
		naka_buy->RenderEx( (hge->System_GetState(HGE_SCREENWIDTH)*0.22), 250, 0, 1.0f, 1.0f);
	}
	else if(lastid == 25 || (nowID == 25))
	{
		shimakaze_buy->RenderEx( (hge->System_GetState(HGE_SCREENWIDTH)*0.20), 250, 0, 1.0f, 1.0f);
	}
	else if(lastid == 26 || (nowID == 26))
	{
		kongo_buy->RenderEx( (hge->System_GetState(HGE_SCREENWIDTH)*0.20), 250, 0, 1.0f, 1.0f);
	}
	else if(lastid == 27 || (nowID == 27))
	{
		agano_buy->RenderEx( (hge->System_GetState(HGE_SCREENWIDTH)*0.18), 250, 0, 1.0f, 1.0f);
	}
	else {}

	if(gui->GetCtrl(24)->bVisible)
	{
		ChFont->Print(280,680,"#K數值變化：");
	}

	HgeFont->SetColor(0xFF00FF00);	//0xFFFFFFFF 
	HgeFont->printf(5, 5, HGETEXT_LEFT, "dt:%.3f\nFPS:%d", hge->Timer_GetDelta(), hge->Timer_GetFPS());
	ChFont->Print(900,80,"#W金錢：#W%d",10000);
	gui->Render();
	hge->Gfx_EndScene();
}

bool ReplacePanel::FrameFucn()
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
	id=gui->Update(dt);
	if(id == -1)
	{
		switch(lastid)
		{
			//Exit
			case 3: 
				return true;
				break;
			//Return
			case 19:
				controler.SetCurrentPanel(new HomePanel(1));
				return false;
			//更換時的人物選擇按鈕
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
			//更換裝備
			//驅逐: 29 30 28 35 36 37
			//輕巡: 29 30 32 28 31 35 36 37
			//戰艦: 33 34 31 37
			case 28:
				if (nowPosition == 38)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(38);
					gui->AddCtrl(new hgeGUIButton(38, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 200, 64,64,hge->Texture_Load("10cm.png"),0.5,0.5));
					gui->ShowCtrl(38,true);
					gui->EnableCtrl(38,true);
					for(int i=39; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 39)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(39);
					gui->AddCtrl(new hgeGUIButton(39, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 280, 64,64,hge->Texture_Load("10cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 40)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(40);
					gui->AddCtrl(new hgeGUIButton(40, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 360, 64,64,hge->Texture_Load("10cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 41)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(41);
					gui->AddCtrl(new hgeGUIButton(41, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 440, 64,64,hge->Texture_Load("10cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}


				gui->SetFocus(1);
				gui->Enter();
				break;
			case 29:
				if (nowPosition == 38)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(38);
					gui->AddCtrl(new hgeGUIButton(38, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 200, 64,64,hge->Texture_Load("12.7cm.png"),0.5,0.5));
					gui->ShowCtrl(38,true);
					gui->EnableCtrl(38,true);
					for(int i=39; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 39)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(39);
					gui->AddCtrl(new hgeGUIButton(39, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 280, 64,64,hge->Texture_Load("12.7cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 40)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(40);
					gui->AddCtrl(new hgeGUIButton(40, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 360, 64,64,hge->Texture_Load("12.7cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 41)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(41);
					gui->AddCtrl(new hgeGUIButton(41, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 440, 64,64,hge->Texture_Load("12.7cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}


				gui->SetFocus(1);
				gui->Enter();
				break;
			case 30:
				if (nowPosition == 38)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(38);
					gui->AddCtrl(new hgeGUIButton(38, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 200, 64,64,hge->Texture_Load("12cm.png"),0.5,0.5));
					gui->ShowCtrl(38,true);
					gui->EnableCtrl(38,true);
					for(int i=39; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 39)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(39);
					gui->AddCtrl(new hgeGUIButton(39, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 280, 64,64,hge->Texture_Load("12cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 40)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(40);
					gui->AddCtrl(new hgeGUIButton(40, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 360, 64,64,hge->Texture_Load("12cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 41)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(41);
					gui->AddCtrl(new hgeGUIButton(41, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 440, 64,64,hge->Texture_Load("12cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}


				gui->SetFocus(1);
				gui->Enter();
				break;
			case 31:
				if (nowPosition == 38)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(38);
					gui->AddCtrl(new hgeGUIButton(38, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 200, 64,64,hge->Texture_Load("12cm-h.png"),0.5,0.5));
					gui->ShowCtrl(38,true);
					gui->EnableCtrl(38,true);
					for(int i=39; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 39)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(39);
					gui->AddCtrl(new hgeGUIButton(39, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 280, 64,64,hge->Texture_Load("12cm-h.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 40)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(40);
					gui->AddCtrl(new hgeGUIButton(40, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 360, 64,64,hge->Texture_Load("12cm-h.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 41)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(41);
					gui->AddCtrl(new hgeGUIButton(41, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 440, 64,64,hge->Texture_Load("12cm-h.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}


				gui->SetFocus(1);
				gui->Enter();
				break;
			case 32:
				if (nowPosition == 38)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(38);
					gui->AddCtrl(new hgeGUIButton(38, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 200, 64,64,hge->Texture_Load("14cm.png"),0.5,0.5));
					gui->ShowCtrl(38,true);
					gui->EnableCtrl(38,true);
					for(int i=39; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 39)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(39);
					gui->AddCtrl(new hgeGUIButton(39, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 280, 64,64,hge->Texture_Load("14cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 40)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(40);
					gui->AddCtrl(new hgeGUIButton(40, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 360, 64,64,hge->Texture_Load("14cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 41)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(41);
					gui->AddCtrl(new hgeGUIButton(41, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 440, 64,64,hge->Texture_Load("14cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}


				gui->SetFocus(1);
				gui->Enter();
				break;
			case 33:
				if (nowPosition == 38)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(38);
					gui->AddCtrl(new hgeGUIButton(38, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 200, 64,64,hge->Texture_Load("35.6cm.png"),0.5,0.5));
					gui->ShowCtrl(38,true);
					gui->EnableCtrl(38,true);
					for(int i=39; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 39)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(39);
					gui->AddCtrl(new hgeGUIButton(39, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 280, 64,64,hge->Texture_Load("35.6cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 40)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(40);
					gui->AddCtrl(new hgeGUIButton(40, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 360, 64,64,hge->Texture_Load("35.6cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 41)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(41);
					gui->AddCtrl(new hgeGUIButton(41, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 440, 64,64,hge->Texture_Load("35.6cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}


				gui->SetFocus(1);
				gui->Enter();
				break;
			case 34:
				if (nowPosition == 38)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(38);
					gui->AddCtrl(new hgeGUIButton(38, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 200, 64,64,hge->Texture_Load("41cm.png"),0.5,0.5));
					gui->ShowCtrl(38,true);
					gui->EnableCtrl(38,true);
					for(int i=39; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 39)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(39);
					gui->AddCtrl(new hgeGUIButton(39, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 280, 64,64,hge->Texture_Load("41cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 40)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(40);
					gui->AddCtrl(new hgeGUIButton(40, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 360, 64,64,hge->Texture_Load("41cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 41)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(41);
					gui->AddCtrl(new hgeGUIButton(41, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 440, 64,64,hge->Texture_Load("41cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}


				gui->SetFocus(1);
				gui->Enter();
				break;
			case 35:
				if (nowPosition == 38)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(38);
					gui->AddCtrl(new hgeGUIButton(38, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 200, 64,64,hge->Texture_Load("61-3cm.png"),0.5,0.5));
					gui->ShowCtrl(38,true);
					gui->EnableCtrl(38,true);
					for(int i=39; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 39)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(39);
					gui->AddCtrl(new hgeGUIButton(39, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 280, 64,64,hge->Texture_Load("61-3cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 40)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(40);
					gui->AddCtrl(new hgeGUIButton(40, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 360, 64,64,hge->Texture_Load("61-3cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 41)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(41);
					gui->AddCtrl(new hgeGUIButton(41, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 440, 64,64,hge->Texture_Load("61-3cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}


				gui->SetFocus(1);
				gui->Enter();
				break;
			case 36:
				if (nowPosition == 38)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(38);
					gui->AddCtrl(new hgeGUIButton(38, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 200, 64,64,hge->Texture_Load("61-4cm.png"),0.5,0.5));
					gui->ShowCtrl(38,true);
					gui->EnableCtrl(38,true);
					for(int i=39; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 39)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(39);
					gui->AddCtrl(new hgeGUIButton(39, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 280, 64,64,hge->Texture_Load("61-4cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 40)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(40);
					gui->AddCtrl(new hgeGUIButton(40, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 360, 64,64,hge->Texture_Load("61-4cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 41)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(41);
					gui->AddCtrl(new hgeGUIButton(41, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 440, 64,64,hge->Texture_Load("61-4cm.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}


				gui->SetFocus(1);
				gui->Enter();
				break;
			case 37:
				if (nowPosition == 38)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(38);
					gui->AddCtrl(new hgeGUIButton(38, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 200, 64,64,hge->Texture_Load("can.png"),0.5,0.5));
					gui->ShowCtrl(38,true);
					gui->EnableCtrl(38,true);
					for(int i=39; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 39)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(39);
					gui->AddCtrl(new hgeGUIButton(39, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 280, 64,64,hge->Texture_Load("can.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 40)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(40);
					gui->AddCtrl(new hgeGUIButton(40, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 360, 64,64,hge->Texture_Load("can.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}
				if (nowPosition == 41)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->DelCtrl(41);
					gui->AddCtrl(new hgeGUIButton(41, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 440, 64,64,hge->Texture_Load("can.png"),0.5,0.5));
					for(int i=38; i<42; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
				}


				gui->SetFocus(1);
				gui->Enter();
				break;
			//初始4格裝備
			//驅逐: 28 29 30 35 36 37
			//輕巡: 28 29 30 31 32 35 36 37
			//戰艦: 31 33 34 37
			case 38:
				nowPosition = 38;

				//disable
				for(int i=38; i<42; i++)
				{
					gui->ShowCtrl(i,false);
					gui->EnableCtrl(i,false);
				}
				//enable
				if(nowID == 24)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
					gui->ShowCtrl(33,false);
					gui->EnableCtrl(33,false);
					gui->ShowCtrl(34,false);
					gui->EnableCtrl(34,false);
				}
				if(nowID == 25)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
					gui->ShowCtrl(31,false);
					gui->EnableCtrl(31,false);
					gui->ShowCtrl(32,false);
					gui->EnableCtrl(32,false);
					gui->ShowCtrl(33,false);
					gui->EnableCtrl(33,false);
					gui->ShowCtrl(34,false);
					gui->EnableCtrl(34,false);
				}
				//戰艦: 31 33 34 37
				if(nowID == 26)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->ShowCtrl(31,true);
					gui->EnableCtrl(31,true);
					gui->ShowCtrl(33,true);
					gui->EnableCtrl(33,true);
					gui->ShowCtrl(34,true);
					gui->EnableCtrl(34,true);
					gui->ShowCtrl(37,true);
					gui->EnableCtrl(37,true);
				}
				if(nowID == 27)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
					gui->ShowCtrl(33,false);
					gui->EnableCtrl(33,false);
					gui->ShowCtrl(34,false);
					gui->EnableCtrl(34,false);
				}


				gui->SetFocus(1);
				gui->Enter();
				break;
			case 39:
				nowPosition = 39;
				//disable
				for(int i=38; i<42; i++)
				{
					gui->ShowCtrl(i,false);
					gui->EnableCtrl(i,false);
				}
				//enable
				if(nowID == 24)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
					gui->ShowCtrl(33,false);
					gui->EnableCtrl(33,false);
					gui->ShowCtrl(34,false);
					gui->EnableCtrl(34,false);
				}
				if(nowID == 25)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
					gui->ShowCtrl(31,false);
					gui->EnableCtrl(31,false);
					gui->ShowCtrl(32,false);
					gui->EnableCtrl(32,false);
					gui->ShowCtrl(33,false);
					gui->EnableCtrl(33,false);
					gui->ShowCtrl(34,false);
					gui->EnableCtrl(34,false);
				}
				//戰艦: 31 33 34 37
				if(nowID == 26)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->ShowCtrl(31,true);
					gui->EnableCtrl(31,true);
					gui->ShowCtrl(33,true);
					gui->EnableCtrl(33,true);
					gui->ShowCtrl(34,true);
					gui->EnableCtrl(34,true);
					gui->ShowCtrl(37,true);
					gui->EnableCtrl(37,true);
				}
				if(nowID == 27)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
					gui->ShowCtrl(33,false);
					gui->EnableCtrl(33,false);
					gui->ShowCtrl(34,false);
					gui->EnableCtrl(34,false);
				}


				gui->SetFocus(1);
				gui->Enter();
				break;
			case 40:
				nowPosition = 40;
				//disable
				for(int i=38; i<42; i++)
				{
					gui->ShowCtrl(i,false);
					gui->EnableCtrl(i,false);
				}
				//enable
				if(nowID == 24)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
					gui->ShowCtrl(33,false);
					gui->EnableCtrl(33,false);
					gui->ShowCtrl(34,false);
					gui->EnableCtrl(34,false);
				}
				if(nowID == 25)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
					gui->ShowCtrl(31,false);
					gui->EnableCtrl(31,false);
					gui->ShowCtrl(32,false);
					gui->EnableCtrl(32,false);
					gui->ShowCtrl(33,false);
					gui->EnableCtrl(33,false);
					gui->ShowCtrl(34,false);
					gui->EnableCtrl(34,false);
				}
				//戰艦: 31 33 34 37
				if(nowID == 26)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->ShowCtrl(31,true);
					gui->EnableCtrl(31,true);
					gui->ShowCtrl(33,true);
					gui->EnableCtrl(33,true);
					gui->ShowCtrl(34,true);
					gui->EnableCtrl(34,true);
					gui->ShowCtrl(37,true);
					gui->EnableCtrl(37,true);
				}
				if(nowID == 27)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
					gui->ShowCtrl(33,false);
					gui->EnableCtrl(33,false);
					gui->ShowCtrl(34,false);
					gui->EnableCtrl(34,false);
				}


				gui->SetFocus(1);
				gui->Enter();
				break;
			case 41:
				nowPosition = 41;
				//disable
				for(int i=38; i<42; i++)
				{
					gui->ShowCtrl(i,false);
					gui->EnableCtrl(i,false);
				}
				//enable
				if(nowID == 24)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
					gui->ShowCtrl(33,false);
					gui->EnableCtrl(33,false);
					gui->ShowCtrl(34,false);
					gui->EnableCtrl(34,false);
				}
				if(nowID == 25)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
					gui->ShowCtrl(31,false);
					gui->EnableCtrl(31,false);
					gui->ShowCtrl(32,false);
					gui->EnableCtrl(32,false);
					gui->ShowCtrl(33,false);
					gui->EnableCtrl(33,false);
					gui->ShowCtrl(34,false);
					gui->EnableCtrl(34,false);
				}
				//戰艦: 31 33 34 37
				if(nowID == 26)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,false);
						gui->EnableCtrl(i,false);
					}
					gui->ShowCtrl(31,true);
					gui->EnableCtrl(31,true);
					gui->ShowCtrl(33,true);
					gui->EnableCtrl(33,true);
					gui->ShowCtrl(34,true);
					gui->EnableCtrl(34,true);
					gui->ShowCtrl(37,true);
					gui->EnableCtrl(37,true);
				}
				if(nowID == 27)
				{
					for(int i=28; i<38; i++)
					{
						gui->ShowCtrl(i,true);
						gui->EnableCtrl(i,true);
					}
					gui->ShowCtrl(33,false);
					gui->EnableCtrl(33,false);
					gui->ShowCtrl(34,false);
					gui->EnableCtrl(34,false);
				}


				gui->SetFocus(1);
				gui->Enter();
				break;
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

bool ReplacePanel::FreeFucn()
{
	// Delete created objects and free loaded resources
	//關閉程式時，釋放GUI和資源
	delete spr;
	hge->Effect_Free(snd);
	hge->Texture_Free(tex);
	hge->Texture_Free(quad.tex);
	return false;
}

bool ReplacePanel::InitResource()
{
	// Load sound and textures
	quad.tex=hge->Texture_Load("sea3.png");
	tex=hge->Texture_Load("cursor.png");
	//person = new hgeSprite(hge->Texture_Load("landwind.png"),0.832,0.5859,426,600);
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

	//*************

	//更換
	gui->AddCtrl(new hgeGUIButton(24, (hge->System_GetState(HGE_SCREENWIDTH)*0.16),170,64,64,hge->Texture_Load("number1.png"),0.5,0.5));
	gui->ShowCtrl(24,true);
	gui->EnableCtrl(24,true);
	gui->AddCtrl(new hgeGUIButton(25, (hge->System_GetState(HGE_SCREENWIDTH)*0.24),170,64,64,hge->Texture_Load("number2.png"),0.5,0.5));
	gui->ShowCtrl(25,true);
	gui->EnableCtrl(25,true);
	gui->AddCtrl(new hgeGUIButton(26, (hge->System_GetState(HGE_SCREENWIDTH)*0.32),170,64,64,hge->Texture_Load("number3.png"),0.5,0.5));
	gui->ShowCtrl(26,true);
	gui->EnableCtrl(26,true);
	gui->AddCtrl(new hgeGUIButton(27, (hge->System_GetState(HGE_SCREENWIDTH)*0.40),170,64,64,hge->Texture_Load("number4.png"),0.5,0.5));
	gui->ShowCtrl(27,true);
	gui->EnableCtrl(27,true);

	//Equipment
	//驅逐: 29 30 28 35 36 37
	//輕巡: 29 30 32 28 31 35 36 37
	//戰艦: 33 34 31 37
	gui->AddCtrl(new hgeGUIButton(28, (hge->System_GetState(HGE_SCREENWIDTH)*0.6),200,64,64,hge->Texture_Load("10cm.png"),0.5,0.5));
	gui->ShowCtrl(28,false);
	gui->EnableCtrl(28,false);
	gui->AddCtrl(new hgeGUIButton(29, (hge->System_GetState(HGE_SCREENWIDTH)*0.6),250,64,64,hge->Texture_Load("12.7cm.png"),0.5,0.5));
	gui->ShowCtrl(29,false);
	gui->EnableCtrl(29,false);
	gui->AddCtrl(new hgeGUIButton(30, (hge->System_GetState(HGE_SCREENWIDTH)*0.6),300,64,64,hge->Texture_Load("12cm.png"),0.5,0.5));
	gui->ShowCtrl(30,false);
	gui->EnableCtrl(30,false);
	gui->AddCtrl(new hgeGUIButton(31, (hge->System_GetState(HGE_SCREENWIDTH)*0.6),350,64,64,hge->Texture_Load("12cm-h.png"),0.5,0.5));
	gui->ShowCtrl(31,false);
	gui->EnableCtrl(31,false);
	gui->AddCtrl(new hgeGUIButton(32, (hge->System_GetState(HGE_SCREENWIDTH)*0.6),400,64,64,hge->Texture_Load("14cm.png"),0.5,0.5));
	gui->ShowCtrl(32,false);
	gui->EnableCtrl(32,false);
	gui->AddCtrl(new hgeGUIButton(33, (hge->System_GetState(HGE_SCREENWIDTH)*0.6),450,64,64,hge->Texture_Load("35.6cm.png"),0.5,0.5));
	gui->ShowCtrl(33,false);
	gui->EnableCtrl(33,false);
	gui->AddCtrl(new hgeGUIButton(34, (hge->System_GetState(HGE_SCREENWIDTH)*0.6),500,64,64,hge->Texture_Load("41cm.png"),0.5,0.5));
	gui->ShowCtrl(34,false);
	gui->EnableCtrl(34,false);
	gui->AddCtrl(new hgeGUIButton(35, (hge->System_GetState(HGE_SCREENWIDTH)*0.6),550,64,64,hge->Texture_Load("61-3cm.png"),0.5,0.5));
	gui->ShowCtrl(35,false);
	gui->EnableCtrl(35,false);
	gui->AddCtrl(new hgeGUIButton(36, (hge->System_GetState(HGE_SCREENWIDTH)*0.6),600,64,64,hge->Texture_Load("61-4cm.png"),0.5,0.5));
	gui->ShowCtrl(36,false);
	gui->EnableCtrl(36,false);
	gui->AddCtrl(new hgeGUIButton(37, (hge->System_GetState(HGE_SCREENWIDTH)*0.6),650,64,64,hge->Texture_Load("can.png"),0.5,0.5));
	gui->ShowCtrl(37,false);
	gui->EnableCtrl(37,false);

	//初始4格裝備
	for(int i=38; i<42; i++)
	{
		gui->AddCtrl(new hgeGUIButton(i, (hge->System_GetState(HGE_SCREENWIDTH)*0.6), 200+(i-38)*80, 64,64,hge->Texture_Load("can.png"),0.5,0.5));
		gui->ShowCtrl(i,true);
		gui->EnableCtrl(i,true);
	}

	
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
}

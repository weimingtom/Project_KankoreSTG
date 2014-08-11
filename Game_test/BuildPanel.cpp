#include "BuildPanel.h"
#include "PanelControler.h"
extern PanelControler controler;

BuildPanel::BuildPanel(int id):GUIPanel(id){};

static int lastid=0;

BuildPanel::~BuildPanel()
{
	delete spr;
	delete person;
	delete Bar_Top;
	delete naka_buy;
	delete shimakaze_buy;
	delete kongo_buy;
	delete agano_buy;
}
void BuildPanel::RenderFucn()
{
	// Render graphics
	//呼叫「hgeGUI::Render」繪製選單
	hge->Gfx_BeginScene();
	hge->Gfx_RenderQuad(&quad);
	Bar_Top->Render(0,65);
	
	/*if (gui->GetCtrl(7)->bVisible)
		person->RenderEx((hge->System_GetState(HGE_SCREENWIDTH)*1.2)/2, 200, 0, 1.0f, 1.0f);*/
	if(gui->GetCtrl(20)->bVisible)
	{
		naka_buy->RenderEx( (hge->System_GetState(HGE_SCREENWIDTH)*0.02), 170, 0, 1.0f, 1.0f);
		shimakaze_buy->RenderEx( (hge->System_GetState(HGE_SCREENWIDTH)*0.24), 170, 0, 1.0f, 1.0f);
		kongo_buy->RenderEx( (hge->System_GetState(HGE_SCREENWIDTH)*0.48), 170, 0, 1.0f, 1.0f);
		agano_buy->RenderEx( (hge->System_GetState(HGE_SCREENWIDTH)*0.72), 170, 0, 1.0f, 1.0f);
	}

	HgeFont->SetColor(0xFF00FF00);	//0xFFFFFFFF 
	HgeFont->printf(5, 5, HGETEXT_LEFT, "dt:%.3f\nFPS:%d", hge->Timer_GetDelta(), hge->Timer_GetFPS());
	ChFont->Print(900,80,"#W金錢：#W%d",controler.GetAdmiral()->getMoney());
	gui->Render();
	if (!gui->GetCtrl(49)->bEnabled)
	{
		if (SaleoutFlag[0])
			if (controler.GetAdmiral()->getMoney()>=1000)
				ChFont->Print(100,300,"#RＳＡＬＥ\n ＯＵＴ");
			else
				ChFont->Print(100,300,"#R　 ＮＯ\nＭＯＮＥＹ");
		if (SaleoutFlag[1])
			if (controler.GetAdmiral()->getMoney()>=20000)
				ChFont->Print(360,300,"#RＳＡＬＥ\n ＯＵＴ");
			else
				ChFont->Print(360,300,"#R　 ＮＯ\nＭＯＮＥＹ");
		if (SaleoutFlag[2])
			if (controler.GetAdmiral()->getMoney()>=10000)
				ChFont->Print(650,300,"#RＳＡＬＥ\n ＯＵＴ");
			else
				ChFont->Print(650,300,"#R　 ＮＯ\nＭＯＮＥＹ");
		if (SaleoutFlag[3])
			if (controler.GetAdmiral()->getMoney()>=5000)
				ChFont->Print(1000,300,"#RＳＡＬＥ\n ＯＵＴ");
			else
				ChFont->Print(1000,300,"#R　 ＮＯ\nＭＯＮＥＹ");
	}
	hge->Gfx_EndScene();
}

bool BuildPanel::FrameFucn()
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
			//建造
			case 6:	
				//buy button
				gui->ShowCtrl(20,true);
				gui->EnableCtrl(20,true);
				gui->ShowCtrl(21,true);
				gui->EnableCtrl(21,true);
				gui->ShowCtrl(22,true);
				gui->EnableCtrl(22,true);
				gui->ShowCtrl(23,true);
				gui->EnableCtrl(23,true);

				//back
				gui->ShowCtrl(19,true);
				gui->EnableCtrl(19,true);

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 19:
				controler.SetCurrentPanel(new HomePanel(2));
				return false;
			//buy
			case 20:
				for(int i=20; i<24; i++)
				{
					gui->ShowCtrl(i,false);
					gui->EnableCtrl(i,false);
				}
				gui->ShowCtrl(19,false);
				gui->EnableCtrl(19,false);

				//Yes No button(確認是否購買)
				gui->ShowCtrl(49,true);
				gui->EnableCtrl(49,true);
				gui->ShowCtrl(50,true);
				gui->EnableCtrl(50,true);
				TargetToBuy = 0;

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 21:
				for(int i=20; i<24; i++)
				{
					gui->ShowCtrl(i,false);
					gui->EnableCtrl(i,false);
				}
				gui->ShowCtrl(19,false);
				gui->EnableCtrl(19,false);

				//Yes No button(確認是否購買)
				gui->ShowCtrl(49,true);
				gui->EnableCtrl(49,true);
				gui->ShowCtrl(50,true);
				gui->EnableCtrl(50,true);
				TargetToBuy = 1;

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 22:
				for(int i=20; i<24; i++)
				{
					gui->ShowCtrl(i,false);
					gui->EnableCtrl(i,false);
				}
				gui->ShowCtrl(19,false);
				gui->EnableCtrl(19,false);

				//Yes No button(確認是否購買)
				gui->ShowCtrl(49,true);
				gui->EnableCtrl(49,true);
				gui->ShowCtrl(50,true);
				gui->EnableCtrl(50,true);
				TargetToBuy = 2;

				gui->SetFocus(1);
				gui->Enter();
				break;
			case 23:
				for(int i=20; i<24; i++)
				{
					gui->ShowCtrl(i,false);
					gui->EnableCtrl(i,false);
				}
				gui->ShowCtrl(19,false);
				gui->EnableCtrl(19,false);

				//Yes No button(確認是否購買)
				gui->ShowCtrl(49,true);
				gui->EnableCtrl(49,true);
				gui->ShowCtrl(50,true);
				gui->EnableCtrl(50,true);
				TargetToBuy = 3;

				gui->SetFocus(1);
				gui->Enter();
				break;
			//Yes No button(確認是否購買)
			case 49:
				if(TargetToBuy == 0)
				{
					controler.GetAdmiral()->getShip(TargetToSet)->setShipType(_NAKA);
					controler.GetAdmiral()->setMoney(controler.GetAdmiral()->getMoney()-1000);
				}
				else if(TargetToBuy == 1)
				{
					controler.GetAdmiral()->getShip(TargetToSet)->setShipType(_SHIMAKAZE);
				}
				else if(TargetToBuy == 2)
				{
					controler.GetAdmiral()->getShip(TargetToSet)->setShipType(_KONGOU);
					controler.GetAdmiral()->setMoney(controler.GetAdmiral()->getMoney()-10000);
					//printf("%d",controler.GetAdmiral()->getShip(TargetToBuy)->getShipType());
				}
				else if(TargetToBuy == 3)
				{
					controler.GetAdmiral()->getShip(TargetToSet)->setShipType(_AGANO);
					controler.GetAdmiral()->setMoney(controler.GetAdmiral()->getMoney()-5000);
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

bool BuildPanel::FreeFucn()
{
	// Delete created objects and free loaded resources
	//關閉程式時，釋放GUI和資源
	delete spr;
	hge->Effect_Free(snd);
	hge->Texture_Free(tex);
	hge->Texture_Free(quad.tex);
	return false;
}

bool BuildPanel::InitResource()
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

	//建造
	gui->AddCtrl(new hgeGUIButton(20,(hge->System_GetState(HGE_SCREENWIDTH)*0.02),650,236,89,hge->Texture_Load("buy.png"),0.92,0.695));
	gui->ShowCtrl(20,true);
	gui->EnableCtrl(20,true);
	gui->AddCtrl(new hgeGUIButton(21, (hge->System_GetState(HGE_SCREENWIDTH)*0.28),650,236,89,hge->Texture_Load("buy.png"),0.92,0.695));
	gui->ShowCtrl(21,true);
	gui->EnableCtrl(21,true);
	gui->AddCtrl(new hgeGUIButton(22, (hge->System_GetState(HGE_SCREENWIDTH)*0.48),650,236,89,hge->Texture_Load("buy.png"),0.92,0.695));
	gui->ShowCtrl(22,true);
	gui->EnableCtrl(22,true);
	gui->AddCtrl(new hgeGUIButton(23, (hge->System_GetState(HGE_SCREENWIDTH)*0.76),650,236,89,hge->Texture_Load("buy.png"),0.92,0.695));
	gui->ShowCtrl(23,true);
	gui->EnableCtrl(23,true);
	//*************

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
	SaleoutFlag[0]=false;
	SaleoutFlag[1]=false;
	SaleoutFlag[2]=false;
	SaleoutFlag[3]=false;
	for (int i = 0;i<4;i++)
	{
		shiptype STP = controler.GetAdmiral()->getShip(i)->getShipType();
		if (STP == _NAKA || controler.GetAdmiral()->getMoney()<1000)
		{
			gui->EnableCtrl(20,false);
			SaleoutFlag[0] = true;
		}
		if (STP == _SHIMAKAZE || controler.GetAdmiral()->getMoney()<20000)
		{
			gui->EnableCtrl(21,false);
			SaleoutFlag[1] = true;
		}
		if (STP == _KONGOU || controler.GetAdmiral()->getMoney()<10000)
		{
			gui->EnableCtrl(22,false);
			SaleoutFlag[2] = true;
		}
		if (STP == _AGANO || controler.GetAdmiral()->getMoney()<5000)
		{
			gui->EnableCtrl(23,false);
			SaleoutFlag[3] = true;
		}
		if (STP == _NOSHIP)
		{
			TargetToSet = i;
			break;
		}
	}
	return false;
}
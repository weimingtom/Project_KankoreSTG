#include "startPanel.h"

extern PanelControler controler;

startPanel::startPanel(int id) : GUIPanel(id) {;}

void startPanel::RenderFucn()
{
	// Render graphics
	//呼叫「hgeGUI::Render」繪製選單
	hge->Gfx_BeginScene();
	hge->Gfx_RenderQuad(&quad);
	gui->Render();
	logo->RenderEx((hge->System_GetState(HGE_SCREENWIDTH)-381*1.2)/2,100,0,1.2f,1.2f);
	HgeFont->SetColor(ARGB(255,255,255,255));	//0xFFFFFFFF 
	//HgeFont->printf(5, 5, HGETEXT_LEFT, "dt:%.3f\nFPS:%d", hge->Timer_GetDelta(), hge->Timer_GetFPS());
	if (inputFlag)
	{
		typeFont->SetColor(ARGB(255,255,255,255));
		typeFont->printf(hge->System_GetState(HGE_SCREENWIDTH)/2, 600, HGETEXT_CENTER, "Please Enter Your Name :\n\n  %s", input_Name);
		if (controler.GetAdmiral()->getGender())
			typeFont->printf(hge->System_GetState(HGE_SCREENWIDTH)/2, 750, HGETEXT_CENTER, "Enter Left or Right to change gender: \n\n%s", "Male");
		else
			typeFont->printf(hge->System_GetState(HGE_SCREENWIDTH)/2, 750, HGETEXT_CENTER, "Enter Left or Right to change gender: \n\n%s", "Female");
	}
	
	hge->Gfx_EndScene();
}

bool startPanel::FrameFucn()
{
	float dt=hge->Timer_GetDelta();
	static float t=0.0f;
	float tx,ty;
	int id;
	static int lastid=0;

	// If ESCAPE was pressed, tell the GUI to finish
	if(hge->Input_GetKeyState(HGEK_ESCAPE)) { lastid=5; gui->Leave();return 1; }
		
	// We update the GUI and take an action if
	// one of the menu items was selected
	id=gui->Update(dt);
	if(id == -1)
	{
		if (!inputFlag)
		{
			switch(lastid)
			{
				case 1:		//Play
					gui->EnableCtrl(1,false);
					gui->EnableCtrl(2,false);
					gui->EnableCtrl(3,false);
					if (!controler.GetAdmiral()->Loading("D:\\HGE\\Game_test\\Debug\\savedata\\savedata.sav"))
					{
						/*controler.GetAdmiral()->setName("Laim");
						controler.GetAdmiral()->setGender(true);
						controler.GetAdmiral()->Saving();*/
						inputFlag = true;
					}
					else
					{
						controler.SetCurrentPanel(new HomePanel(2));
					}
					//gui->SetFocus(1);
					//gui->Enter();
					return false;
				case 2:
					gui->SetFocus(1);
					gui->Enter();
					break;
				case 3: 
					return true;
					break;
				case 6:
					gui->SetFocus(1);
					gui->Enter();
					break;
			}
		}
		else
		{
			if (!(hge->Input_KeyDown(HGEK_BACKSPACE)))
			{
				if (count<15)
				{
					input_Name[count]=(char)hge->Input_GetChar();
					if (!input_Name[count]=='\0')
					{
						count++;
					}
				}
			}
			else if (count!=0)
			{
				input_Name[count]='\0';
				count--;
			}
			//是男的且按右會變女的，是女的按左會變男的
			if (controler.GetAdmiral()->getGender() && hge->Input_KeyDown(HGEK_LEFT) || (!controler.GetAdmiral()->getGender() && hge->Input_KeyDown(HGEK_RIGHT)))
				controler.GetAdmiral()->setGender(!controler.GetAdmiral()->getGender());
			//按ENTER就確定資訊並存檔，接著切換頁面
			if (hge->Input_KeyDown(HGEK_ENTER) && input_Name[0]!='\0')
			{
				controler.GetAdmiral()->setName(input_Name);
				controler.GetAdmiral()->setGender(true);
				controler.GetAdmiral()->Saving();
				controler.SetCurrentPanel(new HomePanel(2));
				return false;
			}
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

bool startPanel::FreeFucn()
{
	// Delete created objects and free loaded resources
	//關閉程式時，釋放GUI和資源
	delete spr;
	hge->Effect_Free(snd);
	hge->Texture_Free(tex);
	hge->Texture_Free(quad.tex);
	return false;
}

bool startPanel::InitResource()
{
	
	//設置TYPING字體
	inputFlag = false;
	count = 0;
	for (int i =0 ;i < 16 ; i++)
		input_Name[i] = '\0';
	typeFont = new hgeFont("font1.fnt");
	typeFont->SetColor(ARGB(255,255,255,255));
	typeFont->SetScale(1.5f);

	// Load sound and textures
	quad.tex=hge->Texture_Load("bg.png");
	tex=hge->Texture_Load("cursor.png");
	logo = new hgeSprite(hge->Texture_Load("kankore_logo.png"),0.744,0.744,381,381);
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
	//gui=new hgeGUI();

	gui->AddCtrl(new hgeGUIMenuItem(1,HgeFont,snd,hge->System_GetState(HGE_SCREENWIDTH)/2,600,0.0f,"Start Game"));
	gui->AddCtrl(new hgeGUIMenuItem(2,HgeFont,snd,hge->System_GetState(HGE_SCREENWIDTH)/2,680,0.1f,"Options"));
	gui->AddCtrl(new hgeGUIMenuItem(3,HgeFont,snd,hge->System_GetState(HGE_SCREENWIDTH)/2,760,0.2f,"Exit"));
	//設置GUI的導航模式、滑鼠指標的圖示以及預設的選取項目。
	gui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	gui->SetCursor(spr);
	gui->SetFocus(1);
	gui->Enter();
	return false;
}
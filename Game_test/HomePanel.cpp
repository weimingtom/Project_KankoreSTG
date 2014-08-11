#include "HomePanel.h"
#include "PanelControler.h"
extern PanelControler controler;


HomePanel::HomePanel(int id) : GUIPanel(id){;}
int HomePanel::lastid = 0;

void HomePanel::RenderFucn()
{
	// Render graphics
	//©I¥s¡uhgeGUI::Render¡vÃ¸»s¿ï³æ
	hge->Gfx_BeginScene();
	hge->Gfx_RenderQuad(&quad);
	Bar_Top->Render(0,65);
	
	if (gui->GetCtrl(7)->bVisible)
		person->RenderEx((hge->System_GetState(HGE_SCREENWIDTH)*1.2)/2,200,0,1.0f,1.0f);

	ChFont->Print(100,80,"#W%s",HalfToFullconverter(controler.GetAdmiral()->getName()));
	ChFont->Print(900,80,"#Wª÷¿ú¡G#W%d",controler.GetAdmiral()->getMoney());
	gui->Render();
	hge->Gfx_EndScene();
}

bool HomePanel::FrameFucn()
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

			case 6:	
				controler.SetCurrentPanel(new BuildPanel(6));
				return false;
			case 7:		//¥XÀ»
				//gui->ShowCtrl(3,false);
				//gui->EnableCtrl(3,false);
				gui->ShowCtrl(6,false);
				gui->EnableCtrl(6,false);
				gui->ShowCtrl(7,false);
				gui->EnableCtrl(7,false);
				gui->ShowCtrl(8,false);
				gui->EnableCtrl(8,false);
				gui->ShowCtrl(9,false);
				gui->EnableCtrl(9,false);
				gui->ShowCtrl(11,true);
				gui->ShowCtrl(12,true);
				gui->ShowCtrl(13,true);
				gui->ShowCtrl(14,true);
				CheckShipEnable();
				gui->SetFocus(1);
				gui->Enter();
				break;
			case 8:
				controler.SetCurrentPanel(new ReplacePanel(8));
				return false;
			case 9:
				controler.SetCurrentPanel(new EquipPanel(9));
				return false;
			//Choose Fleet
			case 11:
				gui->ShowCtrl(11,false);
				gui->EnableCtrl(11,false);
				gui->ShowCtrl(12,false);
				gui->EnableCtrl(12,false);
				gui->ShowCtrl(13,false);
				gui->EnableCtrl(13,false);
				gui->ShowCtrl(14,false);
				gui->EnableCtrl(14,false);
				gui->ShowCtrl(16,true);
				gui->EnableCtrl(16,true);
				gui->ShowCtrl(17,true);
				gui->EnableCtrl(17,true);
				gui->ShowCtrl(19,true);
				gui->EnableCtrl(19,true);


				gui->SetFocus(1);
				gui->Enter();
				break;
			case 12:
				gui->ShowCtrl(11,false);
				gui->EnableCtrl(11,false);
				gui->ShowCtrl(12,false);
				gui->EnableCtrl(12,false);
				gui->ShowCtrl(13,false);
				gui->EnableCtrl(13,false);
				gui->ShowCtrl(14,false);
				gui->EnableCtrl(14,false);
				gui->ShowCtrl(16,true);
				gui->EnableCtrl(16,true);
				gui->ShowCtrl(17,true);
				gui->EnableCtrl(17,true);
				gui->ShowCtrl(19,true);
				gui->EnableCtrl(19,true);


				gui->SetFocus(1);
				gui->Enter();
				break;
			case 13:
				gui->ShowCtrl(11,false);
				gui->EnableCtrl(11,false);
				gui->ShowCtrl(12,false);
				gui->EnableCtrl(12,false);
				gui->ShowCtrl(13,false);
				gui->EnableCtrl(13,false);
				gui->ShowCtrl(14,false);
				gui->EnableCtrl(14,false);
				gui->ShowCtrl(16,true);
				gui->EnableCtrl(16,true);
				gui->ShowCtrl(17,true);
				gui->EnableCtrl(17,true);
				gui->ShowCtrl(19,true);
				gui->EnableCtrl(19,true);


				gui->SetFocus(1);
				gui->Enter();
				break;
			case 14:
				gui->ShowCtrl(11,false);
				gui->EnableCtrl(11,false);
				gui->ShowCtrl(12,false);
				gui->EnableCtrl(12,false);
				gui->ShowCtrl(13,false);
				gui->EnableCtrl(13,false);
				gui->ShowCtrl(14,false);
				gui->EnableCtrl(14,false);
				gui->ShowCtrl(16,true);
				gui->EnableCtrl(16,true);
				gui->ShowCtrl(17,true);
				gui->EnableCtrl(17,true);
				gui->ShowCtrl(19,true);
				gui->EnableCtrl(19,true);


				gui->SetFocus(1);
				gui->Enter();
				break;
			//Choose Map
			case 16:
				controler.SetCurrentPanel(new GamePanel(3));
				return false;
			case 17:
				controler.SetCurrentPanel(new GamePanel(3));
				return false;
			//Return
			case 19:
				gui->ShowCtrl(16,false);
				gui->EnableCtrl(16,false);
				gui->ShowCtrl(17,false);
				gui->EnableCtrl(17,false);
				gui->ShowCtrl(19,false);
				gui->EnableCtrl(19,false);
				//«Ø³y
				gui->ShowCtrl(6,true);
				gui->EnableCtrl(6,true);
				//¥XÀ»
				gui->ShowCtrl(7,true);
				gui->EnableCtrl(7,true);
				//§ó´«
				gui->ShowCtrl(8,true);
				gui->EnableCtrl(8,true);
				//ÁÊ¶R
				gui->ShowCtrl(9,true);
				gui->EnableCtrl(9,true);
				//Â÷¶}
				//gui->ShowCtrl(3,true);
				//gui->EnableCtrl(3,true);

				gui->SetFocus(1);
				gui->Enter();
				break;
		}
	}
	else if(id) { 
		lastid=id; 
		gui->Leave(); 
	}


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

bool HomePanel::FreeFucn()
{
	// Delete created objects and free loaded resources
	//Ãö³¬µ{¦¡®É¡AÄÀ©ñGUI©M¸ê·½
	delete spr;
	hge->Effect_Free(snd);
	hge->Texture_Free(tex);
	hge->Texture_Free(quad.tex);
	return false;
}

bool HomePanel::InitResource()
{
	// Load sound and textures
	quad.tex=hge->Texture_Load("sea3.png");
	tex=hge->Texture_Load("cursor.png");
	person = new hgeSprite(hge->Texture_Load("landwind.png"),0.832,0.5859,426,600);
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
		quad.v[i].col=0xFFFFFFFF;	//0xFFFFFFFF	³o´N¬O­I´ºÃC¦â!!!
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
	//²£¥ÍGUI¨Ã¥[¤J¿ï³æ¶µ¥Ø¶i¥h¡C
	//Top Bar
	Bar_Top =  new hgeSprite (0,0,0,hge->System_GetState(HGE_SCREENWIDTH),70);
	Bar_Top->SetColor(ARGB(255,48,46,42),0);
	Bar_Top->SetColor(ARGB(200,48,46,42),1);
	Bar_Top->SetColor(ARGB(255,48,46,42),2);
	Bar_Top->SetColor(ARGB(200,48,46,42),3);

	//gui->AddCtrl(new hgeGUIMenuItem(1,HgeFont,snd,hge->System_GetState(HGE_SCREENWIDTH)/2,600,0.0f,"Start Game"));
	TEX_BUTTON = hge->Texture_Load("kankore_logo.png");
	//«Ø³y
	gui->AddCtrl(new hgeGUIButton(6,250,200,220,220,hge->Texture_Load("BUTTON_1CP1.png"),0.43,0.86));
	//¥XÀ»
	gui->AddCtrl(new hgeGUIButton(7,250,600,220,220,hge->Texture_Load("BUTTON_2CP1.png"),0.43,0.86));
	//§ó´«
	gui->AddCtrl(new hgeGUIButton(8,80,400,220,220,hge->Texture_Load("BUTTON_3CP1.png"),0.43,0.86));
	//ÁÊ¶R
	gui->AddCtrl(new hgeGUIButton(9,430,400,220,220,hge->Texture_Load("BUTTON_4CP1.png"),0.43,0.86));
	//Â÷¶}
	//gui->AddCtrl(new hgeGUIMenuItem(3,HgeFont,snd,hge->System_GetState(HGE_SCREENWIDTH)*0.85,850,0.0f,"Exit"));

	//¥XÀ»
	gui->AddCtrl(new hgeGUIButton(11,(hge->System_GetState(HGE_SCREENWIDTH)*0.77),300,218,300,hge->Texture_Load("Naka2.png"),0.85,0.5859));
	gui->ShowCtrl(11,false);
	gui->EnableCtrl(11,false);
	gui->AddCtrl(new hgeGUIButton(12,(hge->System_GetState(HGE_SCREENWIDTH)*0.52),300,218,300,hge->Texture_Load("Shimakaze2.png"),0.85,0.5859));
	gui->ShowCtrl(12,false);
	gui->EnableCtrl(12,false);
	gui->AddCtrl(new hgeGUIButton(13,(hge->System_GetState(HGE_SCREENWIDTH)*0.27),300,221,302,hge->Texture_Load("Kongou2.png"),0.863,0.59));
	gui->ShowCtrl(13,false);
	gui->EnableCtrl(13,false);
	gui->AddCtrl(new hgeGUIButton(14,(hge->System_GetState(HGE_SCREENWIDTH)*0.02),300,218,300,hge->Texture_Load("agano3.png"),0.85,0.5859));
	gui->ShowCtrl(14,false);
	gui->EnableCtrl(14,false);
	//*************

	//Map
	gui->AddCtrl(new hgeGUIButton(16,(hge->System_GetState(HGE_SCREENWIDTH)*0.24),250,750,207,hge->Texture_Load("map.png"),0.73,0.404));
	gui->ShowCtrl(16,false);
	gui->EnableCtrl(16,false);
	gui->AddCtrl(new hgeGUIButton(17,(hge->System_GetState(HGE_SCREENWIDTH)*0.24),570,750,372,hge->Texture_Load("map2.png"),0.73,0.43));
	gui->ShowCtrl(17,false);
	gui->EnableCtrl(17,false);
	//************
	
	//Back
	gui->AddCtrl(new hgeGUIButton(19,(hge->System_GetState(HGE_SCREENWIDTH)*0.86),800,128,128,hge->Texture_Load("back.png"), 0.5, 0.5));
	gui->ShowCtrl(19,false);
	gui->EnableCtrl(19,false);
	//***********
	//hgeGUIListbox¬O¤@ƒª¥Î¤_¦Cªí®ØGUI±±¥ó
	/*hgeGUIListbox *List = new hgeGUIListbox(10,50,100,800,100,HgeFont,ARGB(255,255,255,255),ARGB(255,192,192,192),ARGB(255,192,192,192));
	List->AddItem("`");
	gui->AddCtrl(List);*/

	//³]¸mGUIªº¾É¯è¼Ò¦¡¡B·Æ¹««ü¼Ðªº¹Ï¥Ü¥H¤Î¹w³]ªº¿ï¨ú¶µ¥Ø¡C
	gui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	gui->SetCursor(spr);
	gui->SetFocus(1);
	gui->Enter();
	return false;
}
void HomePanel::CheckShipEnable()
{
	for (int i = 0 ; i<4 ; i++)
	{
		shiptype STP = controler.GetAdmiral()->getShip(i)->getShipType();
		if (STP == _NAKA)
		{
			gui->EnableCtrl(14,true);
		}
		if (STP == _SHIMAKAZE)
		{
			gui->EnableCtrl(12,true);
		}
		if (STP == _KONGOU )
		{
			gui->EnableCtrl(13,true);
		}
		if (STP == _AGANO)
		{
			gui->EnableCtrl(11,true);
		}
		if (STP == _NOSHIP)
		{
			break;
		}
	}
}
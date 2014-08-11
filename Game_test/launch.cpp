/*
** Haaf's Game Engine 1.8
** Copyright (C) 2003-2007, Relish Games
** hge.relishgames.com
**
** hge_tut01 - Minimal HGE application
*/

#include <hge.h>
#include <hgefont.h>
#include <hgestrings.h>
#include <Dialoghelper.h>
#include ".\GfxFont.h"
#include "Shiptable.h"
#include "Front.h"
#include "PanelControler.h"
#pragma comment(linker, "/subsystem:console /entry:WinMainCRTStartup")

HGE *hge = 0;
Shiptable *table = 0;
extern PanelControler controler;

bool InitFunc()
{
	controler.SetCurrentPanel(new startPanel(1));
	controler.GetCurrentPanel()->Loading();
	return true;
}


bool GfxRestoreFunc()  
{  
  return false;
}  

bool FreeFunc()
{
	return true;
}

bool FrameFunc()
{
	controler.GetCurrentPanel()->Update();
	return controler.GetCurrentPanel()->Exit();
}

bool RenderFunc()
{	
	controler.GetCurrentPanel()->Render();
	return false;
}



int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	
	hge = hgeCreate(HGE_VERSION);
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "HGE Tutorial 01 - Minimal HGE application");
	hge->System_SetState(HGE_FPS,60);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENWIDTH,1280);
	hge->System_SetState(HGE_SCREENHEIGHT,960);
	hge->System_SetState(HGE_HIDEMOUSE,true);
	if(hge->System_Initiate())
	{
		InitFunc();
		hge->System_Start();
	}
	else
	{	
		MessageBox(NULL, hge->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
	}
	FreeFunc();
	hge->System_Shutdown();

	hge->Release();

	return 0;
}

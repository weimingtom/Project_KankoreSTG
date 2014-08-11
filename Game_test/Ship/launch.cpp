/*
** Haaf's Game Engine 1.8
** Copyright (C) 2003-2007, Relish Games
** hge.relishgames.com
**
** hge_tut02 - Using input, sound and rendering
*/


// Copy the files "particles.png" and "menu.wav"
// from the folder "precompiled" to the folder with
// executable file. Also copy hge.dll and bass.dll
// to the same folder.


#include "Shimakaze.h"
#include "Naka.h"
#include "Agano.h"
#include "Kongo.h"
#include "Boss.h"
#include "DDH.h"
#include "DDI.h"
#include "LCH.h"
#include "BS.h"

//ªì©l½á¤©
HGE *hge=0;
Shiptable *table=0;

Myship *myship = new Shimakaze();
Enemyship *shiptest = new Boss(368,50,0.1,90,0,0,0);
Enemyship *shiptest2 = new BS(50,-500,5,90,0,0,0);
Enemyship *shiptest3 = new DDH(700,-500,10,90,0,0,0,false);

bool FrameFunc()
{
	Shipcontroller::frameShip();

	// Continue execution
	return false;
}
// This function will be called by HGE when
// the application window should be redrawn.
// Put your rendering code here.
bool RenderFunc()
{
	// Begin rendering quads.
	// This function must be called
	// before any actual rendering.
	hge->Gfx_BeginScene();

	// Clear screen with black color
	hge->Gfx_Clear(0);

	// Render quads here. This time just
	// one of them will serve our needs.

	Shipcontroller::renderShip();

	// End rendering and update the screen
	hge->Gfx_EndScene();

	// RenderFunc should always return false
	return false;
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//Shipcontroller::createInitial();

	// Get HGE interface
	hge = hgeCreate(HGE_VERSION);

	// Set up log file, frame function, render function and window title
	hge->System_SetState(HGE_LOGFILE, "test.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "Object Test");

	// Set up video mode
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENWIDTH, Width);
	hge->System_SetState(HGE_SCREENHEIGHT, Height);
	hge->System_SetState(HGE_SCREENBPP, 32);

	if(hge->System_Initiate())
	{
		// Load sound and texture
		table = new Shiptable();
		Shipcontroller::loadShip();

		// Set up quad which we will use for rendering sprite
		// Let's rock now!
		hge->System_Start();

		// Free loaded texture and sound
	}
	else MessageBox(NULL, hge->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);

	// Clean up and shutdown
	hge->System_Shutdown();
	hge->Release();
	return 0;
}

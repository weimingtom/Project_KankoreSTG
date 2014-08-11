#ifndef STARTPANEL_H
#define STARTPANEL_H

#include "GUIPanel.h"
#include "hgeFont.h"
#include "menuitem.h"
#include <math.h>
#include "windows.h"
#include "HomePanel.h"
#include "GUIPanel.h"
#include "PanelControler.h"

class startPanel : public GUIPanel
{
public:
	startPanel(int id);

	void RenderFucn();//渲染函數，對應到目前Panel的渲染函數，已於Render內呼叫。修改定義，直接渲染屏幕。
	
	bool FrameFucn();//邏輯函數，對應到目前Panel的邏輯函數，已於Update內呼叫。修改定義，用法同主程式
	
	bool FreeFucn();//記憶體釋放函數，用於釋放素材資源
	
	bool InitResource();//建構出所有使用資源，在呼叫Loading函數之後自動呼叫
	
	//bool SystemState();//設置SystemState之函數
private:
	bool inputFlag;
	char input_Name[16];
	int count;
	HEFFECT		snd;
	HTEXTURE	tex;
	hgeQuad		quad;
	hgeFont		*typeFont;
	hgeSprite	*spr;
	hgeSprite	*logo;
};

#endif


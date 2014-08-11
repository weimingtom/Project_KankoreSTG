/*
** Haaf's Game Engine 1.7
** Copyright (C) 2003-2007, Relish Games
** hge.relishgames.com
**
** Tutorial 06 - Creating menus
*/

// In menuitem.cpp/h we define the
// behaviour of our custom GUI control

#include "hge.h"
#include "hgegui.h"
#include "hgefont.h"
#include "hgecolor.h"

#ifndef HGEGUIMENUITEM_H
#define HGEGUIMENUITEM_H

class hgeGUIMenuItem : public hgeGUIObject		//定義一個衍生自「hgeGUIObject」的組件:
{
public:
	hgeGUIMenuItem(int id, hgeFont *fnt, HEFFECT snd, float x, float y, float delay, char *title);

	virtual void	Render();			//將圖形化界面呈現在屏幕上
	virtual void	Update(float dt);	//更新GUI和user的輸入

	virtual void	Enter();			//起始動畫從這裡啟動
	virtual void	Leave();			//結束動畫從這裡啟動
	virtual bool	IsDone();			//測試組件的(進入/離開)動畫是否已經完成
	virtual void	Focus(bool bFocused);	//在組件(獲得/失去)控制權時呼叫。在這範例裡，我們把取得控制權的動畫在這裡開始
	virtual void	MouseOver(bool bOver);	//在滑鼠游標(進入/離開)組件作用範圍時呼叫

	virtual bool	MouseLButton(bool bDown);	//在滑鼠左鍵的狀態改變時呼叫
	virtual bool	KeyClick(int key, int chr);	//當某個按鍵被點擊(click)時會通知控制組件

private:
	hgeFont		*fnt;
	HEFFECT		snd;
	float		delay;
	char		*title;

	hgeColor	scolor, dcolor, scolor2, dcolor2, sshadow, dshadow;
	hgeColor	color, shadow;
	float		soffset, doffset, offset;
	float		timer, timer2;
};
#endif
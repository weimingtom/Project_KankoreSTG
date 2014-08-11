/*
** Haaf's Game Engine 1.7
** Copyright (C) 2003-2007, Relish Games
** hge.relishgames.com
**
** Tutorial 06 - Creating menus
*/

// In menuitem.cpp/h we define the
// behaviour of our custom GUI control

#include "menuitem.h"

// This is a GUI control constructor,
// we should initialize all the variables here
//組件的建構元(Constructor)需要初始化「hgeGUIObject」的成員資料
hgeGUIMenuItem::hgeGUIMenuItem(int _id, hgeFont *_fnt, HEFFECT _snd, float _x, float _y, float _delay, char *_title)
{
	float w;
	
	id=_id;
	fnt=_fnt;
	snd=_snd;
	delay=_delay;
	title=_title;

	color.SetHWColor(0xFFFFE060); //0xFFFFE060
	shadow.SetHWColor(0x30000000);	//0x30000000
	offset=0.0f;
	timer=-1.0f;
	timer2=-1.0f;

	bStatic=false;
	bVisible=true;
	bEnabled=true;

	w=fnt->GetStringWidth(title);
	rect.Set(_x-w/2, _y, _x+w/2, _y+fnt->GetHeight());
}

// This method is called when the control should be rendered
void hgeGUIMenuItem::Render()
{
	fnt->SetColor(shadow.GetHWColor());
	fnt->Render(rect.x1+offset+3, rect.y1+3, HGETEXT_LEFT, title);
	fnt->SetColor(color.GetHWColor());
	fnt->Render(rect.x1-offset, rect.y1-offset, HGETEXT_LEFT, title);
}

// This method is called each frame,
// we should update the animation here
//「Update」方法會在每次 GUI 更新和動畫更新時呼叫。在這範例中，我們使用兩個計時器(timers)，根據時間控制組件的顏色和位置
void hgeGUIMenuItem::Update(float dt)
{
	if(timer2 != -1.0f)
	{
		timer2+=dt;
		if(timer2 >= delay+0.1f)
		{
			color=scolor2+dcolor2;
			shadow=sshadow+dshadow;
			offset=0.0f;
			timer2=-1.0f;
		}
		else
		{
			if(timer2 < delay) { color=scolor2; shadow=sshadow; }
			else { color=scolor2+dcolor2*(timer2-delay)*10; shadow=sshadow+dshadow*(timer2-delay)*10; }
		}
	}
	else if(timer != -1.0f)
	{
		timer+=dt;
		if(timer >= 0.2f)
		{
			color=scolor+dcolor;
			offset=soffset+doffset;
			timer=-1.0f;
		}
		else
		{
			color=scolor+dcolor*timer*5;
			offset=soffset+doffset*timer*5;
		}
	}
}

// This method is called when the GUI
// is about to appear on the screen
//「Enter」方法是在組件剛出現於螢幕上時呼叫。組件的起始動畫應該會從這裡啟動
void hgeGUIMenuItem::Enter()
{
	hgeColor tcolor2;

	scolor2.SetHWColor(0x00FFE060);	//0x00FFE060
	tcolor2.SetHWColor(0xFFFFE060);	//0xFFFFE060
	dcolor2=tcolor2-scolor2;

	sshadow.SetHWColor(0x00000000);	//0x00000000
	tcolor2.SetHWColor(0x30000000);	//0x30000000
	dshadow=tcolor2-sshadow;

	timer2=0.0f;
}

// This method is called when the GUI
// is about to disappear from the screen
//「Leave」方法是在GUI消失於螢幕上時呼叫。組件的結束動畫應該要從這裡啟動
void hgeGUIMenuItem::Leave()
{
	hgeColor tcolor2;

	scolor2.SetHWColor(0xFFFFE060);		//0xFFFFE060
	tcolor2.SetHWColor(0x00FFE060);		//0x00FFE060
	dcolor2=tcolor2-scolor2;

	sshadow.SetHWColor(0x30000000);		//0x30000000
	tcolor2.SetHWColor(0x00000000);		//0x00000000
	dshadow=tcolor2-sshadow;

	timer2=0.0f;
}

// This method is called to test whether the control
// have finished it's Enter/Leave animation
//「IsDone」是用來測試組件的(進入/離開)動畫是否已經完成。如果動畫已完結，則會回傳ture
bool hgeGUIMenuItem::IsDone()
{
	if(timer2==-1.0f) return true;
	else return false;
}

// This method is called when the control
// receives or loses keyboard input focus
//「Focus」方法是在組件(獲得/失去)控制權時呼叫。在這範例裡，我們把取得控制權的動畫在這裡開始
void hgeGUIMenuItem::Focus(bool bFocused)
{
	hgeColor tcolor;
	
	if(bFocused)
	{
		hge->Effect_Play(snd);
		scolor.SetHWColor(0xFFFFE060);  //0xFFFFE060
		tcolor.SetHWColor(0xFFFFFFFF);	//0xFFFFFFFF
		soffset=0;
		doffset=4;
	}
	else
	{
		scolor.SetHWColor(0xFFFFFFFF);	//0xFFFFFFFF
		tcolor.SetHWColor(0xFFFFE060);	//0xFFFFE060
		soffset=4;
		doffset=-4;
	}

	dcolor=tcolor-scolor;
	timer=0.0f;
}

// This method is called to notify the control
// that the mouse cursor has entered or left it's area
//「MouseOver」方法會再滑鼠游標(進入/離開)組件作用範圍時呼叫。當滑鼠移入組件範圍時，這裡我們只將GUI的目標設置在組件上
void hgeGUIMenuItem::MouseOver(bool bOver)
{
	if(bOver) gui->SetFocus(id);
}

// This method is called to notify the control
// that the left mouse button state has changed.
// If it returns true - the caller will receive
// the control's ID
//「MouseLButton」方法會再滑鼠左鍵的狀態改變時呼叫。當組件改變狀態並且想要提醒呼叫者時，應該回傳ture
bool hgeGUIMenuItem::MouseLButton(bool bDown)
{
	if(!bDown)
	{
		offset=4;
		return true;
	}
	else 
	{
		hge->Effect_Play(snd);
		offset=0;
		return false;
	}
}

// This method is called to notify the
// control that a key has been clicked.
// If it returns true - the caller will
// receive the control's ID
//「KeyClick」方法是當某個按鍵被點擊(click)時會通知控制組件。當組件改變狀態並且想要提醒呼叫者時，應該回傳ture
bool hgeGUIMenuItem::KeyClick(int key, int chr)
{
	if(key==HGEK_ENTER || key==HGEK_SPACE)
	{
		MouseLButton(true);
		return MouseLButton(false);
	}

	return false;
}

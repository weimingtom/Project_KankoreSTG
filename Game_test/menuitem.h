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

class hgeGUIMenuItem : public hgeGUIObject		//�w�q�@�ӭl�ͦۡuhgeGUIObject�v���ե�:
{
public:
	hgeGUIMenuItem(int id, hgeFont *fnt, HEFFECT snd, float x, float y, float delay, char *title);

	virtual void	Render();			//�N�ϧΤƬɭ��e�{�b�̹��W
	virtual void	Update(float dt);	//��sGUI�Muser����J

	virtual void	Enter();			//�_�l�ʵe�q�o�̱Ұ�
	virtual void	Leave();			//�����ʵe�q�o�̱Ұ�
	virtual bool	IsDone();			//���ղե�(�i�J/���})�ʵe�O�_�w�g����
	virtual void	Focus(bool bFocused);	//�b�ե�(��o/���h)�����v�ɩI�s�C�b�o�d�Ҹ̡A�ڭ̧���o�����v���ʵe�b�o�̶}�l
	virtual void	MouseOver(bool bOver);	//�b�ƹ����(�i�J/���})�ե�@�νd��ɩI�s

	virtual bool	MouseLButton(bool bDown);	//�b�ƹ����䪺���A���ܮɩI�s
	virtual bool	KeyClick(int key, int chr);	//��Y�ӫ���Q�I��(click)�ɷ|�q������ե�

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
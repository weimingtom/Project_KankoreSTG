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

	void RenderFucn();//��V��ơA������ثePanel����V��ơA�w��Render���I�s�C�ק�w�q�A������V�̹��C
	
	bool FrameFucn();//�޿��ơA������ثePanel���޿��ơA�w��Update���I�s�C�ק�w�q�A�Ϊk�P�D�{��
	
	bool FreeFucn();//�O���������ơA�Ω���������귽
	
	bool InitResource();//�غc�X�Ҧ��ϥθ귽�A�b�I�sLoading��Ƥ���۰ʩI�s
	
	//bool SystemState();//�]�mSystemState�����
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


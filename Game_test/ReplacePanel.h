#ifndef REPLACEPANEL_H
#define REPLACEPANEL_H

#include "GUIPanel.h"
#include "hgeguictrls.h"
#include "menuitem.h"
#include "math.h"

class ReplacePanel : public GUIPanel 
{
public:
	ReplacePanel(int id);

	void RenderFucn();//��V��ơA������ثePanel����V��ơA�w��Render���I�s�C�ק�w�q�A������V�̹��C
	
	bool FrameFucn();//�޿��ơA������ثePanel���޿��ơA�w��Update���I�s�C�ק�w�q�A�Ϊk�P�D�{��
	
	bool FreeFucn();//�O���������ơA�Ω���������귽
	
	bool InitResource();//�غc�X�Ҧ��ϥθ귽�A�b�I�sLoading��Ƥ���۰ʩI�s

	//�Ѻc�禡
	~ReplacePanel();

private:
	HEFFECT		snd;
	HTEXTURE	tex;
	HTEXTURE	TEX_BUTTON;
	hgeQuad		quad;
	hgeSprite	*spr;
	hgeSprite	*person;
	hgeSprite	*Bar_Top;

	//fleet buy
	hgeSprite	*naka_buy;
	hgeSprite	*shimakaze_buy;
	hgeSprite	*kongo_buy;
	hgeSprite	*agano_buy;
	//equipment
	hgeSprite	*tenCM;
};
#endif
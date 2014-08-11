#ifndef GAMEPANEL_H
#define GAMEPANEL_H
#include "GUIPanel.h"
#include "Dialoghelper.h"
#include "MapScript.h"
#include "menuitem.h"

#include "Bullet.h"
#include "Warship.h"
#include "Enemyship.h"
#include "Myship.h"
#include "Shimakaze.h"
#include "Kongo.h"
#include "Naka.h"
#include "Agano.h"
#include "Trash.h"
#include "Boss.h"
#include "Generalbullet.h"
#include "DDH.h"
#include "DDI.h"
#include "LCH.h"
#include "BS.h"
#include "Shiptable.h"
#include "Front.h"

class GamePanel : public GUIPanel
{
public:
	GamePanel(int id);
	~GamePanel();
	
	void RenderFucn();//��V��ơA������ثePanel����V��ơA�w��Render���I�s�C�ק�w�q�A������V�̹��C
	
	bool FrameFucn();//�޿��ơA������ثePanel���޿��ơA�w��Update���I�s�C�ק�w�q�A�Ϊk�P�D�{��
	
	bool FreeFucn(){return false;};//�O���������ơA�Ω���������귽
	
	bool InitResource();//�غc�X�Ҧ��ϥθ귽�A�b�I�sLoading��Ƥ���۰ʩI�s
	
	bool SystemState(){return false;};//�]�mSystemState�����
//�I���귽
private:
	void RenderTarget();
	static bool SystemLostFoucus();
	bool checkFlagChange();
	hgeQuad Background;
	hgeQuad Mask;
	int width,height;
	HTARGET		target;
	hgeSprite *PlayGroundTarget;
	hgeSprite *ill;
	hgeSprite *cursor_spr;
	HTEXTURE cursor_tex;
	static bool stopFlag;
//�}���귽
	MapScript *mapReader;
//����ŧi
	Myship *myship;
	Enemyship *shiptest;
	Enemyship *shiptest2;
	Enemyship *shiptest3;
};
#endif

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
	
	void RenderFucn();//渲染函數，對應到目前Panel的渲染函數，已於Render內呼叫。修改定義，直接渲染屏幕。
	
	bool FrameFucn();//邏輯函數，對應到目前Panel的邏輯函數，已於Update內呼叫。修改定義，用法同主程式
	
	bool FreeFucn(){return false;};//記憶體釋放函數，用於釋放素材資源
	
	bool InitResource();//建構出所有使用資源，在呼叫Loading函數之後自動呼叫
	
	bool SystemState(){return false;};//設置SystemState之函數
//背景資源
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
//腳本資源
	MapScript *mapReader;
//角色宣告
	Myship *myship;
	Enemyship *shiptest;
	Enemyship *shiptest2;
	Enemyship *shiptest3;
};
#endif

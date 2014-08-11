#ifndef EQUIPPANEL_H
#define EQUIPPANEL_H

#include "GUIPanel.h"
#include "hgeguictrls.h"
#include "menuitem.h"
#include "math.h"

class EquipPanel : public GUIPanel 
{
public:
	EquipPanel(int id);

	void RenderFucn();//渲染函數，對應到目前Panel的渲染函數，已於Render內呼叫。修改定義，直接渲染屏幕。
	
	bool FrameFucn();//邏輯函數，對應到目前Panel的邏輯函數，已於Update內呼叫。修改定義，用法同主程式
	
	bool FreeFucn();//記憶體釋放函數，用於釋放素材資源
	
	bool InitResource();//建構出所有使用資源，在呼叫Loading函數之後自動呼叫

	//解構函式
	~EquipPanel();

private:
	void CheckItem();
	HEFFECT		snd;
	HTEXTURE	tex;
	HTEXTURE	TEX_BUTTON;
	hgeQuad		quad;
	hgeSprite	*spr;
	hgeSprite	*person;
	hgeSprite	*Bar_Top;
	int Lock_Sum;
	int SumOnScreen;
	bool CheckItemList[80];
	//fleet buy
	hgeSprite	*naka_buy;
	hgeSprite	*shimakaze_buy;
	hgeSprite	*kongo_buy;
	hgeSprite	*agano_buy;
};
#endif
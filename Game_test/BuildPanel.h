#ifndef BUILDPANEL_H
#define BUILDPANEL_H

#include "GUIPanel.h"
#include "hgeguictrls.h"
#include "menuitem.h"
#include "math.h"

class BuildPanel : public GUIPanel
{
public:
	BuildPanel(int id);

	void RenderFucn();//渲染函數，對應到目前Panel的渲染函數，已於Render內呼叫。修改定義，直接渲染屏幕。
	
	bool FrameFucn();//邏輯函數，對應到目前Panel的邏輯函數，已於Update內呼叫。修改定義，用法同主程式
	
	bool FreeFucn();//記憶體釋放函數，用於釋放素材資源
	
	bool InitResource();//建構出所有使用資源，在呼叫Loading函數之後自動呼叫

	~BuildPanel();
private:
	HEFFECT		snd;
	HTEXTURE	tex;
	HTEXTURE	TEX_BUTTON;
	hgeQuad		quad;
	hgeSprite	*spr;
	hgeSprite	*person;
	hgeSprite	*Bar_Top;
	bool SaleoutFlag[4];
	int TargetToBuy;
	int TargetToSet;

	//fleet buy
	hgeSprite	*naka_buy;
	hgeSprite	*shimakaze_buy;
	hgeSprite	*kongo_buy;
	hgeSprite	*agano_buy;
};
#endif
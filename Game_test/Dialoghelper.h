#ifndef DIALOGHELPER_H
#define DIALOGHELPER_H
#include "hge.h"
#include "hgegui.h"
#include ".\GfxFont.h"
#include "hgesprite.h"
#include <hgestrings.h>
#include <stdio.h>



class Dialoghelper : public hgeGUIObject
{
public:
	//建構函數
	Dialoghelper(int _id,float _x,float _y,float _w,float _h,GfxFont* Fnt,HTEXTURE BgTex=0);
	//螢幕渲染，放置在渲染主程序下
	virtual void Render();
	//每幀更新函數，放置在幀函數主程序下
	virtual void Update(float  fDeltaTime);
	//偵測按鍵，Update內部調用實作
	virtual bool KeyClick(int key, int chr);
	//目標渲染，用以固定紋理區域大小，內部調用實作
	virtual void RenderTarget();
	//設置文本
	virtual void SetStringtable(hgeStringTable *_hst);
	//調整文本位置
	virtual void AdjustWordPos(float x,float y);
	//設置顯示模式1為逐字，2為固定
	virtual void SetMode(bool _mode);
	//獲取現在模式
	virtual bool GetMode();
	//滑鼠點擊
	virtual bool MouseLButton(bool bDown);
	//進入動畫
	virtual void Enter();

protected:
	hgeSprite		*tar;	//顯示用精靈
	hgeStringTable	*hst;
	char *str;
	hgeQuad			BG;		//背景紋理結構
	HTARGET			target;	//顯示區域大小
	GfxFont*		fnt;	//中文文字紋理
	float			timer;
	float			timeSpeed;
	int				xNum,strId;
	bool			Mode;
	float			width;
	float			height;
	float			adj_x;
	float			adj_y;
	char			stringName[10];//文本序號用
};
#endif
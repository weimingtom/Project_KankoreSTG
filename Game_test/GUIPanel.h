#ifndef GUIPANEL_H
#define GUIPANEL_H

#include "hge.h"
#include "hgegui.h"
#include "hgesprite.h"
#include "hgestrings.h"
#include "hgefont.h"
#include "stdio.h"
#include ".\GfxFont.h"
#include <windows.h>
#include <process.h>




class GUIPanel
{
public:
	//建構子，繼承此類別務必先定義建構子
	GUIPanel(int id);

	virtual void RenderFucn(){
		hge->Gfx_BeginScene();
		hge->Gfx_Clear(0);
		hge->Gfx_EndScene();};//渲染函數，對應到目前Panel的渲染函數，已於Render內呼叫。修改定義，直接渲染屏幕。
	
	virtual bool FrameFucn() = 0;//邏輯函數，對應到目前Panel的邏輯函數，已於Update內呼叫。修改定義，用法同主程式
	
	virtual	bool FreeFucn() = 0;//記憶體釋放函數，用於釋放素材資源
	
	virtual	bool InitResource() = 0;//建構出所有使用資源，在呼叫Loading函數之後自動呼叫
	
	virtual	bool SystemState(){return false;};//設置SystemState之函數
	
	//半形轉全形
	char* HalfToFullconverter(const char *words);
	//多字節轉寬字節
	//wchar_t* ToWCharSet(const char* _charset);
	//外部呼叫用渲染函式，請在主程式RenderFucn內呼叫，既有定義呼叫Loading函式，不建議進行修改
	void Render();
	//外部呼叫用幀函式，請在主程式FrameFucn內呼叫，既有定義呼叫Loading函式，不建議進行修改
	void Update();
	//載入用函式定義，不建議進行修改
	void Loading();
	//Exit
	bool Exit();

protected:

	//一般繼承變數定義
	int PanelId;
	hgeGUI		*gui; 
	GfxFont		*ChFont;
	hgeFont		*HgeFont;
	static HGE	*hge;
	static bool ExitFlag;

private:

	//載入用靜態函式、變數定義，不建議進行修改
	HANDLE thread;
	DWORD *tid;
	static int counter;
	static int LoadAniNum;
	static bool LoadCompleteFlag;
	static GfxFont *LoadingFnt;
	void LoadingSence(void);
	void LoadingUpdate(void);
	void static LoadResource(GUIPanel *Panel);
};
#endif
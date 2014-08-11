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
	//�غc�l�A�~�Ӧ����O�ȥ����w�q�غc�l
	GUIPanel(int id);

	virtual void RenderFucn(){
		hge->Gfx_BeginScene();
		hge->Gfx_Clear(0);
		hge->Gfx_EndScene();};//��V��ơA������ثePanel����V��ơA�w��Render���I�s�C�ק�w�q�A������V�̹��C
	
	virtual bool FrameFucn() = 0;//�޿��ơA������ثePanel���޿��ơA�w��Update���I�s�C�ק�w�q�A�Ϊk�P�D�{��
	
	virtual	bool FreeFucn() = 0;//�O���������ơA�Ω���������귽
	
	virtual	bool InitResource() = 0;//�غc�X�Ҧ��ϥθ귽�A�b�I�sLoading��Ƥ���۰ʩI�s
	
	virtual	bool SystemState(){return false;};//�]�mSystemState�����
	
	//�b�������
	char* HalfToFullconverter(const char *words);
	//�h�r�`��e�r�`
	//wchar_t* ToWCharSet(const char* _charset);
	//�~���I�s�δ�V�禡�A�Цb�D�{��RenderFucn���I�s�A�J���w�q�I�sLoading�禡�A����ĳ�i��ק�
	void Render();
	//�~���I�s�δV�禡�A�Цb�D�{��FrameFucn���I�s�A�J���w�q�I�sLoading�禡�A����ĳ�i��ק�
	void Update();
	//���J�Ψ禡�w�q�A����ĳ�i��ק�
	void Loading();
	//Exit
	bool Exit();

protected:

	//�@���~���ܼƩw�q
	int PanelId;
	hgeGUI		*gui; 
	GfxFont		*ChFont;
	hgeFont		*HgeFont;
	static HGE	*hge;
	static bool ExitFlag;

private:

	//���J���R�A�禡�B�ܼƩw�q�A����ĳ�i��ק�
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
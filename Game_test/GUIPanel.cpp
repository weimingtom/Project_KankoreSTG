#include "GUIPanel.h"
using namespace Util;


//常量定義
bool GUIPanel::LoadCompleteFlag=false;
int GUIPanel::LoadAniNum=7;
int GUIPanel::counter=0;
GfxFont *GUIPanel::LoadingFnt = new GfxFont("微軟正黑體",54 ,TRUE,false,TRUE);
HGE *GUIPanel::hge=0;
bool GUIPanel::ExitFlag = false;

//Loading函數定義

GUIPanel::GUIPanel(int id)
{
	ChFont = new GfxFont("微軟正黑體",32 ,TRUE,false,TRUE);
	HgeFont = new hgeFont("font1.fnt");
	hge = hgeCreate(HGE_VERSION);
	gui = new hgeGUI();
	PanelId = id;
}
void GUIPanel::Loading()
{
	tid = new DWORD;
	LoadCompleteFlag = false;
	thread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)this->LoadResource,this,0,tid);
}

void GUIPanel::LoadingSence(void)
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	LoadingFnt->PrintEx(1280-460,960-100,LoadAniNum,"ＬＯＡＤＩＮＧ‧‧‧");
	hge->Gfx_EndScene();
}
void GUIPanel::LoadingUpdate(void)
{
	if (counter >=30)
	{
		if (LoadAniNum<=8)
			LoadAniNum++;
		else
			LoadAniNum=5;
		counter=0;
	}
	else
		counter++;
}
void GUIPanel::LoadResource(GUIPanel *Panel)
{
	Panel->InitResource();
	LoadCompleteFlag = true;
}
void GUIPanel::Render()
{
	if (!LoadCompleteFlag)
	{
		LoadingSence();
	}
	else
	{
		RenderFucn();
	}
}
void GUIPanel::Update()
{
	if (!LoadCompleteFlag)
	{
		LoadingUpdate();
	}
	else
	{
		if (FrameFucn())
		{
			ExitFlag = true;
		}
		else 
		{
			ExitFlag = false;
		}
	}
}

bool GUIPanel::Exit()
{
	return ExitFlag;
}
char *GUIPanel::HalfToFullconverter(const char words[16])
{
	char *buf;
	int count=0;
	buf = new char[32];

	for(int i=0;i<16;i++)
	{
		switch(words[i])
		{	
			case'a':
				strcpy((buf+count),"ａ");
				count+=2;
				break;
			case'A':
				strcpy((buf+count),"Ａ");
				count+=2;
				break;
			case'b':
				strcpy((buf+count),"ｂ");
				count+=2;
				break;
			case'B':
				strcpy((buf+count),"Ｂ");
				count+=2;
				break;
			case'c':
				strcpy((buf+count),"ｃ");
				count+=2;
				break;
			case'C':
				strcpy((buf+count),"Ｃ");
				count+=2;
				break;
			case'd':
				strcpy((buf+count),"ｄ");
				count+=2;
				break;
			case'D':
				strcpy((buf+count),"Ｄ");
				count+=2;
				break;
			case'e':
				strcpy((buf+count),"ｅ");
				count+=2;
				break;
			case'E':
				strcpy((buf+count),"Ｅ");
				count+=2;
				break;
			case'f':
				strcpy((buf+count),"ｆ");
				count+=2;
				break;
			case'F':
				strcpy((buf+count),"Ｆ");
				count+=2;
				break;
			case'g':
				strcpy((buf+count),"ｇ");
				count+=2;
				break;
			case'G':
				strcpy((buf+count),"Ｇ");
				count+=2;
				break;
			case'h':
				strcpy((buf+count),"ｈ");
				count+=2;
				break;
			case'H':
				strcpy((buf+count),"Ｈ");
				count+=2;
				break;
			case'i':
				strcpy((buf+count),"ｉ");
				count+=2;
				break;
			case'I':
				strcpy((buf+count),"Ｉ");
				count+=2;
				break;
			case'j':
				strcpy((buf+count),"ｊ");
				count+=2;
				break;
			case'J':
				strcpy((buf+count),"Ｊ");
				count+=2;
				break;
			case'k':
				strcpy((buf+count),"ｋ");
				count+=2;
				break;
			case'K':
				strcpy((buf+count),"Ｋ");
				count+=2;
				break;
			case'l':
				strcpy((buf+count),"ｌ");
				count+=2;
				break;
			case'L':
				strcpy((buf+count),"Ｌ");
				count+=2;
				break;
			case'm':
				strcpy((buf+count),"ｍ");
				count+=2;
				break;
			case'M':
				strcpy((buf+count),"Ｍ");
				count+=2;
				break;
			case'n':
				strcpy((buf+count),"ｎ");
				count+=2;
				break;
			case'N':
				strcpy((buf+count),"Ｎ");
				count+=2;
				break;
			case'o':
				strcpy((buf+count),"ｏ");
				count+=2;
				break;
			case'O':
				strcpy((buf+count),"Ｏ");
				count+=2;
				break;
			case'p':
				strcpy((buf+count),"ｐ");
				count+=2;
				break;
			case'P':
				strcpy((buf+count),"Ｐ");
				count+=2;
				break;
			case'q':
				strcpy((buf+count),"ｑ");
				count+=2;
				break;
			case'Q':
				strcpy((buf+count),"Ｑ");
				count+=2;
				break;
			case'r':
				strcpy((buf+count),"ｒ");
				count+=2;
				break;
			case'R':
				strcpy((buf+count),"Ｒ");
				count+=2;
				break;
			case's':
				strcpy((buf+count),"ｓ");
				count+=2;
				break;
			case'S':
				strcpy((buf+count),"Ｓ");
				count+=2;
				break;
			case't':
				strcpy((buf+count),"ｔ");
				count+=2;
				break;
			case'T':
				strcpy((buf+count),"Ｔ");
				count+=2;
				break;
			case'u':
				strcpy((buf+count),"ｕ");
				count+=2;
				break;
			case'U':
				strcpy((buf+count),"Ｕ");
				count+=2;
				break;
			case'v':
				strcpy((buf+count),"ｖ");
				count+=2;
				break;
			case'V':
				strcpy((buf+count),"Ｖ");
				count+=2;
				break;
			case'w':
				strcpy((buf+count),"ｗ");
				count+=2;
				break;
			case'W':
				strcpy((buf+count),"Ｗ");
				count+=2;
				break;
			case'x':
				strcpy((buf+count),"ｘ");
				count+=2;
				break;
			case'X':
				strcpy((buf+count),"Ｘ");
				count+=2;
				break;
			case'y':
				strcpy((buf+count),"ｙ");
				count+=2;
				break;
			case'Y':
				strcpy((buf+count),"Ｙ");
				count+=2;
				break;
			case'z':
				strcpy((buf+count),"ｚ");
				count+=2;
				break;
			case'Z':
				strcpy((buf+count),"Ｚ");
				count+=2;
				break;
			default:
				*(buf+count)=words[i];
				count++;
				break;
		}
	}
	return buf;
}

/*
wchar_t* GUIPanel::ToWCharSet(const char* _charset)
{
	wchar_t *pwText;
	DWORD dwNum = MultiByteToWideChar(CP_ACP , 0 , _charset , -1 , NULL , 0);
	pwText = new wchar_t [dwNum];
	if (!pwText)
		delete pwText;
	MultiByteToWideChar(CP_ACP , 0 , _charset , -1 ,pwText , dwNum);
	return pwText;
}*/
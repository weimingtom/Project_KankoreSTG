#include "GUIPanel.h"
using namespace Util;


//�`�q�w�q
bool GUIPanel::LoadCompleteFlag=false;
int GUIPanel::LoadAniNum=7;
int GUIPanel::counter=0;
GfxFont *GUIPanel::LoadingFnt = new GfxFont("�L�n������",54 ,TRUE,false,TRUE);
HGE *GUIPanel::hge=0;
bool GUIPanel::ExitFlag = false;

//Loading��Ʃw�q

GUIPanel::GUIPanel(int id)
{
	ChFont = new GfxFont("�L�n������",32 ,TRUE,false,TRUE);
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
	LoadingFnt->PrintEx(1280-460,960-100,LoadAniNum,"�ڢݢϢҢעܢաE�E�E");
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
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'A':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'b':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'B':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'c':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'C':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'd':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'D':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'e':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'E':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'f':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'F':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'g':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'G':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'h':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'H':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'i':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'I':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'j':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'J':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'k':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'K':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'l':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'L':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'm':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'M':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'n':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'N':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'o':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'O':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'p':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'P':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'q':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'Q':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'r':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'R':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case's':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'S':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case't':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'T':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'u':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'U':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'v':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'V':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'w':
				strcpy((buf+count),"�@");
				count+=2;
				break;
			case'W':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'x':
				strcpy((buf+count),"�A");
				count+=2;
				break;
			case'X':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'y':
				strcpy((buf+count),"�B");
				count+=2;
				break;
			case'Y':
				strcpy((buf+count),"��");
				count+=2;
				break;
			case'z':
				strcpy((buf+count),"�C");
				count+=2;
				break;
			case'Z':
				strcpy((buf+count),"��");
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
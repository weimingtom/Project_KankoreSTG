#include "MapScript.h"

#include "hge.h"
#include "hgerect.h"
#include "hgesprite.h"
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
#include "Shipcontroller.h"

extern  Shiptable *table;

const char *MapScript::Header="[MAP_SCRIPT_START]";
const char *MapScript::Ender="[MAP_SCRIPT_END]";
bool MapScript::ReaderOpen = false;
bool MapScript::ExitFlag = false;
//GetCurrentThreadId()
MapScript::MapScript(const char *_path)
{
	Map = new MapFile();
	fstream File;
	File.open(_path,ios::in);
	printf("%s\n",_path);
	if (File)
	{
		char command_line[128];
		while (File.getline(command_line,sizeof(command_line),'\n'))
		{
			char* buf;
			buf = new char[128];
			if (strncmp(command_line,"",128))
			{
				strncpy(buf,command_line,128);
				Map->push_back(buf);
			}
		}
		printf("Get The File.\n");
	}
	File.close();
	For_Counter=0;
	
}
MapScript::~MapScript()
{
	Map->clear();
	printf("Thread %d Clear Map.\n",GetCurrentThreadId());
}
void MapScript::ScriptRead()
{
	ReaderOpen = false;
	ExitFlag = false;
	tid =new DWORD;
	ReaderOpen =true;
	thread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)this->StartThread,this,0,tid);
}
void MapScript::Reader()
{
	for (list<char *>::iterator i=Map->begin(); i !=Map->end(); i++)
	{
		while (!(ReaderOpen ^ ExitFlag)){;};
		if (ExitFlag)
			break;
		int is_for = Parser(*i);
		if (is_for == FOR)
		{
			For_Tag = i++;
			i--;
		}
		else if (is_for == ENDFOR)
		{
			For_Counter--;
			if (For_Counter != 0)
				i = For_Tag;
		}
	}
}
void MapScript::StartThread(MapScript *_Map)
{
	printf("Start Thread\n");
	_Map->Reader();
	ReaderOpen =false;
	printf("End Thread\n");
	delete _Map;
}



int MapScript::Parser(const char* command)
{
	char *getTag,*tokenBrk,*data;
	char *tag[10];
	int count=0;
	data = new char [128];
	strncpy(data,command,128);
	for (getTag = strtok_s(data," ",&tokenBrk);getTag;getTag = strtok_s( NULL , " " , &tokenBrk ))
	{
		tag[count++] = getTag;
	}
	int size = count;
	Warship *newship;
	bool switch_LR = 1;
		if (strcmp(tag[9],"TRUE"))
			switch_LR = 1;
	switch (CommandChanger(tag[0]))
	{
	case CREATE:
		printf("Create a %s at (%f,%f) with vector (%f,%f,%f,%f,%d).\n",tag[1],atof(tag[2]),atof(tag[3]),atof(tag[4]),atof(tag[5]),atof(tag[6]),atof(tag[7]),atoi(tag[8]));
		switch (ShipCreateTable(tag[1]))
		{
		case _DDH:
			newship = new DDH(atof(tag[2]),atof(tag[3]),atof(tag[4]),atof(tag[5]),atof(tag[6]),atof(tag[7]),atoi(tag[8]),switch_LR);
			Shipcontroller::loadShip();
			break;
		case _DDI:
			newship = new DDI(atof(tag[2]),atof(tag[3]),atof(tag[4]),atof(tag[5]),atof(tag[6]),atof(tag[7]),atoi(tag[8]),switch_LR);
			Shipcontroller::loadShip();
			break;
		case _LCH:
			newship = new LCH(atof(tag[2]),atof(tag[3]),atof(tag[4]),atof(tag[5]),atof(tag[6]),atof(tag[7]),atoi(tag[8]),switch_LR);
			Shipcontroller::loadShip();
			break;
		case _BS:
			newship = new BS(atof(tag[2]),atof(tag[3]),atof(tag[4]),atof(tag[5]),atof(tag[6]),atof(tag[7]),atoi(tag[8]));
			Shipcontroller::loadShip();
			break;
		case _BOSS:
			newship = new Boss(atof(tag[2]),atof(tag[3]),atof(tag[4]),atof(tag[5]),atof(tag[6]),atof(tag[7]),atoi(tag[8]));
			Shipcontroller::loadShip();
			break;
		default:
			printf("Create has a fault. We didn't have any shiptype named %s",tag[1]);
			break;
		}
		break;
	case STOP:
		printf("Sleep %d sec.\n",atoi(tag[1]));
		for (int i = atoi(tag[1]);i>0;i--)
		{
			while (!(ReaderOpen ^ ExitFlag)){;};
			if (ExitFlag)
				break;
			Sleep(1);
		}
		break;
	case FOR:
		For_Counter = atoi(tag[3]) - atoi(tag[1]); 
		printf ("FOR %d Times\n",For_Counter);
		delete data;
		return FOR;
	case ENDFOR:
		return ENDFOR;
	case HEADER_START:
		printf("Script Start.\n");
		break;
	case HEADER_END:
		printf("Script End.\n");
		break;
	default:
		printf("µL¦¹«ü¥O¡C\n");
		break;
	}
	delete data;
	return 0;
}
int MapScript::CommandChanger(const char* command)
{
	if (strcmp(command,"CREATE") == 0)
		return CREATE;
	else if (strcmp(command,"STOP") == 0)
		return STOP;
	else if (strcmp(command,"FOR") == 0)
		return FOR;
	else if (strcmp(command,"ENDFOR") == 0)
		return ENDFOR;
	else if (strcmp(command,Header) == 0)
		return HEADER_START; 
	else if (strcmp(command,Ender) == 0)
		return HEADER_END;
	else
		return OTHER;
}
int MapScript::ShipCreateTable(const char* command)
{
	if (strcmp(command,"DESTROYER_H") == 0)
		return _DDH;
	else if (strcmp(command,"DESTROYER_I") == 0)
		return _DDI;
	else if (strcmp(command,"LIGHT_CRUISER") == 0)
		return _LCH;
	else if (strcmp(command,"BATTLESHIP") == 0)
		return _BS;
	else if (strcmp(command,"BOSS") == 0)
		return _BOSS;
	else
		return _FAULT;
}
void MapScript::PauseRead(){ReaderOpen = false;}
void MapScript::StartRead(){ReaderOpen = true;}
void MapScript::Stop(){ExitFlag = true;}
bool MapScript::GetReadState(){return ReaderOpen;}
#ifndef MAPSCRIPT_H
#define MAPSCRIPT_H

#include "stdio.h"
#include <iostream>
#include <fstream>
#include <list>
#include <string.h>
#include "windows.h"
using namespace std;


typedef list<char*> MapFile;

class MapScript
{
public:
	MapScript(const char *_path);
	~MapScript();
	void ScriptRead();
	void Clear();
	void Reader();
	bool GetReadState();
	static void PauseRead();
	static void StartRead();	
	void Stop();
private:
	MapFile *Map;
	const static char* Header;
	const static char* Ender;
	//static void ScriptReadFucn();

	HANDLE thread;
	DWORD *tid;
	int Parser(const char* command);
	int ShipCreateTable(const char* command);
	int CommandChanger(const char* command);
	void static StartThread(MapScript *_Map);

private:
	list<char *>::iterator For_Tag;
	int For_Counter;
	bool static ReaderOpen;
	bool static ExitFlag;
	enum CommandTag {CREATE = 1 , STOP = 3 , CLEAR = 2 , FOR = 4 , ENDFOR = 5 , OTHER = 0 , HEADER_START = 254 , HEADER_END=255};
	enum ShipCreatTable	{_FAULT = 0 , _DDH = 1 , _DDI=2 , _LCH = 3 , _BS = 9 , _BOSS = 20};
};
#endif
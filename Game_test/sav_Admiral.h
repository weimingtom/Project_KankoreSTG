//提督資料類別
#ifndef SAVADMIRAL_H
#define SAVADMIRAL_H
#include "stdio.h"
#include "EquipIDTable.h"
#include <iostream>
#include <string.h>
using namespace std;

enum shiptype{ _NOSHIP = 0 , _KONGOU = 1 , _SHIMAKAZE = 2 , _NAKA = 3 , _AGANO = 4};

struct ShipData
{
	shiptype ShipType;
	unsigned short int Equip[4];
};
struct SaveData
{
	char Name[16];
	bool Gender;
	unsigned long int Money;
	ShipData Ship[4];
	unsigned short int EquipInventory[80];
};

class ShipInfo
{
public:
	ShipInfo(shiptype type);
	shiptype getShipType();
	void setShipType(shiptype type);
	void setEquip(int _id,int equip_kind_id);
	unsigned short int getEquip(int _id);
private:
	shiptype ShipType;
	unsigned short int Equip[4];
};

class Admiral
{

public:
	//建構子
	Admiral();
	//建構子，可以預先建構名字以及性別
	Admiral(const char* _name,bool _gender);
	//設置名稱
	void setName(const char* _name);
	void setGender(bool _gender);
	void setMoney(long int _money);
	void addEquipInventory(int _id,short int add_num);
	char* getName();
	bool getGender();
	unsigned long int getMoney();
	int getShipNum();
	ShipInfo *getShip(int _id);
	unsigned short int getEquipInventory(int _id);
	//讀取檔案，沒有讀取到檔案則回傳FALSE
	bool Loading(char *_path);
	void Saving();
private:
	char Name[16];
	bool Gender;
	int Money;
	ShipInfo *Ship[4];
	unsigned short int EquipInventory[80];

	char *data_path;
	SaveData savedata;
};
#endif
#include "sav_Admiral.h"
//ShipInfo

ShipInfo::ShipInfo(shiptype type)
{
	ShipType = type;
	for (int i =0 ; i<4 ; i++)
		Equip[i]=0;
}
void ShipInfo::setEquip(int _id,int equip_kind_id)
{
	if (_id<4)
		Equip[_id] = equip_kind_id;
	else
		printf("裝備只有四格。");
}
unsigned short int ShipInfo::getEquip(int _id)
{
	if (_id<4)
		return Equip[_id];
	else
	{
		printf("裝備只有四格。");
		return 0;
	}
}
shiptype ShipInfo::getShipType()
{
	return ShipType;
}
void ShipInfo::setShipType(shiptype type)
{
	ShipType = type;
	for (int i =0 ; i<4 ; i++)
		Equip[i]=0;
}

//Admiral
Admiral::Admiral()
{
	strncpy(Name,"NoName",16);
	Gender = true;
	Money = 10000;
	data_path="savedata.sav";
	for (int i =0 ;i<4;i++)
	{
		if (i==0)
			Ship[i] = new ShipInfo(_SHIMAKAZE);
		else
			Ship[i] = new ShipInfo(_NOSHIP);
		Ship[i]->setEquip(0,0);
		Ship[i]->setEquip(0,0);
		Ship[i]->setEquip(0,0);
		Ship[i]->setEquip(0,0);
	}
	for (int i = 0;i < 70;i++)
		EquipInventory[i] = 0;
}
Admiral::Admiral(const char* _name,bool _gender)
{
	strncpy(Name,_name,16);
	Gender = _gender;
	Money = 10000;
	data_path="savedata.sav";
	for (int i =0 ;i<4;i++)
	{
		if (i==0)
			Ship[i] = new ShipInfo(_SHIMAKAZE);
		else
			Ship[i] = new ShipInfo(_NOSHIP);
		Ship[i]->setEquip(0,0);
		Ship[i]->setEquip(0,0);
		Ship[i]->setEquip(0,0);
		Ship[i]->setEquip(0,0);
	}
	for (int i = 0;i < 70;i++)
		EquipInventory[i] = 0;
}
void Admiral::setName(const char* _name){strncpy(Name,_name,16);};
void Admiral::setGender(bool _gender){Gender = _gender;};
void Admiral::setMoney(long int _money){Money = _money;};
bool Admiral::Loading(char *_path)
{
	FILE *File;
	data_path=_path;
	File = fopen(_path,"rb");
	if (File != NULL)
	{
		fread(&savedata,sizeof(SaveData),1,File);
		fclose(File);
		strncpy(Name,savedata.Name,16);
		Gender = savedata.Gender;
		Money = savedata.Money;

		cout << "Name = " << Name << endl ;
		cout << "Gender = " << Gender << endl ;
		cout << "Money = " << Money << endl ;
		
		for (int i=0;i<4;i++)
		{
			Ship[i]->setShipType(savedata.Ship[i].ShipType);
			cout << "\tShip" << i << " = "<< Ship[i]->getShipType() << endl ;
			for (int j=0;j<4;j++)
			{
				Ship[i]->setEquip(j,savedata.Ship[i].Equip[j]);
				cout << "\t\tEquip" << j << " = "<< Ship[i]->getEquip(j) << endl ;
			}
		}
		for (int i = 0;i<70;i++)
		{
			EquipInventory[i] = savedata.EquipInventory[i];
			cout << "Equip Inventory " << i << " : " << EquipInventory[i] <<endl;
		}
		return true;
	}
	else
	{
		cout << "無存檔，請創建新檔案。" << endl;
		return false;
	}
}
void Admiral::Saving()
{
	//更新存檔值
	strncpy(savedata.Name,Name,16);
	savedata.Gender=Gender;
	savedata.Money=Money;
	for (int i = 0 ; i<4 ; i++)
	{
		if (Ship[i]->getShipType() != _NOSHIP)
		{
			savedata.Ship[i].ShipType = Ship[i]->getShipType();
			printf("Save %d Shiptype %d\n",i,Ship[i]->getShipType());
			savedata.Ship[i].Equip[0] = Ship[i]->getEquip(0);
			savedata.Ship[i].Equip[1] = Ship[i]->getEquip(1);
			savedata.Ship[i].Equip[2] = Ship[i]->getEquip(2);
			savedata.Ship[i].Equip[3] = Ship[i]->getEquip(3);
		}
		else
		{
			savedata.Ship[i].ShipType = _NOSHIP;
			savedata.Ship[i].Equip[0] = 0;
			savedata.Ship[i].Equip[1] = 0;
			savedata.Ship[i].Equip[2] = 0;
			savedata.Ship[i].Equip[3] = 0;
		}
	}
	for (int i = 0 ;i < 80;i++)
		savedata.EquipInventory[i]=EquipInventory[i];
	//存檔
	FILE *File;
	File = fopen(data_path,"wb");
	fwrite(&savedata,sizeof(SaveData),1,File);
	fclose(File);
}
unsigned long int Admiral::getMoney(){return Money;}
char* Admiral::getName(){return Name;}
bool Admiral::getGender(){return Gender;}
ShipInfo *Admiral::getShip(int _id){return Ship[_id];}
unsigned short int Admiral::getEquipInventory(int _id){return EquipInventory[_id];};
void  Admiral::addEquipInventory(int _id,short int add_num)
{
	if ((EquipInventory[_id]+add_num)!=0)
		EquipInventory[_id]+=add_num;
	else
		EquipInventory[_id]=0;
}
int Admiral::getShipNum()
{
	int count=0;
	for (int i=0;i<4;i++)
	{
		if (Ship[i]->getShipType()!=_NOSHIP)
		{
			count++;
		}
	}
	return count;
}
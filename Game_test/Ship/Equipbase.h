//基本裝備類別

#ifndef EQUIPBASE
#define EQUIPBASE

class Equipbase
{
protected:
	//裝備素質
	int Atkbonus;
	int Defbonus;
	int Spbonus;
public:
	//建構子
	Equipbase();
	//取得攻擊力加成
	int getAtkBonus();
	//取得防禦力加成
	int getDefBonus();
	//取得特殊攻擊力加成
	int getSpBonus();
};

#endif
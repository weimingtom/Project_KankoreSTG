//�򥻸˳����O

#ifndef EQUIPBASE
#define EQUIPBASE

class Equipbase
{
protected:
	//�˳Ư���
	int Atkbonus;
	int Defbonus;
	int Spbonus;
public:
	//�غc�l
	Equipbase();
	//���o�����O�[��
	int getAtkBonus();
	//���o���m�O�[��
	int getDefBonus();
	//���o�S������O�[��
	int getSpBonus();
};

#endif
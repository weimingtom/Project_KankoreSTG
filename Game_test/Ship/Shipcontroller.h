//ĥ���t�C������O

#include "Myship.h"
#include "Enemyship.h"
#include "Generalbullet.h"
#include "Specialattackbullet.h"
#include "Enemygeneralbullet.h"

#ifndef SHIPCONTROLLER
#define SHIPCONTROLLER

class Shipcontroller
{
private:
	static Myship* playerShip;
	static Enemyship** enemyShips;
	static int enemyshipNum;
public:
	//�غc�}�C
	void static createInitial();
	//���aĥ���n�O
	void static registerMyShip(Myship*);
	//���aĥ���Ѱ�
	void static unregisterMyShip();
	//�T�w�ڤ�O�_�s�b
	bool static getMyShipState();
	//�Ĥ�ĥ���n�O
	int static registerEnemyShip(Enemyship*);
	//�Ĥ�ĥ���Ѱ�
	void static unregisterEnemyShip(int);
	//���o�Ĥ�ĥ���Ӽ�
	int static getEnemyShipNum();
	//�R���j�󭭬ɥ~��ĥ��
	void static releaseBound();
	
	//�p���k
	void static frameShip();
	//�e�Ϥ�k
	void static renderShip();
	//���J��k
	void static loadShip();
	//�R��
	void static deleteShip();
};

#endif
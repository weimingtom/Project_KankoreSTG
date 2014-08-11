//艦艇系列控制器類別

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
	//建構陣列
	void static createInitial();
	//玩家艦艇登記
	void static registerMyShip(Myship*);
	//玩家艦艇解除
	void static unregisterMyShip();
	//確定我方是否存在
	bool static getMyShipState();
	//敵方艦艇登記
	int static registerEnemyShip(Enemyship*);
	//敵方艦艇解除
	void static unregisterEnemyShip(int);
	//取得敵方艦艇個數
	int static getEnemyShipNum();
	//刪除大於限界外的艦艇
	void static releaseBound();
	
	//計算方法
	void static frameShip();
	//畫圖方法
	void static renderShip();
	//載入方法
	void static loadShip();
	//刪除
	void static deleteShip();
};

#endif
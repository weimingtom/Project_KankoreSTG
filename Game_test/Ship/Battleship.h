//戰艦類別--繼承我方艦種類別

#include "Shipcontroller.h"

#ifndef BATTLESHIP
#define BATTLESHIP

class Battleship : public Myship
{
private:
public:
	Battleship();

	//實作方法
	//特殊攻擊
	void spAttack();
	//開火
	void fire();

	//需要實作
	//設置圖片和聲音
	virtual void setimgsnd();
};

#endif
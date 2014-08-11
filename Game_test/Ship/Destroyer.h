//驅逐艦類別--繼承我方艦種類別

#include "Shipcontroller.h"

#ifndef DESTROYER
#define DESTROYER

class Destroyer : public Myship
{
private:
public:
	Destroyer();

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
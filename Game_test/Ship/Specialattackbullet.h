//特殊砲彈類別--繼承子彈基礎類別

#include "Bullet.h"

#ifndef SPECIALATTACKBULLET
#define SPECIALATTACKBULLET

class Specialattackbullet : public Bullet
{
private:
public:
	//建構子
	Specialattackbullet();

	//實作方法
	//設置圖片和聲音
	void setimgsnd();
	//移動
	void move();
};

#endif
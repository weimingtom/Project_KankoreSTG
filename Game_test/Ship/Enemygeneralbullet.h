//敵人一般砲彈類別--繼承子彈基礎類別

#include "Bullet.h"

#ifndef ENEMYGENRTALBULLET
#define ENEMYGENRTALBULLET

class Enemygeneralbullet : public Bullet
{
private:
public:
	//建構子
	Enemygeneralbullet();

	//實作方法
	//設置圖片和聲音
	void setimgsnd();
	//移動
	void move();
};

#endif
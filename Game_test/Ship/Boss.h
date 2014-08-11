//魔王敵艦類別--繼承敵艦類別

#include "Shipcontroller.h"

#ifndef BOSS
#define BOSS

class Boss : public Enemyship
{
private:
public:
	//建構子
	Boss();
	Boss(float, float, float, float, float, float, int);

	//實作方法
	//移動
	void move();
	//設置圖片和聲音
	void setimgsnd();
	//受傷
	void damage(int);
	//開火
	void fire();
	//畫圖
	void Render();
};

#endif
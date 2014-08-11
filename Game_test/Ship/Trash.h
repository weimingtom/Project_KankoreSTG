//雜魚敵艦類別--繼承敵艦類別

#include "Shipcontroller.h"

#ifndef TRASH
#define TRASH

class Trash : public Enemyship
{
private:
public:
	//建構子
	Trash();
	Trash(float, float, float, float, float, float, int);

	//實作方法
	//畫圖
	void Render();

	//需要實作
	//移動
	virtual void move();
	//設置圖片和聲音
	virtual void setimgsnd();
	//受傷
	virtual void damage(int);
	//開火
	virtual void fire();
};

#endif
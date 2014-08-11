//敵艦類別--繼承艦種類別

#include "Warship.h"

#ifndef ENEMYSHIP
#define ENEMYSHIP

class Enemyship : public Warship
{
protected :
	//移動參數
	float r;
	float angle;
	float rm;
	float anglem;
	//註冊號碼
	int RegNum;
	//倍率參數
	float ScaleNum;
public:
	//建構子
	Enemyship();
	Enemyship(int);
	//新增敵艦
	void newEne();
	void newEne(float, float, float, float, float, float);
	//設置敵艦位置
	void setship();
	//被破壞
	void destroy();

	//需要實作
	//移動
	virtual void move();
	//設置圖片和聲音
	virtual void setimgsnd();
	//受傷
	virtual void damage(int);
	//開火
	virtual void fire();
	//畫圖
	virtual void Render();
};

#endif
//艦種基礎類別

#include "Bullet.h"

#ifndef WARSHIP
#define WARSHIP

class Warship
{
protected:
	//子彈冷卻間隔
	int countBulMax;
	//碰撞偵測
	hgeRect shipRect;
	//渲染相關
	hgeSprite* ship;
	//自身座標
	float x;
	float y;
	//子彈指標
	Bullet* bull;
	//子彈計數
	int bullCount;
	//子彈冷卻計數
	int countBul;
	//遊戲參數
	int HP;
	int Atk;
	int Def;
	//聲音
	HEFFECT snd;
public:
	//建構子
	Warship();
	//發出聲音
	void boom();
	//取得現在子彈計數
	int getCount();
	//偵測碰撞
	void RectDetect(Warship*);
	//取得自身邊界
	hgeRect* getRect();
	//判斷自身有無超出邊界
	bool insideDetect();

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
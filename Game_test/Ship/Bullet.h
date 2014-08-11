//子彈基礎類別

#include "Front.h"
#include "Math.h"

#ifndef BULLET
#define BULLET

class Bullet
{
protected:
	//碰撞偵測
	hgeRect buttRect;
	//渲染相關
	hgeSprite* butt;
	//本身座標
	float x;
	float y;
	//移動參數
	float r;
	float angle;
	float rm;
	float anglem;
	//自動與否(現在沒用到)
	bool autoBul;
	//聲音
	HEFFECT snd;
public:
	//建構子
	Bullet();
	Bullet(bool);
	//設置子彈位置
	void setbutt();
	//偵測碰撞特定物件
	bool detect(hgeRect*);
	//產生新子彈
	void newBul();
	//void newBul(int,hgeQuad*);
	//void newBul(int,float,float);
	//void newBul(int,int,float,float);
	//void newBul(hgeQuad);
	void newBul(float, float, float, float, float, float);
	//發出聲音
	void boom();
	//釋放資源
	void freeEffect();
	//變更模式(現在沒用到)
	void InverAuto();
	//畫圖
	void Render();

	//需要實作
	//設置圖片和聲音
	virtual void setimgsnd();
	//移動
	virtual void move();

};

#endif
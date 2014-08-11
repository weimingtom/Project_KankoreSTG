//我方艦類別--繼承艦種類別

#include "Warship.h"

#ifndef MYSHIP
#define MYSHIP

class Myship : public Warship
{
protected:
	//特殊子彈冷卻間隔
	int spcountBulMax;
	//特殊子彈指標
	Bullet* spBul;
	//特殊子彈計數
	int spCount;
	//特殊子彈冷卻
	int spCountBul;
	//腳色移動參數
	float dx;
	float dy;
	//移動速度
	int speed;
	//移動上限
	int speedMax;
	//能力參數
	int spAtk;
public:
	//建構子
	Myship();
	//取得特殊計數
	int getspCount();
	//特殊子彈偵測
	void spDetect(Warship*);
	//取得按鍵值
	void getKeyValue();

	//實作方法
	//移動
	void move();
	//受傷
	void damage(int);
	//畫圖
	void Render();
	//加入裝備
	void setEquipData(int,int,int,int);

	//需要實作
	//設置圖片和聲音
	virtual void setimgsnd();
	//特殊攻擊
	virtual void spAttack();
	//開火
	void fire();
};

#endif
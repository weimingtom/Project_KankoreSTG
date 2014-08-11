//DDH類別--繼承雜魚敵艦類別

#include "Trash.h"

#ifndef DDHDEF
#define DDHDEF

class DDH : public Trash
{
private:
	//左右
	bool Direct;
public:
	//建構子
	DDH(float, float, float, float, float, float, int, bool);

	//實作方法
	//移動
	void move();
	//設置圖片和聲音
	void setimgsnd();
	//受傷
	void damage(int);
	//開火
	void fire();
};

#endif
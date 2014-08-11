//BS類別--繼承雜魚敵艦類別

#include "Trash.h"

#ifndef BSDEF
#define BSDEF

class BS : public Trash
{
private:
public:
	//建構子
	BS(float, float, float, float, float, float, int);

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
//島風類別--繼承驅逐艦類別

#include "Destroyer.h"

#ifndef SHIMAKAZE
#define SHIMAKAZE

class Shimakaze : public Destroyer
{
private:
public:
	Shimakaze();

	//實作方法
	//設置圖片和聲音
	void setimgsnd();
};

#endif
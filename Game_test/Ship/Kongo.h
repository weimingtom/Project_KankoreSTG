//金剛類別--繼承戰艦類別

#include "Battleship.h"

#ifndef KONGO
#define KONGO

class Kongo : public Battleship
{
private:
public:
	Kongo();

	//實作方法
	//設置圖片和聲音
	void setimgsnd();
};

#endif
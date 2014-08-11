//阿賀野類別--繼承巡洋艦類別

#include "Cruiser.h"

#ifndef AGANO
#define AGANO

class Agano : public Cruiser
{
private:
public:
	Agano();

	//實作方法
	//設置圖片和聲音
	void setimgsnd();
};

#endif
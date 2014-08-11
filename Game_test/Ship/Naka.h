//那珂類別--繼承巡洋艦類別

#include "Cruiser.h"

#ifndef NAKA
#define NAKA

class Naka : public Cruiser
{
private:
public:
	Naka();

	//實作方法
	//設置圖片和聲音
	void setimgsnd();
};

#endif
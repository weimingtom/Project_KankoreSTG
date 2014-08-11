//阿賀野類別實作

#include "Agano.h"

Agano::Agano()
{
	Atk = 4;
	Def = 2;
	spAtk = 8;

	speed = 200;
	speedMax = 60;

	countBulMax = 8;
	spcountBulMax = 100;

	HP = 8;
}

void Agano::setimgsnd()
{
	ship->SetTexture(table->getTexture(12));
	snd=table->getSound(12);

	for (int i=0;i<bulNum;i++)
	{
		bull[i].setimgsnd();
	}
	spBul->setimgsnd();
}
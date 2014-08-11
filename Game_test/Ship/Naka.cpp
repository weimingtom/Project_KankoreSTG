//那珂類別實作

#include "Naka.h"

Naka::Naka()
{
	Atk = 3;
	Def = 1;
	spAtk = 12;

	speed = 200;
	speedMax = 60;

	countBulMax = 8;
	spcountBulMax = 100;

	HP = 8;
}

void Naka::setimgsnd()
{
	ship->SetTexture(table->getTexture(1));
	snd=table->getSound(1);

	for (int i=0;i<bulNum;i++)
	{
		bull[i].setimgsnd();
	}
	spBul->setimgsnd();
}
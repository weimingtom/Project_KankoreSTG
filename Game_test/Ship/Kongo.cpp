//金剛類別實作

#include "Kongo.h"

Kongo::Kongo()
{
	Atk = 7;
	Def = 5;
	spAtk = 3;

	speed = 100;
	speedMax = 30;

	countBulMax = 16;
	spcountBulMax = 200;

	HP = 15;
}

void Kongo::setimgsnd()
{
	ship->SetTexture(table->getTexture(0));
	snd=table->getSound(0);

	for (int i=0;i<bulNum;i++)
	{
		bull[i].setimgsnd();
	}
	spBul->setimgsnd();
}
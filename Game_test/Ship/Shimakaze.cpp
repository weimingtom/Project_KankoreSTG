//島風類別實作

#include "Shimakaze.h"

Shimakaze::Shimakaze()
{
	Atk = 1;
	Def = 0;
	spAtk = 10;

	speed = 300;
	speedMax = 150;

	countBulMax = 8;
	spcountBulMax = 80;

	HP = 5;
}

void Shimakaze::setimgsnd()
{
	ship->SetTexture(table->getTexture(2));
	snd=table->getSound(2);

	for (int i=0;i<bulNum;i++)
	{
		bull[i].setimgsnd();
	}
	spBul->setimgsnd();
}
//驅逐艦類別實作

#include "Destroyer.h"

Destroyer::Destroyer()
{
	spBul = new Specialattackbullet();
	spCountBul = 0;
}

void Destroyer::setimgsnd()
{
}

void Destroyer::spAttack()
{
	spBul->newBul(this->x+ship->GetWidth()/2-32,this->y+ship->GetHeight()/2-8,15,270,0,0);
	this->spCountBul++;
}

void Destroyer::fire()
{
	bullCount = (bullCount+1)%bulNum;

	bull[bullCount].newBul(this->x+ship->GetWidth()/2-32,this->y+ship->GetHeight()/2-8,15,270,0,0);
	this->countBul++;
}

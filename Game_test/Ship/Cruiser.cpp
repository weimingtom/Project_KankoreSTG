//巡洋艦類別實作

#include "Cruiser.h"

Cruiser::Cruiser()
{
	spBul = new Specialattackbullet();
	spCountBul = 0;
}

void Cruiser::setimgsnd()
{
}

void Cruiser::spAttack()
{
	spBul->newBul(this->x+ship->GetWidth()/2-32,this->y+ship->GetHeight()/2-8,15,270,0,0);
	this->spCountBul++;
}

void Cruiser::fire()
{
	bullCount = (bullCount+1)%bulNum;

	bull[bullCount].newBul(this->x+ship->GetWidth()/2-32,this->y+ship->GetHeight()/2-8,15,270,0,0);
	this->countBul++;
}

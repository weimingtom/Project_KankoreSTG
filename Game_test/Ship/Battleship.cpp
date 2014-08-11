//戰艦類別實作

#include "Battleship.h"

Battleship::Battleship()
{
	spBul = new Specialattackbullet();
	spCountBul = 0;
}

void Battleship::setimgsnd()
{
}

void Battleship::spAttack()
{
	spBul->newBul(this->x+ship->GetWidth()/2-32,this->y+ship->GetHeight()/2-8,15,270,0,0);
	this->spCountBul++;
}

void Battleship::fire()
{
	bullCount = (bullCount+1)%bulNum;
	bull[bullCount].newBul(this->x+ship->GetWidth()/2-32,this->y+ship->GetHeight()/2-8,15,230,0,0);

	bullCount = (bullCount+1)%bulNum;
	bull[bullCount].newBul(this->x+ship->GetWidth()/2-32,this->y+ship->GetHeight()/2-8,15,250,0,0);

	bullCount = (bullCount+1)%bulNum;
	bull[bullCount].newBul(this->x+ship->GetWidth()/2-32,this->y+ship->GetHeight()/2-8,15,290,0,0);

	bullCount = (bullCount+1)%bulNum;
	bull[bullCount].newBul(this->x+ship->GetWidth()/2-32,this->y+ship->GetHeight()/2-8,15,310,0,0);

	this->countBul++;
}

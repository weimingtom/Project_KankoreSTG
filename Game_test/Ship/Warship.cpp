//戰艦類別實作

#include "Warship.h"

Warship::Warship()
{
}

void Warship::setimgsnd()
{
}

void Warship::move()
{
}

void Warship::fire()
{
}

void Warship::Render()
{
}

hgeRect* Warship::getRect()
{
	return &shipRect;
}

void Warship::damage(int ATK)
{
}

void Warship::boom() {
	int pan=int((x-400)/4);
	//float pitch=(dx*dx+dy*dy)*0.0005f+0.2f;
	hge->Effect_PlayEx(snd,100,pan,1.0);
}

int Warship::getCount()
{
	return this->countBul;
}

void Warship::RectDetect(Warship* target)
{
	for (int i=0;i<bulNum;i++)
	{
		if (bull[i].detect(target->getRect()))
		{
			target->damage(this->Atk);
		}
	}
}

bool Warship::insideDetect()
{
	if (x < -500 || y < -500 || x > Width+500 || y>Height+500)
		return true;
	else
		return false;
}
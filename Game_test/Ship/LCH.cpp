//LCH類別實作

#include "LCH.h"

LCH::LCH(float newx, float newy, float newr, float newangle, float newrm, float newanglem, int Type, bool Dir) : Trash(newx,newy,newr,newangle,newrm,newanglem,Type)
{
	Atk = 2;
	Def = 1;

	HP = 15;

	countBulMax = 20;

	Direct = Dir;
}

void LCH::move()
{
	r+=rm;
	angle+=anglem;

	float xm = r*cos(angle * PI / 180.0);
	float ym = r*sin(angle * PI / 180.0);

	if (x<0 || y <0 || x>Width || y>Height)
	{
		setship();

		for (int i=0;i<bulNum;i++)
		{
			bull[i].move();
		}
	}
	else
	{
		setship();
		if (this->countBul!=0)
			this->countBul = (this->countBul+1)%(countBulMax);
		else
			fire();

		for (int i=0;i<bulNum;i++)
		{
			bull[i].move();
		}
	}
}

void LCH::setimgsnd()
{
	if (Direct)
		ship->SetTexture(table->getTexture(9));
		//ship->SetTexture(hge->Texture_Load("DDH-r.png"));
	else
		ship->SetTexture(table->getTexture(10));
		//ship->SetTexture(hge->Texture_Load("LCH-l.png"));

	for (int i=0;i<bulNum;i++)
	{
		bull[i].setimgsnd();
	}
	//snd=hge->Effect_Load("vo_n_nakani.wav");
	snd=table->getSound(9);
}

void LCH::damage(int ATK)
{
	int dif = ATK - this->Def;
	if (dif<=0)
		dif = 1;
	HP-=dif;
	if (HP<=0)
	{
		//HP=5;
		//newEne();
		//newEne(-10000,-10000,0,0,0,0);
		destroy();
		boom();
	}
}

void LCH::fire()
{
	bullCount = (bullCount+1)%bulNum;

	bull[bullCount].newBul(this->x+(ship->GetWidth())*ScaleNum/2,this->y+(ship->GetHeight())*ScaleNum/2,15,90,0,0);
	this->countBul++;
}
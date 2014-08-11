//DDH類別實作

#include "DDI.h"

DDI::DDI(float newx, float newy, float newr, float newangle, float newrm, float newanglem, int Type, bool Dir) : Trash(newx,newy,newr,newangle,newrm,newanglem,Type)
{
	Atk = 2;
	Def = 0;

	HP = 10;

	countBulMax = 20;

	Direct = Dir;
}

void DDI::move()
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

void DDI::setimgsnd()
{
	if (Direct)
		ship->SetTexture(table->getTexture(7));
		//ship->SetTexture(hge->Texture_Load("DDH-r.png"));
	else
		ship->SetTexture(table->getTexture(8));
		//ship->SetTexture(hge->Texture_Load("DDI-l.png"));

	for (int i=0;i<bulNum;i++)
	{
		bull[i].setimgsnd();
	}
	//snd=hge->Effect_Load("vo_n_nakani.wav");
	snd=table->getSound(7);
}

void DDI::damage(int ATK)
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

void DDI::fire()
{
	bullCount = (bullCount+1)%bulNum;

	bull[bullCount].newBul(this->x+(ship->GetWidth())*ScaleNum/2,this->y+(ship->GetHeight())*ScaleNum/2,15,90,0,0);
	this->countBul++;
}
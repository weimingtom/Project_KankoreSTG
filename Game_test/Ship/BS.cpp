//BS類別實作

#include "BS.h"

BS::BS(float newx, float newy, float newr, float newangle, float newrm, float newanglem, int Type) : Trash(newx,newy,newr,newangle,newrm,newanglem,Type)
{
	Atk = 3;
	Def = 1;

	HP = 30;

	countBulMax = 28;

	ship->SetTextureRect(0,0,256,256);
}

void BS::move()
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

void BS::setimgsnd()
{
	//ship->SetTexture(hge->Texture_Load("BS.png"));
	ship->SetTexture(table->getTexture(4));
	snd=table->getSound(4);
	for (int i=0;i<bulNum;i++)
	{
		bull[i].setimgsnd();
	}
	//snd=hge->Effect_Load("vo_n_nakani.wav");
}

void BS::damage(int ATK)
{
	int dif = ATK - this->Def;
	if (dif<=0)
		dif = 1;
	HP-=dif;
	if (HP<=0)
	{
		//HP=5;
		//newEne();
		destroy();
		//newEne(-10000,-10000,0,0,0,0);
		boom();
	}
}

void BS::fire()
{
	bullCount = (bullCount+1)%bulNum;
	bull[bullCount].newBul(this->x+(ship->GetWidth())*ScaleNum/4-32,this->y+(ship->GetHeight())*ScaleNum/2,15,90,0,0);

	bullCount = (bullCount+1)%bulNum;
	bull[bullCount].newBul(this->x+(ship->GetWidth())*ScaleNum*3/4-16,this->y+(ship->GetHeight())*ScaleNum/2,15,90,0,0);

	this->countBul++;
}
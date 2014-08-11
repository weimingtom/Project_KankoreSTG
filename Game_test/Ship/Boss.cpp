//魔王敵艦類別實作

#include "Boss.h"

Boss::Boss()
{
	Atk = 1;
	Def = 2;

	HP = 100;

	ScaleNum = 0.5;

	ship = new hgeSprite(0,0,0,512,512);

	countBulMax = 8;

	ship->SetBlendMode(BLEND_ALPHABLEND | BLEND_ZWRITE);
	ship->SetZ(0.5f);
	ship->SetColor(0xFFFFFFFF);


	newEne();
}

Boss::Boss(float newx, float newy, float newr, float newangle, float newrm, float newanglem, int Type) : Enemyship(Type)
{
	Atk = 1;
	Def = 2;

	ScaleNum = 0.5;

	HP = 100;

	ship = new hgeSprite(0,0,0,512,512);

	countBulMax = 8;

	ship->SetBlendMode(BLEND_ALPHABLEND | BLEND_ZWRITE);
	ship->SetZ(0.5f);
	ship->SetColor(0xFFFFFFFF);


	newEne(newx,newy,newr,newangle,newrm,newanglem);
}

void Boss::move()
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

void Boss::setimgsnd()
{
	ship->SetTexture(table->getTexture(3));
	snd=table->getSound(3);
	for (int i=0;i<bulNum;i++)
	{
		bull[i].setimgsnd();
	}
	//snd=hge->Effect_Load("vo_n_hawa.wav");

}
void Boss::damage(int ATK)
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

void Boss::fire()
{
	bullCount = (bullCount+1)%bulNum;

	bull[bullCount].newBul(this->x+(ship->GetWidth())*ScaleNum/2,this->y+(ship->GetHeight())*ScaleNum/2,15,90,0,0);
	this->countBul++;
}

void Boss::Render()
{
	ship->RenderEx(this->x,this->y,0,ScaleNum);

	for (int i=0;i<bulNum;i++)
	{
		bull[i].Render();
	}
}

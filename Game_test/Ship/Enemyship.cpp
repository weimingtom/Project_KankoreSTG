//敵艦類別實作

#include "Shipcontroller.h"

Enemyship::Enemyship()
{
	//RegNum = shipcontroller->registerEnemyShip(this);

	RegNum = Shipcontroller::registerEnemyShip(this);

	bull = new Enemygeneralbullet[bulNum];

	bullCount=0;
}

Enemyship::Enemyship(int Type)
{
	switch(Type)
	{
	default:
		bull = new Enemygeneralbullet[bulNum];
		break;
	}

	bullCount=0;

	//RegNum = shipcontroller->registerEnemyShip(this);
	RegNum = Shipcontroller::registerEnemyShip(this);

}

void Enemyship::move()
{
}

void Enemyship::setimgsnd()
{
}

void Enemyship::damage(int ATK)
{
}

void Enemyship::fire()
{
}

void Enemyship::Render()
{
}

void Enemyship::newEne()
{
	float x1,y1;
	if (rand()%2==0)
	{
		if (rand()%2==0)
		{
			x1 = (float)(rand()%720+40);
			y1 = 520.0;
		}
		else
		{
			x1 = (float)(rand()%720+40);
			y1 = 40.0;
		}
		
	}
	else
	{
		if (rand()%2==0)
		{
			x1 = 720.0;
			y1 = (float)(rand()%520+40);
		}
		else
		{
			x1 = 40.0;
			y1 = (float)(rand()%520+40);
		}
	}

	this->x = x1-36;
	this->y = y1-63;

	shipRect.x1=x+(ship->GetWidth())*ScaleNum/4;
	shipRect.y1=y+(ship->GetWidth())*ScaleNum/4;
	shipRect.x2=x+(ship->GetWidth())*ScaleNum*3/4;
	shipRect.y2=y+(ship->GetHeight())*ScaleNum*3/4;

	r=(rand()%50)/10.0 - 2.5;
	angle=0;

	rm=0;
	anglem=1.0;
}

void Enemyship::newEne(float newx, float newy, float newr, float newangle, float newrm, float newanglem)
{
	x = newx;
	y = newy;
	r = newr;
	angle = newangle;
	rm = newrm;
	anglem = newanglem;

	shipRect.x1=x+(ship->GetWidth())*ScaleNum/4;
	shipRect.y1=y+(ship->GetHeight())*ScaleNum/4;
	shipRect.x2=x+(ship->GetWidth())*ScaleNum*3/4;
	shipRect.y2=y+(ship->GetHeight())*ScaleNum*3/4;
}

void Enemyship::setship()
{
	float xm = r*cos(angle * PI / 180.0);
	float ym = r*sin(angle * PI / 180.0);

	this->x+=xm;
	this->y+=ym;

	shipRect.x1+=xm;
	shipRect.y1+=ym;
	shipRect.x2+=xm;
	shipRect.y2+=ym;
}

void Enemyship::destroy()
{
	//shipcontroller->unregisterEnemyShip(RegNum);
	Shipcontroller::unregisterEnemyShip(RegNum);
}
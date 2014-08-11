//子彈類別實作

#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(bool au)
{
	autoBul=au;

	newBul();
}

void Bullet::setimgsnd()
{
}

void Bullet::move()
{
}

void Bullet::setbutt()
{
	float xm = r*cos(angle * PI / 180.0);
	float ym = r*sin(angle * PI / 180.0);

	this->x+=xm;
	this->y+=ym;

	buttRect.x1+=xm;
	buttRect.y1+=ym;
	buttRect.x2+=xm;
	buttRect.y2+=ym;
}

bool Bullet::detect(hgeRect* target)
{
	if (buttRect.Intersect(target))
	{
		boom();

		this->x = this->x-10000;
		this->y = this->y-10000;

		buttRect.x1=this->x;
		buttRect.y1=this->y;
		buttRect.x2=this->x+16;
		buttRect.y2=this->y+16;

		r=0;
		angle=0;
		rm=0;
		anglem=0;

		return true;
	}
	else
		return false;
}

void Bullet::newBul()
{
	if (autoBul)
	{
		float x1,y1;
		if (rand()%2==0)
		{
			if (rand()%2==0)
			{
				x1 = (float)(rand()%768+16);
				y1 = 568.0;
			}
			else
			{
				x1 = (float)(rand()%768+16);
				y1 = 16.0;
			}
			
		}
		else
		{
			if (rand()%2==0)
			{
				x1 = 768.0;
				y1 = (float)(rand()%568+16);
			}
			else
			{
				x1 = 16.0;
				y1 = (float)(rand()%568+16);
			}
		}

		this->x = x1-8;
		this->y = y1-8;

		buttRect.x1=this->x;
		buttRect.y1=this->y;
		buttRect.x2=this->x+16;
		buttRect.y2=this->y+16;

		r=(rand()%50)/10.0 - 2.5;
		angle=0;

		rm=0;
		anglem=1.0;
	}
	else
	{

	}
}

/*void Bullet::newBul(int ym,hgeQuad* quad)
{

	this->x = quad->v[0].x-8;
	this->y = quad->v[0].y-8;

	buttRect.x1=this->x;
	buttRect.y1=this->y;
	buttRect.x2=this->x+16;
	buttRect.y2=this->y+16;

	xm=0;
	this->ym=ym;
}

void Bullet::newBul(int ym,float newx, float newy)
{
	this->x = newx-8;
	this->y = newy-8;

	buttRect.x1=this->x;
	buttRect.y1=this->y;
	buttRect.x2=this->x+16;
	buttRect.y2=this->y+16;

	xm=0;
	this->ym=ym;
}

void Bullet::newBul(int xm,int ym,float newx, float newy)
{
	this->x = newx-8;
	this->y = newy-8;

	buttRect.x1=this->x;
	buttRect.y1=this->y;
	buttRect.x2=this->x+16;
	buttRect.y2=this->y+16;

	this->xm=xm;
	this->ym=ym;
}*/

void Bullet::newBul(float newx, float newy, float newr, float newangle,float newrm, float newanglem)
{
	x = newx;
	y = newy;

	r = newr;
	angle = newangle;
	rm = newrm;
	anglem = newanglem;

	buttRect.x1=x;
	buttRect.y1=y;
	buttRect.x2=x+butt->GetWidth();
	buttRect.y2=y+butt->GetHeight();
}

void Bullet::freeEffect()
{
	hge->Effect_Free(snd);
}

void Bullet::boom() {
	int pan=int((x-400)/4);
	//float pitch=(dx*dx+dy*dy)*0.0005f+0.2f;
	hge->Effect_PlayEx(snd,100,pan,1.0);
}

void Bullet::InverAuto()
{
	autoBul=!autoBul;
}

void Bullet::Render()
{
	butt->Render(x,y);
}
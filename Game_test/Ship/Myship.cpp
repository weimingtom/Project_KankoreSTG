//我方艦艇類別實作

#include "Shipcontroller.h"
#include "Equipbase.h"
#include "Equipfactory.h"

Myship::Myship()
{
	ship = new hgeSprite(0,0,0,128,128);

	ship->SetBlendMode(BLEND_ALPHABLEND | BLEND_ZWRITE);
	ship->SetZ(0.5f);
	ship->SetColor(0xFFFFFFFF);

	this->x = 368.0f;
	this->y = 700.0f;

	bull = new Generalbullet[bulNum];

	bullCount=0;

	dx = 0.0f;
	dy = 0.0f;

	//shipcontroller->registerMyShip(this);
	Shipcontroller::registerMyShip(this);
}

void Myship::setimgsnd()
{
}

void Myship::spAttack()
{
}

void Myship::fire()
{
}

int Myship::getspCount()
{
	return spCountBul;
}

void Myship::spDetect(Warship* target)
{
	if (spBul->detect(target->getRect()))
	{
		target->damage(this->spAtk);
	}
}

void Myship::getKeyValue()
{
	// Get the time elapsed since last call of FrameFunc().
	// This will help us to synchronize on different
	// machines and video modes.
	float dt=hge->Timer_GetDelta();

	// Process keys
	if (hge->Input_GetKeyState(HGEK_SHIFT)) 
		speed=speedMax;
	else 
		speed=speedMax*10/3;
	if (hge->Input_GetKeyState(HGEK_LEFT))
		dx=0-speed*dt;
	else if (hge->Input_GetKeyState(HGEK_RIGHT)) 
		dx=speed*dt;
	else
		dx=0;
	if (hge->Input_GetKeyState(HGEK_UP))
		dy=0-speed*dt;
	else if (hge->Input_GetKeyState(HGEK_DOWN)) 
		dy=speed*dt;
	else 
		dy=0;
	if (hge->Input_GetKeyState(HGEK_Z))
	{
		if (getCount()==0)
		{
			fire();
		}
	}

	if (hge->Input_GetKeyState(HGEK_X))
	{
		if (getspCount()==0)
		{
			spAttack();
		}
	}
}

void Myship::move()
{
	getKeyValue();

	this->x+=dx;
	this->y+=dy;

	if(x>Width-ship->GetWidth()) {x=Width-ship->GetWidth();}
	if(x<0) {x=0;}
	if(y>Height-ship->GetHeight()) {y=Height-ship->GetHeight();}
	if(y<0) {y=0;}

	shipRect.x1 = this->x+ship->GetWidth()/4;
	shipRect.y1 = this->y+ship->GetHeight()/4;
	shipRect.x2 = this->x+ship->GetWidth()*3/4;
	shipRect.y2 = this->y+ship->GetHeight()*3/4;

	if (this->countBul!=0)
		this->countBul = (this->countBul+1)%countBulMax;

	if (this->spCountBul!=0)
		spCountBul = (spCountBul+1)%spcountBulMax;

	for (int i=0;i<bulNum;i++)
	{
		bull[i].move();
	}
	spBul->move();
}

void Myship::damage(int ATK)
{
	int Dif = ATK - this->Def;
	if (Dif<=0)
		Dif = 1;
	HP-=Dif;
	if (HP<=0)
	{
		//HP=5;
		//shipcontroller->unregisterMyShip();
		Shipcontroller::unregisterMyShip();
		boom();
	}
}

void Myship::Render()
{
	ship->Render(this->x,this->y);

	for (int i=0;i<bulNum;i++)
	{
		bull[i].Render();
	}

	spBul->Render();
}

void Myship::setEquipData(int eq1, int eq2, int eq3, int eq4)
{
	Equipbase *equip=0;

	equip = Equipfactory::createEquip(eq1);
	Atk += equip->getAtkBonus();
	Def += equip->getAtkBonus();
	spAtk += equip->getSpBonus();
	delete equip;
	equip = Equipfactory::createEquip(eq2);
	Atk += equip->getAtkBonus();
	Def += equip->getAtkBonus();
	spAtk += equip->getSpBonus();
	delete equip;
	equip = Equipfactory::createEquip(eq3);
	Atk += equip->getAtkBonus();
	Def += equip->getAtkBonus();
	spAtk += equip->getSpBonus();
	delete equip;
	equip = Equipfactory::createEquip(eq4);
	Atk += equip->getAtkBonus();
	Def += equip->getAtkBonus();
	spAtk += equip->getSpBonus();
	delete equip;
}
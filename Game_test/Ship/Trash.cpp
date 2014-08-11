//雜魚敵艦類別實作

#include "Trash.h"

Trash::Trash()
{
	HP = 5;

	ScaleNum = 1.0f;

	ship = new hgeSprite(0,0,0,128,128);

	countBulMax = 20;

	ship->SetBlendMode(BLEND_ALPHABLEND | BLEND_ZWRITE);
	ship->SetZ(0.5f);
	ship->SetColor(0xFFFFFFFF);


	newEne();
}

Trash::Trash(float newx, float newy, float newr, float newangle, float newrm, float newanglem, int Type) : Enemyship(Type)
{
	ship = new hgeSprite(0,0,0,128,128);

	ScaleNum = 1.0f;

	ship->SetBlendMode(BLEND_ALPHABLEND | BLEND_ZWRITE);
	ship->SetZ(0.5f);
	ship->SetColor(0xFFFFFFFF);


	newEne(newx,newy,newr,newangle,newrm,newanglem);
}

void Trash::move()
{
}

void Trash::setimgsnd()
{
}

void Trash::damage(int ATK)
{
}

void Trash::fire()
{
}

void Trash::Render()
{
	ship->RenderEx(this->x,this->y,0,ScaleNum);

	for (int i=0;i<bulNum;i++)
	{
		bull[i].Render();
	}
}

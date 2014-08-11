//特殊砲彈類別實作

#include "Specialattackbullet.h"

Specialattackbullet::Specialattackbullet()
{
	autoBul=false;
	butt = new hgeSprite(0,0,0,64,64);

	butt->SetBlendMode(BLEND_ALPHABLEND | BLEND_ZWRITE);
	butt->SetZ(0.5f);
	butt->SetColor(0xFFFFFFFF);
}

void Specialattackbullet::setimgsnd()
{
	butt->SetTexture(table->getTexture(13));
	snd=table->getSound(13);
}

void Specialattackbullet::move()
{
	setbutt();
}
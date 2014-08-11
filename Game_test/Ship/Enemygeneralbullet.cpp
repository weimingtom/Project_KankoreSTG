//敵人一般砲彈類別實作

#include "Enemygeneralbullet.h"

Enemygeneralbullet::Enemygeneralbullet()
{
	autoBul=false;
	butt = new hgeSprite(0,0,0,64,64);

	butt->SetBlendMode(BLEND_ALPHABLEND | BLEND_ZWRITE);
	butt->SetZ(0.5f);
	butt->SetColor(0xFFFFFFFF);
}

void Enemygeneralbullet::setimgsnd()
{
	/*butt->SetTexture(hge->Texture_Load("Actor1.png"));
	snd=hge->Effect_Load("shot.wav");*/
	butt->SetTexture(table->getTexture(14));
	snd=table->getSound(14);
}

void Enemygeneralbullet::move()
{
	setbutt();
}
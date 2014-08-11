//艦艇圖片聲音類別實作

#include "hge.h"
#include "Shiptable.h"
#include "Front.h"

Shiptable::Shiptable()
{
	shipTexture = new HTEXTURE[15];

	shipTexture[0] = hge->Texture_Load("kongo.png");
	shipTexture[1] = hge->Texture_Load("Naka-chan.png");
	shipTexture[2] = hge->Texture_Load("Shimakaze.png");
	shipTexture[3] = hge->Texture_Load("boss.png");
	shipTexture[4] = hge->Texture_Load("BS.png");
	shipTexture[5] = hge->Texture_Load("DDH-r.png");
	shipTexture[6] = hge->Texture_Load("DDH-l.png");
	shipTexture[7] = hge->Texture_Load("DDI-r.png");
	shipTexture[8] = hge->Texture_Load("DDI-l.png");
	shipTexture[9] = hge->Texture_Load("LCH-r.png");
	shipTexture[10] = hge->Texture_Load("LCH-l.png");
	shipTexture[11] = hge->Texture_Load("self-bullet.png");
	shipTexture[12] = hge->Texture_Load("Agano.png");
	shipTexture[13] = hge->Texture_Load("bomb.png");
	shipTexture[14] = hge->Texture_Load("enemy-bullet.png");

	shipEffect = new HEFFECT[15];

	shipEffect[0] = hge->Effect_Load("Kongo_destroy.mp3");
	shipEffect[1] = hge->Effect_Load("damage01.wav");
	shipEffect[2] = hge->Effect_Load("Shimakaze_destroy.mp3");
	shipEffect[3] = hge->Effect_Load("r3.wav");
	shipEffect[4] = hge->Effect_Load("bomb.wav");
	shipEffect[5] = hge->Effect_Load("bomb.wav");
	shipEffect[6] = hge->Effect_Load("bomb.wav");
	shipEffect[7] = hge->Effect_Load("bomb.wav");
	shipEffect[8] = hge->Effect_Load("bomb.wav");
	shipEffect[9] = hge->Effect_Load("bomb.wav");
	shipEffect[10] = hge->Effect_Load("bomb.wav");
	shipEffect[11] = hge->Effect_Load("gun.wav");
	shipEffect[12] = hge->Effect_Load("damage02.wav");
	shipEffect[13] = hge->Effect_Load("bomb.wav");
	shipEffect[14] = hge->Effect_Load("bazooka.wav");
}

HTEXTURE Shiptable::getTexture(int index)
{
	return shipTexture[index];
}

HEFFECT Shiptable::getSound(int index)
{
	return shipEffect[index];
}
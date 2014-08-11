//艦艇圖片、聲音列表

#ifndef SHIPTABLE
#define SHIPTABLE

class Shiptable
{
private:
	HTEXTURE* shipTexture;
	HEFFECT* shipEffect;
public:
	//建構子
	Shiptable();
	//取得圖片
	HTEXTURE getTexture(int);
	//取得聲音
	HEFFECT getSound(int);
};

#endif
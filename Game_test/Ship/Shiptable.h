//ĥ���Ϥ��B�n���C��

#ifndef SHIPTABLE
#define SHIPTABLE

class Shiptable
{
private:
	HTEXTURE* shipTexture;
	HEFFECT* shipEffect;
public:
	//�غc�l
	Shiptable();
	//���o�Ϥ�
	HTEXTURE getTexture(int);
	//���o�n��
	HEFFECT getSound(int);
};

#endif
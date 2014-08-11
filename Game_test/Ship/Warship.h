//ĥ�ذ�¦���O

#include "Bullet.h"

#ifndef WARSHIP
#define WARSHIP

class Warship
{
protected:
	//�l�u�N�o���j
	int countBulMax;
	//�I������
	hgeRect shipRect;
	//��V����
	hgeSprite* ship;
	//�ۨ��y��
	float x;
	float y;
	//�l�u����
	Bullet* bull;
	//�l�u�p��
	int bullCount;
	//�l�u�N�o�p��
	int countBul;
	//�C���Ѽ�
	int HP;
	int Atk;
	int Def;
	//�n��
	HEFFECT snd;
public:
	//�غc�l
	Warship();
	//�o�X�n��
	void boom();
	//���o�{�b�l�u�p��
	int getCount();
	//�����I��
	void RectDetect(Warship*);
	//���o�ۨ����
	hgeRect* getRect();
	//�P�_�ۨ����L�W�X���
	bool insideDetect();

	//�ݭn��@
	//����
	virtual void move();
	//�]�m�Ϥ��M�n��
	virtual void setimgsnd();
	//����
	virtual void damage(int);
	//�}��
	virtual void fire();
	//�e��
	virtual void Render();
};

#endif
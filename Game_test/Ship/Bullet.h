//�l�u��¦���O

#include "Front.h"
#include "Math.h"

#ifndef BULLET
#define BULLET

class Bullet
{
protected:
	//�I������
	hgeRect buttRect;
	//��V����
	hgeSprite* butt;
	//�����y��
	float x;
	float y;
	//���ʰѼ�
	float r;
	float angle;
	float rm;
	float anglem;
	//�۰ʻP�_(�{�b�S�Ψ�)
	bool autoBul;
	//�n��
	HEFFECT snd;
public:
	//�غc�l
	Bullet();
	Bullet(bool);
	//�]�m�l�u��m
	void setbutt();
	//�����I���S�w����
	bool detect(hgeRect*);
	//���ͷs�l�u
	void newBul();
	//void newBul(int,hgeQuad*);
	//void newBul(int,float,float);
	//void newBul(int,int,float,float);
	//void newBul(hgeQuad);
	void newBul(float, float, float, float, float, float);
	//�o�X�n��
	void boom();
	//����귽
	void freeEffect();
	//�ܧ�Ҧ�(�{�b�S�Ψ�)
	void InverAuto();
	//�e��
	void Render();

	//�ݭn��@
	//�]�m�Ϥ��M�n��
	virtual void setimgsnd();
	//����
	virtual void move();

};

#endif
//��ĥ���O--�~��ĥ�����O

#include "Warship.h"

#ifndef ENEMYSHIP
#define ENEMYSHIP

class Enemyship : public Warship
{
protected :
	//���ʰѼ�
	float r;
	float angle;
	float rm;
	float anglem;
	//���U���X
	int RegNum;
	//���v�Ѽ�
	float ScaleNum;
public:
	//�غc�l
	Enemyship();
	Enemyship(int);
	//�s�W��ĥ
	void newEne();
	void newEne(float, float, float, float, float, float);
	//�]�m��ĥ��m
	void setship();
	//�Q�}�a
	void destroy();

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
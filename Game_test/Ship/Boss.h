//�]����ĥ���O--�~�Ӽ�ĥ���O

#include "Shipcontroller.h"

#ifndef BOSS
#define BOSS

class Boss : public Enemyship
{
private:
public:
	//�غc�l
	Boss();
	Boss(float, float, float, float, float, float, int);

	//��@��k
	//����
	void move();
	//�]�m�Ϥ��M�n��
	void setimgsnd();
	//����
	void damage(int);
	//�}��
	void fire();
	//�e��
	void Render();
};

#endif
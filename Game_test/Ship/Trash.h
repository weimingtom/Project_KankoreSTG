//������ĥ���O--�~�Ӽ�ĥ���O

#include "Shipcontroller.h"

#ifndef TRASH
#define TRASH

class Trash : public Enemyship
{
private:
public:
	//�غc�l
	Trash();
	Trash(float, float, float, float, float, float, int);

	//��@��k
	//�e��
	void Render();

	//�ݭn��@
	//����
	virtual void move();
	//�]�m�Ϥ��M�n��
	virtual void setimgsnd();
	//����
	virtual void damage(int);
	//�}��
	virtual void fire();
};

#endif
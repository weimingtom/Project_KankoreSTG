//�ڤ�ĥ���O--�~��ĥ�����O

#include "Warship.h"

#ifndef MYSHIP
#define MYSHIP

class Myship : public Warship
{
protected:
	//�S��l�u�N�o���j
	int spcountBulMax;
	//�S��l�u����
	Bullet* spBul;
	//�S��l�u�p��
	int spCount;
	//�S��l�u�N�o
	int spCountBul;
	//�}�Ⲿ�ʰѼ�
	float dx;
	float dy;
	//���ʳt��
	int speed;
	//���ʤW��
	int speedMax;
	//��O�Ѽ�
	int spAtk;
public:
	//�غc�l
	Myship();
	//���o�S��p��
	int getspCount();
	//�S��l�u����
	void spDetect(Warship*);
	//���o�����
	void getKeyValue();

	//��@��k
	//����
	void move();
	//����
	void damage(int);
	//�e��
	void Render();
	//�[�J�˳�
	void setEquipData(int,int,int,int);

	//�ݭn��@
	//�]�m�Ϥ��M�n��
	virtual void setimgsnd();
	//�S�����
	virtual void spAttack();
	//�}��
	void fire();
};

#endif
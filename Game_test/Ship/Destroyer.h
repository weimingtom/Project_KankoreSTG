//�X�vĥ���O--�~�ӧڤ�ĥ�����O

#include "Shipcontroller.h"

#ifndef DESTROYER
#define DESTROYER

class Destroyer : public Myship
{
private:
public:
	Destroyer();

	//��@��k
	//�S�����
	void spAttack();
	//�}��
	void fire();

	//�ݭn��@
	//�]�m�Ϥ��M�n��
	virtual void setimgsnd();
};

#endif
//���vĥ���O--�~�ӧڤ�ĥ�����O

#include "Shipcontroller.h"

#ifndef CRUISER
#define CRUISER

class Cruiser : public Myship
{
private:
public:
	Cruiser();

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
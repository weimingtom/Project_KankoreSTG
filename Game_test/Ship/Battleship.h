//��ĥ���O--�~�ӧڤ�ĥ�����O

#include "Shipcontroller.h"

#ifndef BATTLESHIP
#define BATTLESHIP

class Battleship : public Myship
{
private:
public:
	Battleship();

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
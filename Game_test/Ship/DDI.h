//DDI���O--�~��������ĥ���O

#include "Trash.h"

#ifndef DDIDEF
#define DDIDEF

class DDI : public Trash
{
private:
	//���k
	bool Direct;
public:
	//�غc�l
	DDI(float, float, float, float, float, float, int, bool);

	//��@��k
	//����
	void move();
	//�]�m�Ϥ��M�n��
	void setimgsnd();
	//����
	void damage(int);
	//�}��
	void fire();
};

#endif
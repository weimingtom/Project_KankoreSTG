//LCH���O--�~��������ĥ���O

#include "Trash.h"

#ifndef LCHDEF
#define LCHDEF

class LCH : public Trash
{
private:
	//���k
	bool Direct;
public:
	//�غc�l
	LCH(float, float, float, float, float, float, int, bool);

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
//BS���O--�~��������ĥ���O

#include "Trash.h"

#ifndef BSDEF
#define BSDEF

class BS : public Trash
{
private:
public:
	//�غc�l
	BS(float, float, float, float, float, float, int);

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
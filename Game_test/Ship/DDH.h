//DDH���O--�~��������ĥ���O

#include "Trash.h"

#ifndef DDHDEF
#define DDHDEF

class DDH : public Trash
{
private:
	//���k
	bool Direct;
public:
	//�غc�l
	DDH(float, float, float, float, float, float, int, bool);

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
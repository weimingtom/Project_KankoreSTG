#ifndef DIALOGHELPER_H
#define DIALOGHELPER_H
#include "hge.h"
#include "hgegui.h"
#include ".\GfxFont.h"
#include "hgesprite.h"
#include <hgestrings.h>
#include <stdio.h>



class Dialoghelper : public hgeGUIObject
{
public:
	//�غc���
	Dialoghelper(int _id,float _x,float _y,float _w,float _h,GfxFont* Fnt,HTEXTURE BgTex=0);
	//�ù���V�A��m�b��V�D�{�ǤU
	virtual void Render();
	//�C�V��s��ơA��m�b�V��ƥD�{�ǤU
	virtual void Update(float  fDeltaTime);
	//��������AUpdate�����եι�@
	virtual bool KeyClick(int key, int chr);
	//�ؼд�V�A�ΥH�T�w���z�ϰ�j�p�A�����եι�@
	virtual void RenderTarget();
	//�]�m�奻
	virtual void SetStringtable(hgeStringTable *_hst);
	//�վ�奻��m
	virtual void AdjustWordPos(float x,float y);
	//�]�m��ܼҦ�1���v�r�A2���T�w
	virtual void SetMode(bool _mode);
	//����{�b�Ҧ�
	virtual bool GetMode();
	//�ƹ��I��
	virtual bool MouseLButton(bool bDown);
	//�i�J�ʵe
	virtual void Enter();

protected:
	hgeSprite		*tar;	//��ܥκ��F
	hgeStringTable	*hst;
	char *str;
	hgeQuad			BG;		//�I�����z���c
	HTARGET			target;	//��ܰϰ�j�p
	GfxFont*		fnt;	//�����r���z
	float			timer;
	float			timeSpeed;
	int				xNum,strId;
	bool			Mode;
	float			width;
	float			height;
	float			adj_x;
	float			adj_y;
	char			stringName[10];//�奻�Ǹ���
};
#endif
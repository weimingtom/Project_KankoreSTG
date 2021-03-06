#include "Dialoghelper.h"

//建構子
Dialoghelper::Dialoghelper(int _id,float _x,float _y,float _w,float _h,GfxFont* Fnt,HTEXTURE BgTex)
{
	//hgeGUIObject必要變數設置
	id=_id;
	//hge=hgeCreate(HGE_VERSION);
	bStatic=false;
	bVisible=true;
	bEnabled=true;
	rect.Set(_x,_y,_x+_w,_y+_h);
	//自定義變數設置
	hst=NULL;
	width=_w;
	height=_h;
	fnt=Fnt;
	timeSpeed=0.1f;
	strId=1;
	xNum=0;
	sprintf(stringName,"%s%d","talk",strId);
	Mode=true;
	str="";
	target=hge->Target_Create(width+1,height+1,false);
	tar=new hgeSprite(hge->Target_GetTexture(target),0,0,width,height);
	tar->SetBlendMode(BLEND_ALPHABLEND | BLEND_ZWRITE);
	adj_x=10;
	adj_y=10;
	//背景紋理貼圖
	BG.tex=BgTex;
	if (BgTex!=0)
	{
		BG.blend=BLEND_ALPHABLEND | BLEND_ZWRITE;
		//設置紋理貼圖區域，指定整個TARGET渲染區域
		BG.v[0].x=0;  BG.v[0].y=0;
		BG.v[1].x=width;  BG.v[1].y=0;
		BG.v[2].x=width;  BG.v[2].y=height;
		BG.v[3].x=0;  BG.v[3].y=height;
		//設置圖片像素範圍，填滿渲染
		float Full_Parameter[2];
		Full_Parameter[0]=(float)width/hge->Texture_GetWidth(BG.tex);
		Full_Parameter[1]=(float)height/hge->Texture_GetHeight(BG.tex);

		BG.v[0].tx=0;					BG.v[0].ty=0;
		BG.v[1].tx=Full_Parameter[0];	BG.v[1].ty=0;
		BG.v[2].tx=Full_Parameter[0];	BG.v[2].ty=Full_Parameter[1];
		BG.v[3].tx=0;					BG.v[3].ty=Full_Parameter[1];
		//設置圖片透明度
		for (int i=0;i<4;i++)
		{
			BG.v[i].z=0.0f;
			BG.v[i].col=0xFFFFFFFF;
		}
	}
}

//對話框遞進
void Dialoghelper::Update(float fDeltaTime)
{
	if (hst!=NULL && Mode)
	{
		if (strId==1)
			gui->ShowCtrl(id,true);
		if(xNum < strlen(str)/2+5 && fDeltaTime - timer > timeSpeed){
			timer= fDeltaTime ;
			xNum+=1;
		}
		else if (fDeltaTime - timer > timeSpeed && timeSpeed>=0.1f)
		{
			timer = fDeltaTime ;
		}
	}
	RenderTarget();
}

//按鍵偵測
bool Dialoghelper::KeyClick(int key, int chr)
{
	if (hst!=NULL && Mode)
	{
		if (key==HGEK_CTRL || HGEK_SPACE)
		{
			if(xNum>=strlen(str)/2+5)
			{
				strId+=1;
				sprintf(stringName,"%s%d","talk",strId);
				if (NULL!=hst->GetString(stringName))
				{
					str=hst->GetString(stringName);
				}
				else
				{
					str="";
					gui->ShowCtrl(id,false);
				}
				xNum=0;
				timeSpeed=0.1f;
			}
			else timeSpeed=0.01f;
		}
	}
	return false;
}
void Dialoghelper::Render()
{
	tar->Render(rect.x1,rect.y1);
}
void Dialoghelper::RenderTarget()
{
	
	hge->Gfx_BeginScene(target);
	hge->Gfx_Clear(0);
	if (BG.tex!=0)
		hge->Gfx_RenderQuad(&BG);
	if (Mode)
	{
		fnt->PrintEx(adj_x,adj_y,xNum,str);
	}
	else
	{
		fnt->Print(adj_x,adj_y,str);
	}
	hge->Gfx_EndScene();
}
void Dialoghelper::SetStringtable(hgeStringTable *_hst)
{
	hst=_hst;
	str=hst->GetString("talk1");
	timeSpeed=0.1f;
	strId=1;
	xNum=0;
}
void Dialoghelper::SetMode(bool _mode)
{
	Mode=_mode;
}
bool Dialoghelper::GetMode()
{
	return Mode;
}
void Dialoghelper::AdjustWordPos(float x,float y)
{
	adj_x=x;
	adj_y=y;
}
bool Dialoghelper::MouseLButton(bool bDown)
{
	KeyClick(HGEK_SPACE,' ');
	return 1;
}
void Dialoghelper::Enter(){};
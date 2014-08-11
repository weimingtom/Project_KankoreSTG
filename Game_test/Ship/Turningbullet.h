//轉彎砲彈類別--繼承子彈基礎類別

class Generalbullet : public Bullet
{
private:
public:
	//建構子
	Generalbullet();

	//實作方法
	//設置圖片和聲音
	void setimgsnd();
	//移動
	void move();
};
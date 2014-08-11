//艦艇系列控制器類別實作

#include "Shipcontroller.h"

Myship* Shipcontroller::playerShip = 0;
Enemyship** Shipcontroller::enemyShips = 0;
int Shipcontroller::enemyshipNum = 0;

void Shipcontroller::createInitial()
{
	enemyShips = new Enemyship*[enemyMaxNum];
	for (int i = 0;i < enemyMaxNum;i++)
	{
		enemyShips[i] = 0;
	}
	enemyshipNum=0;
}

void Shipcontroller::registerMyShip(Myship* newMyShip)
{
	playerShip = newMyShip;
}

void Shipcontroller::unregisterMyShip()
{
	playerShip = 0;
}

bool Shipcontroller::getMyShipState()
{
	if (playerShip == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Shipcontroller::registerEnemyShip(Enemyship* newEnemyShip)
{
	if (enemyShips == 0)
		createInitial();

	for (int i = 0;i < enemyMaxNum;i++)
	{
		if (enemyShips[i]==0)
		{
			enemyShips[i] = newEnemyShip;
			enemyshipNum++;
			return i;
		}
	}

	return -1;
}

void Shipcontroller::unregisterEnemyShip(int i)
{
	enemyShips[i] = 0;
}

int Shipcontroller::getEnemyShipNum()
{
	return enemyshipNum;
}

void Shipcontroller::releaseBound()
{
	for (int i = 0;i < enemyMaxNum;i++)
	{
		if (enemyShips[i] != 0)
		{
			if (enemyShips[i]->insideDetect())
			{
				enemyShips[i]->destroy();
			}
		}
	}
}

void Shipcontroller::frameShip()
{
	if (playerShip != 0)
		playerShip->move();

	for (int i = 0;i < enemyMaxNum;i++)
	{
		if (enemyShips[i] != 0)
		{
			enemyShips[i]->move();		
		}
		if (enemyShips[i] != 0 && playerShip!=0)
		{
			playerShip->RectDetect(enemyShips[i]);
		}
		if (enemyShips[i] != 0 && playerShip!=0)
		{
			playerShip->spDetect(enemyShips[i]);
		}
		if (enemyShips[i] != 0 && playerShip!=0)
		{
			enemyShips[i]->RectDetect(playerShip);
		}
	}

	releaseBound();
}

void Shipcontroller::renderShip()
{
	if (playerShip != 0)
		playerShip->Render();

	for (int i = 0;i < enemyMaxNum;i++)
	{
		if (enemyShips[i] != 0)
		{
			enemyShips[i]->Render();
		}
	}
}

void Shipcontroller::loadShip()
{
	if (enemyShips == 0)
		createInitial();

	if (playerShip != 0)
		playerShip->setimgsnd();

	for (int i = 0;i < enemyMaxNum;i++)
	{
		if (enemyShips[i] != 0)
		{
			enemyShips[i]->setimgsnd();
		}
	}
}

void Shipcontroller::deleteShip()
{
	delete playerShip;
	delete enemyShips;

	playerShip = 0;
	enemyShips = 0;
}
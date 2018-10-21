#include "stdafx.h"
#include "Boss.h"


HRESULT Boss::init()
{

	img = IMAGEMANAGER->findImage("Boss");
	arrayY = 6;
	arrayX = 7;
	x = TILEMANAGER->GetTileList("x")[arrayY][arrayX].GetTileRect().left;
	y = TILEMANAGER->GetTileList("x")[arrayY][arrayX].GetTileRect().top;

	b = new BulletManager;
	b->init("effect3", "Bomb3", 100);

	alpha = 255;
	
	isMoving = false;
	isMoving2 = false;
	updateMoveCount = 0;
	moveCount = rand() % 1000 + 300;

	updateAttackCount = 0;
	attackCount = rand() % 700 + 200;
	hp = 40;

	isDamaged = false;
	damagedCount = 0;
	isDead = false;

	hpBar = new progressBar;
	hpBar->init(-100, -100);
	return S_OK;
}

void Boss::update()
{
	cheat();
	if (isDamaged == false)
	{
		if (  TILEMANAGER->GetTileList("w")[arrayY][arrayX].GetTileState() == BOOM ||
			TILEMANAGER->GetTileList("w")[arrayY-1][arrayX].GetTileState() == BOOM || 
			TILEMANAGER->GetTileList("w")[arrayY+1][arrayX].GetTileState() == BOOM || 
			TILEMANAGER->GetTileList("w")[arrayY][arrayX-1].GetTileState() == BOOM ||
			TILEMANAGER->GetTileList("w")[arrayY][arrayX+1].GetTileState() == BOOM )
		{
			isDamaged = true;
			hp -= 1;
		}
	}
	if (isDamaged == true)
	{
		damagedCount++;
		if (damagedCount > 20)
		{
			isDamaged = false;
			damagedCount = 0;
		}
	}
	move();
	attack();
	b->update();
	hpBar->update(x-35, y-300);
	hpBar->setGauge(hp, 40);
	if (hp <= 0)
		isDead = true;
}
void Boss::cheat()
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		hp -= 15;
	}
}
void  Boss::attack()
{
	updateAttackCount++;
	if (hp < 15)
	{
		if (updateAttackCount % 20 == 0)
		{
			int tempX = rand() % 13 + 1;
			int tempY = rand() % 8 + 1;
			b->setBomb(tempY, tempX);
		}
		return;
	}
	if (updateAttackCount > attackCount)
	{
		int num = rand() % 3;
		switch (num)
		{
		case 0:
			attack1();
			break;
		case 1:
			attack2();
			break;
		case 2:
			attack3();
			break;
		}
		updateAttackCount = 0;
		attackCount = rand() % 700 + 200;
	}
}
void Boss::attack1()
{
	for (int i = 0; i < 10; i++)
	{
		int tempX = rand()%13 + 1;
		int tempY = rand() % 8 + 1;
		b->setBomb(tempY, tempX);
	}
}
void Boss::attack2()
{
	for (int i = 1; i < 14; i+=2)
	{
		b->setBomb(5, i);
	}
	for (int i = 1; i < 9; i+=2)
	{
		b->setBomb(i, 7);
	}
}
void Boss::attack3()
{
	for (int i = 1; i < 9; i+=2)
	{
		b->setBomb(i, 3);
		b->setBomb(i, 7);
		b->setBomb(i, 11);
	}
}

void Boss::move()
{
	updateMoveCount++;
	if (updateMoveCount > moveCount)
	{
		moveX = rand() % 10 + 3;
		moveY = rand() % 7 + 3;
		isMoving = true;
		moveCount = rand() % 700 + 100;
		updateMoveCount = 0;
	}
	if (isMoving == true)
	{
		alpha-=5;
		if (alpha < 0)
		{
			arrayY = moveY;
			arrayX = moveX;
			x = TILEMANAGER->GetTileList("x")[arrayY][arrayX].GetTileRect().left;
			y = TILEMANAGER->GetTileList("x")[arrayY][arrayX].GetTileRect().top;
			isMoving = false;
			isMoving2 = true;
		}
	}
	if (isMoving2 == true)
	{
		alpha += 5;
		if (alpha > 255)
		{
			alpha = 255;
			isMoving2 = false;
		}
	}
}

void Boss::render()
{
	img->alphaRender(getMemDC(),x - 60,y  -250,alpha);
	hpBar->render();
	if(KEYMANAGER->isToggleKey(VK_F1))
		Rectangle(getMemDC(), x, y, x + 64, y + 64);
}

void Boss::release()
{

}

Boss::Boss()
{
}


Boss::~Boss()
{

}

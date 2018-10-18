#include "stdafx.h"
#include "Boss.h"


HRESULT Boss::init()
{

	img = IMAGEMANAGER->findImage("Boss");
	arrayY = 2;
	arrayX = 5;
	x = TILEMANAGER->GetTileList("x")[arrayY][arrayX].GetTileRect().left;
	y = TILEMANAGER->GetTileList("x")[arrayY][arrayX].GetTileRect().top;

	b = new BulletManager;
	b->init("Boom2", "Bub2", 100);

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
	return S_OK;
}

void Boss::update()
{
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
}

void  Boss::attack()
{
	updateAttackCount++;
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
	for (int i = 0; i < 20; i++)
	{
		int tempX = rand()%13 + 1;
		int tempY = rand() % 8 + 1;
		b->setBomb(tempY, tempX);
	}
}
void Boss::attack2()
{
	for (int i = 1; i < 14; i++)
	{
		b->setBomb(5, i);
	}
	for (int i = 1; i < 9; i++)
	{
		b->setBomb(i, 7);
	}
}
void Boss::attack3()
{
	for (int i = 1; i < 9; i++)
	{
		b->setBomb(i, 2);
		b->setBomb(i, 5);
		b->setBomb(i, 8);
	}
}

void Boss::move()
{
	updateMoveCount++;
	if (updateMoveCount > moveCount)
	{
		moveX = rand() % 12 + 2;
		moveY = rand() % 7 + 2;
		isMoving = true;
		moveCount = rand() % 1000 + 300;
		updateMoveCount = 0;
	}
	if (isMoving == true)
	{
		alpha-=3;
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
		alpha += 3;
		if (alpha > 255)
		{
			alpha = 255;
			isMoving2 = false;
		}
	}
}

void Boss::render()
{
	img->alphaRender(getMemDC(),x-100,y-126,alpha);
	char str[128];
	sprintf(str, "hp : %d  x:%d  y:%d", hp,arrayX,arrayY);
	TextOut(getMemDC(), 10, 400, str, strlen(str));
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

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
	b->init("Boom2", "Bub2", 100);

	alpha = 255;
	
	isMoving = false;
	isMoving2 = false;
	updateMoveCount = 0;
	moveCount = rand() % 300 + 300;

	updateAttackCount = 0;
	attackCount = rand() % 300 + 300;
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
void Boss::cheat() //치트키
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		hp -= 15;
	}
}
void  Boss::attack()
{
	updateAttackCount++;

	if (hp < 15) //(발악 패턴)초당 3번 랜덤한 타일에 폭탄 설치
	{
		if (updateAttackCount % 20 == 0)
		{
			int tempX = rand() % 13 + 1;
			int tempY = rand() % 8 + 1;
			b->setBomb(tempY, tempX);
		}

		return;
	}

	if (updateAttackCount > attackCount) //시간이 지나면 랜덤 패턴
	{
		int num = rand() % 4;

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

		case 3:
			attack4();
			break;
		}
		updateAttackCount = 0;
		attackCount = rand() % 300 + 300;
	}
}
void Boss::attack1() //패턴1 (랜덤한 좌표 소환)
{
	for (int i = 0; i < 14; i++)
	{
		int tempX = rand() % 13 + 1;
		int tempY = rand() % 8 + 1;
		b->setBomb(tempY, tempX);
	}
}
void Boss::attack2() //패턴2 (십자가 소환)
{
	for (int i = 1; i < 14; i += 2)
	{
		b->setBomb(arrayY, i);
	}
	for (int i = 1; i < 9; i += 2)
	{
		b->setBomb(i, arrayX);
	}
}
void Boss::attack3() //패턴3 (일정한 좌표 소환)
{
	for (int i = 1; i < 9; i += 2)
	{
		b->setBomb(i, 3);
		b->setBomb(i, 7);
		b->setBomb(i, 11);
	}
}

void Boss::attack4()
{
	for (int i = 1; i < 14; i++)
	{
		b->setBomb(1, i);
		b->setBomb(8, i);
	}

	for (int i = 1; i < 8; i++)
	{
		b->setBomb(i, 1);
		b->setBomb(i, 13);
	}
}

void Boss::move() //이동
{
	updateMoveCount++;
	if (updateMoveCount > moveCount) //랜덤한 시간이 지나면
	{
		moveX = rand() % 10 + 3;
		moveY = rand() % 5 + 3;
		isMoving = true;
		moveCount = rand() % 300 + 300;
		updateMoveCount = 0;
	}
	if (isMoving == true) //천천히 사라졌다가
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
	if (isMoving2 == true) //천천히 생긴다
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
	img->alphaRender(getMemDC(), x - 60, y - 250, alpha);
	char str[128];
	sprintf(str, "hp : %d  x:%d  y:%d", hp,arrayX, arrayY);
	TextOut(getMemDC(), 10, 400, str, strlen(str));
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

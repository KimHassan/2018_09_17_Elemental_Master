#include "stdafx.h"
#include "p_Player.h"


p_Player::p_Player()
{
}


p_Player::~p_Player()
{
}


HRESULT p_Player::init(string _stageName, int _arrayY, int _arrayX)
{
	stageName = _stageName;

	x = TILEMANAGER->GetTileList(stageName.c_str())[_arrayY][_arrayX].GetTileRect().left;
	y = TILEMANAGER->GetTileList(stageName.c_str())[_arrayY][_arrayX].GetTileRect().top;

	arrayY = _arrayY;
	arrayX = _arrayX;
	frameX = 0;
	frameY = 1;

	isDead = false;
	isReverse = false;
	isEnd = false;
	alpha = 0;
	speed = 3;

	dead_sign = IMAGEMANAGER->findImage("dead");

	rc = RectMake(x + 10, y + 70, 50, 30);

	
	return S_OK;
}
void p_Player::update()
{

	rc = RectMake(x + 10, y + 70, 50, 30);

	center = PointMake(x + 35, rc.bottom - 5);
	if (isDead == true)
	{
		if (isReverse == false)
		{
			alpha += 3;
			if (alpha >= 255)
			{
				respawn();

				isReverse = true;

			}

		}
		else
		{
			if (isEnd)
				return;
			alpha -= 3;
			if (alpha < 0)
			{
				alpha = 0;
				isReverse = false;
				isDead = false;

			}
		}


	}
	else
	{
		MoveUpdate();
		FrameUpdate();
		setBomb();
		if (hp->GetCurrentHp() <= 0)
			isEnd = true;
	}
	b->update();


}


void p_Player::MoveUpdate()// 캐릭터의 이동을 담당함
{

	for (int i = 0; i < TILEMANAGER->GetTileLastArrY(); i++)
	{
		for (int j = 0; j < TILEMANAGER->GetTileLastArrX(); j++)
		{
			if (PtInRect(&TILEMANAGER->GetTileList(stageName.c_str())[i][j].GetTileRect(), center))
			{
				arrayX = j;
				arrayY = i;
			}
		}
	}

	if (TILEMANAGER->GetTileList(stageName.c_str())[arrayY][arrayX].GetTileState() == BOOM)
	{
		Dead();
	}
	RECT temp;
	for (int i = 0; i < ITEMMANAGER->getvItem().size(); i++)
	{
		if (IntersectRect(&temp, &ITEMMANAGER->getvItem()[i]->getRect(), &rc))
		{
			ITEMMANAGER->getvItem()[i]->useItem(this);
			ITEMMANAGER->getvItem()[i]->setIsEnd();
		}
	}
	
}
void p_Player::FrameUpdate() // 캐릭터의 애니메이션을 담당함
{

}

void p_Player::setBomb() // 캐릭터의 폭탄을 담당함
{
	
}

void p_Player::respawn()
{

}
void p_Player::Dead()
{
	hp->Hit();
	isDead = true;


}
void p_Player::render()
{
	//if(isDead == false)
	//	img->frameRender(getMemDC(), x, y, frameX, frameY);
	//else
	img->frameAlphaRender(getMemDC(), x, y, frameX, frameY, alpha);
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	}

	char str[128];
	sprintf(str, "(Y:%d, X:%d)", arrayY, arrayX);
	//TextOut(getMemDC(), 10, 100, str, strlen(str));
	//b->render();
	hp->render();

	if (isDead)
	{
		dead_sign->alphaRender(getMemDC(), x + 35, y - 30, 255 - alpha);

	}

}
void p_Player::release()
{
	img = NULL;
	dead_sign = NULL;
	delete img;
	delete dead_sign;
}


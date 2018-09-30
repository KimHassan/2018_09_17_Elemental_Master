#include "stdafx.h"
#include "Player2.h"

Player2::Player2()
{
}

Player2::~Player2()
{
}

HRESULT Player2::init(string _stageName, int _arrayY, int _arrayX)
{
	img = IMAGEMANAGER->findImage("Player2");
	stageName = _stageName;

	x = TILEMANAGER->GetTileList(stageName.c_str())[_arrayY][_arrayX].GetTileRect().left;
	y = TILEMANAGER->GetTileList(stageName.c_str())[_arrayY][_arrayX].GetTileRect().top;

	arrayY = _arrayY;
	arrayX = _arrayX;
	frameX = 0;
	frameY = 1;

	b = new BulletManager;
	b->init(10);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			map[i][j] = false;
		}
	}

	speed = 3;

	hp = new Heart;
	hp->init("Player2_Hp", GAMEWINDOWX + GAMEWINDOWWIDTH + GAMEWINDOWX / 2 - 25, 150, 5);
	return S_OK;
}
void Player2::update()
{
	rc = RectMake(x + 10, y + 70, 50, 30);
	center = PointMake(x + 35, rc.bottom - 5);
	MoveUpdate();
	FrameUpdate();
	setBomb();
	b->update();


}


void Player2::MoveUpdate()// 캐릭터의 이동을 담당함
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

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (rc.left < GAMEWINDOWX)
			return;
		if (TILEMANAGER->GetTileList(stageName.c_str())[arrayY][arrayX - 1].GetTileState() != TILE && TILEMANAGER->GetTileList(stageName.c_str())[arrayY][arrayX - 1].GetTileState() != BOOM)
			if (IntersectRect(&temp, &TILEMANAGER->GetTileList(stageName.c_str())[arrayY][arrayX - 1].GetTileRect(), &rc))
				return;
		x -= speed;

	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (rc.right > GAMEWINDOWX + GAMEWINDOWWIDTH)
			return;
		if (TILEMANAGER->GetTileList(stageName.c_str())[arrayY][arrayX + 1].GetTileState() != TILE && TILEMANAGER->GetTileList(stageName.c_str())[arrayY][arrayX + 1].GetTileState() != BOOM)
		if (IntersectRect(&temp, &TILEMANAGER->GetTileList(stageName.c_str())[arrayY][arrayX + 1].GetTileRect(), &rc))
		return;
		x += speed;

	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		if (rc.top < GAMEWINDOWY)
			return;
		if (arrayY - 1 < 0)
		{
		}
		else
		{
			if (TILEMANAGER->GetTileList(stageName.c_str())[arrayY - 1][arrayX].GetTileState() != TILE && TILEMANAGER->GetTileList(stageName.c_str())[arrayY - 1][arrayX].GetTileState() != BOOM)
				if (IntersectRect(&temp, &TILEMANAGER->GetTileList(stageName.c_str())[arrayY - 1][arrayX].GetTileRect(), &rc))
					return;
		}
		y -= speed;

	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (rc.bottom > GAMEWINDOWY + GAMEWINDOWHEIGHT)
			return;
		if (TILEMANAGER->GetTileList(stageName.c_str())[arrayY + 1][arrayX].GetTileState() != TILE && TILEMANAGER->GetTileList(stageName.c_str())[arrayY + 1][arrayX].GetTileState() != BOOM)
			if (IntersectRect(&temp, &TILEMANAGER->GetTileList(stageName.c_str())[arrayY + 1][arrayX].GetTileRect(), &rc))
				return;
		y += speed;

	}
}
void Player2::FrameUpdate() // 캐릭터의 애니메이션을 담당함
{
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT) || KEYMANAGER->isOnceKeyUp(VK_RIGHT) || KEYMANAGER->isOnceKeyUp(VK_UP) || KEYMANAGER->isOnceKeyUp(VK_DOWN)) //움직임이 바뀔때 마다 프레임 초기화
	{
		frameX = 0;
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) //frameX = 0, 2: STAND, 
	{										//frameX = 1, 3: MOVE

		if (count++ >= 15)
		{
			count = 0;

			if (frameX != 3)
				frameX++;
			else
				frameX = 0;
		}

		if (frameY != 3) {
			frameY = 3;
			img->setFrameY(frameY);
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{

		if (count++ >= 15)
		{
			count = 0;

			if (frameX != 3)
				frameX++;
			else
				frameX = 0;
		}

		if (frameY != 2) {
			frameY = 2;
			img->setFrameY(frameY);
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{

		if (count++ >= 15)
		{
			count = 0;

			if (frameX != 3)
				frameX++;
			else
				frameX = 0;
		}

		if (frameY != 0) {
			frameY = 0;
			img->setFrameY(frameY);
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{

		if (count++ >= 15)
		{
			count = 0;

			if (frameX != 3)
				frameX++;
			else
				frameX = 0;
		}

		if (frameY != 1) {
			frameY = 1;
			img->setFrameY(frameY);
		}
	}
}

void Player2::setBomb() // 캐릭터의 폭탄을 담당함
{

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		b->setBomb(arrayY, arrayX);
	}
}

void Player2::Dead()
{
	hp->Hit();

	arrayY = 5;
	arrayX = 8;
	x = TILEMANAGER->GetTileList(stageName.c_str())[arrayY][arrayX].GetTileRect().left;
	y = TILEMANAGER->GetTileList(stageName.c_str())[arrayY][arrayX].GetTileRect().top;


}

void Player2::render()
{
	img->frameRender(getMemDC(), x, y, frameX, frameY);

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	}

	char str[128];
	sprintf(str, "(Y:%d, X:%d)", arrayY, arrayX);
	TextOut(getMemDC(), 160 + 960+10, 100, str, strlen(str));
	b->render();
	hp->render();
}
void Player2::release()
{

}
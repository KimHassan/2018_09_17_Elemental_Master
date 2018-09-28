#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{

}

HRESULT Player::init(int _posX, int _posY)
{
	img = IMAGEMANAGER->findImage("Player1");

	x = _posX;
	y = _posY;

	frameX = 0;
	frameY = 1;

	b = new BombManager;
	b->init(10);

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			map[i][j] = false;
		}
	}

	return S_OK;
}
void Player::update()
{
	rc = RectMake(x+7, y+30, 57, 70);

	RECT tTemp;



	//if(TILEMANAGER->GetTileList("WaterStage")[0][0].GetTileRect())
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT) || KEYMANAGER->isOnceKeyUp(VK_RIGHT) || KEYMANAGER->isOnceKeyUp(VK_UP) || KEYMANAGER->isOnceKeyUp(VK_DOWN)) //움직임이 바뀔때 마다 프레임 초기화
	{
		frameX = 0;
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) //frameX = 0, 2: STAND, 
	{										//frameX = 1, 3: MOVE
		x -= 3;

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
		x += 3;

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
		y -= 3;

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
		y += 3;

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

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (i * 64 < x + 35 && (i + 1) * 64 > x + 35)
				{
					if (j * 64 < y + 100 && (j + 1) * 64 > y + 100)
					{
						if (map[i][j] == false)
						{
							map[i][j] = true;
							b->setBomb(i * 64, j * 64);
						}
					}
				}
			}
		}
	}
	RECT temp;
	if (IntersectRect(&temp, &rc, &TILEMANAGER->GetTileList("WaterStage")[0][6].GetTileRect()))
	{
		
		TILEMANAGER->GetTileList("WaterStage")[0][6].DestroyBlock();
		
	}
	b->update();
}


void Player::render()
{
	img->frameRender(getMemDC(), x, y, frameX, frameY);

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	}

	b->render();
}
void Player::release()
{

}
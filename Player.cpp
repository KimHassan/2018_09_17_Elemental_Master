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

	x = _posY;
	y = _posY;

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
	return S_OK;
}
void Player::update()
{
	rc = RectMake(x+10, y+70, 50, 30);
	center = PointMake(x + 35, rc.bottom-5);
	if (KEYMANAGER->isOnceKeyDown('H'))
		b->setBoom(1, 1);
	MoveUpdate();
	FrameUpdate();
	setBomb();
	b->update();


}


void Player::MoveUpdate()// 캐릭터의 이동을 담당함
{

	for (int i = 0; i < TILEMANAGER->GetTileLastArrY(); i++)
	{
		for (int j = 0; j < TILEMANAGER->GetTileLastArrX(); j++)
		{
			if (PtInRect(&TILEMANAGER->GetTileList("WaterStage")[i][j].GetTileRect(), center))
			{
				arrayX = j;
				arrayY = i;
			}
		}
	}
	RECT temp;
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{	
		if (rc.left < GAMEWINDOWX)
			return;
		if (TILEMANAGER->GetTileList("WaterStage")[arrayY][arrayX-1].GetTileState()!=TILE)
			if(IntersectRect(&temp,&TILEMANAGER->GetTileList("WaterStage")[arrayY][arrayX-1].GetTileRect(),&rc))
				return;
		x -= speed;

	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (rc.right > GAMEWINDOWX + GAMEWINDOWWIDTH)
			return;
		/*if (TILEMANAGER->GetTileList("WaterStage")[arrayY][arrayX + 1].GetTileState() != TILE)
			if (IntersectRect(&temp, &TILEMANAGER->GetTileList("WaterStage")[arrayY][arrayX + 1].GetTileRect(), &rc))
				return;*/
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
			if (TILEMANAGER->GetTileList("WaterStage")[arrayY - 1][arrayX].GetTileState() != TILE)
				if (IntersectRect(&temp, &TILEMANAGER->GetTileList("WaterStage")[arrayY - 1][arrayX].GetTileRect(), &rc))
					return;
		}
		y -= speed;

	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (rc.bottom > GAMEWINDOWY + GAMEWINDOWHEIGHT)
			return;
		if (TILEMANAGER->GetTileList("WaterStage")[arrayY + 1][arrayX].GetTileState() != TILE)
			if (IntersectRect(&temp, &TILEMANAGER->GetTileList("WaterStage")[arrayY + 1][arrayX].GetTileRect(), &rc))
				return;
		y += speed;

	}
}
void Player::FrameUpdate() // 캐릭터의 애니메이션을 담당함
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

void Player::setBomb() // 캐릭터의 폭탄을 담당함
{
	//if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	//{

	//	for (int i = 0; i < 15; i++)
	//	{
	//		for (int j = 0; j < 10; j++)
	//		{
	//			if (i * 64 < x + 35 && (i + 1) * 64 > x + 35)
	//			{
	//				if (j * 64 < y + 100 && (j + 1) * 64 > y + 100)
	//				{
	//					if (map[i][j] == false)
	//					{
	//						map[i][j] = true;
	//						b->setBomb(i * 64, j * 64);
	//					}
	//				}
	//			}
	//		}
	//	}
	//}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		b->setBomb(arrayY, arrayX);
	}
}

void Player::render()
{
	img->frameRender(getMemDC(), x, y, frameX, frameY);

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	}

	char str[128];
	sprintf(str, "(Y:%d, X:%d)", arrayY, arrayX);
	TextOut(getMemDC(), 10, 100, str, strlen(str));
	b->render();
}
void Player::release()
{

}
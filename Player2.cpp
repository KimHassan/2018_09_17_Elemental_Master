#include "stdafx.h"
#include "Player2.h"

Player2::Player2()
{
}

Player2::~Player2()
{
}

HRESULT Player2::init(int _posX, int _posY)
{
	img = IMAGEMANAGER->findImage("Player2");

	x = _posX;
	y = _posY;

	frameX = 0;
	frameY = 1;

	return S_OK;
}

void Player2::update()
{
	rc = RectMake(x, y, 70, 100);

	if (KEYMANAGER->isOnceKeyUp('A') || KEYMANAGER->isOnceKeyUp('D') || KEYMANAGER->isOnceKeyUp('W') || KEYMANAGER->isOnceKeyUp('S'))
	{
		frameX = 0;
	}

	if (KEYMANAGER->isStayKeyDown('A')) //frameX = 0, 2: STAND, frameX = 1, 3: MOVE
	{
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

	if (KEYMANAGER->isStayKeyDown('D'))
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

	if (KEYMANAGER->isStayKeyDown('W'))
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

	if (KEYMANAGER->isStayKeyDown('S'))
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
}

void Player2::render()
{
	img->frameRender(getMemDC(), x, y, frameX, frameY);
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	}
}

void Player2::release()
{
}

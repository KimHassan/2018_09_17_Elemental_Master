#include "stdafx.h"
#include "Bomb.h"

Bomb::Bomb()
{

}

Bomb::~Bomb()
{
}

HRESULT Bomb::init(int _posX, int _posY)
{
	img = IMAGEMANAGER->findImage("Bub");


	x = _posX;
	y = _posY;

	frameX = 0;
	frameY = 0;

	count = 0;
	end = false;

	return S_OK;
}

void Bomb::update()
{
	count++;

	if (count % 50 == 0 && count != 0)
	{
		frameX++;
	}

	if (frameX >= 4)
	{
		end = true;
		release();
	}

}

void Bomb::render()
{
	img->frameRender(getMemDC(), x, y, frameX, frameY);
}

void Bomb::release()
{
	img = NULL;

	delete img;
}

void BombManager::init(UINT _max)
{
	max = _max;
	count = 0;
}
void BombManager::setBomb(int _posX, int _posY)
{
	if (vBomb.size() >= max)
		return;

	bomb = new Bomb;
	bomb->init(_posX, _posY);
	vBomb.push_back(bomb);
}

void BombManager::update()
{
	for (int i = 0; i < vBomb.size(); i++)
	{
		vBomb[i]->update();

		if (vBomb[i]->getEnd())
		{
			vBomb.erase(vBomb.begin() + i);
		}
	}
}

void BombManager::render()
{
	for (int i = 0; i < vBomb.size(); i++)
	{
		vBomb[i]->render();
	}
}

void BombManager::release()
{

}

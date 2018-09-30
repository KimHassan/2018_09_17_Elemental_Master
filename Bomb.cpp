#include "stdafx.h"
#include "Bomb.h"

Bomb::Bomb()
{

}

Bomb::~Bomb()
{
}

HRESULT Bomb::init(int _arrayY, int _arrayX)
{
	img = IMAGEMANAGER->findImage("Bub");

	arrayX = _arrayX;
	arrayY = _arrayY;
	x = TILEMANAGER->GetTileList("WaterStage")[arrayY][arrayX].GetTileRect().left;
	y = TILEMANAGER->GetTileList("WaterStage")[arrayY][arrayX].GetTileRect().top;

	frameX = 0;
	frameY = 0;

	count = 0;

	end = false;

	return S_OK;
}

void Bomb::update()
{
	count++;

	if (count % 30 == 0 && count != 0)
	{
		frameX++;
	}

	if (frameX >= 4)
	{
		end = true;
		TILEMANAGER->GetTileList("WaterStage")[arrayY][arrayX].ChangeToTile();
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



#include "stdafx.h"
#include "Boom.h"


HRESULT Boom::init(int _arrayY, int _arrayX)
{
	img = IMAGEMANAGER->findImage("Boom");

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

void Boom::update()
{
	count++;

	if (count % 30 == 0 && count != 0)
	{
		frameX++;
	}

	if (frameX >= 3)
	{
		end = true;
		TILEMANAGER->GetTileList("WaterStage")[arrayY][arrayX].ChangeToTile();
		release();
	}
}

void Boom::render()
{
	img->frameRender(getMemDC(), x, y, frameX, frameY);
}

void Boom::release()
{
	img = NULL;

	delete img;
}

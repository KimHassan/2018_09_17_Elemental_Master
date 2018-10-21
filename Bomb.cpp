#include "stdafx.h"
#include "Bomb.h"

Bomb::Bomb()
{

}

Bomb::~Bomb()
{
}

HRESULT Bomb::init(string str,int _arrayY, int _arrayX)
{
	img = IMAGEMANAGER->findImage(str);

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

	if (TILEMANAGER->GetTileList("WaterStage")[arrayY][arrayX].GetTileState() == BOOM)
	{
		frameX = 3;
	}
	if (count % 30 == 0 && count != 0)
	{
		frameX++;
	}

	if (frameX >= 3)
	{
		end = true;
		TILEMANAGER->GetTileList("WaterStage")[arrayY][arrayX].ChangeToTile();
		
		release();

		SOUNDMANAGER->play("BombEffect", 1);
		
	}

}

void Bomb::render()
{
	img->frameRender(getMemDC(), x-3, y-7, frameX, frameY);
}

void Bomb::release()
{
	img = NULL;

	delete img;
}



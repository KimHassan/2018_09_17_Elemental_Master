#include "stdafx.h"
#include "tile.h"

HRESULT tile::init(const char *imageName, float _posX, float _posY, int _arrayX, int _arrayY, int _state, bool _setCheck)
{
	image = IMAGEMANAGER->findImage(imageName);

	arrayX = _arrayX;
	arrayY = _arrayY;

	posX = _posX;
	posY = _posY;

	state = _state;

	setCheck = _setCheck;

	tileRect =
	{
		(LONG)posX,
		(LONG)posY,
		(LONG)posX + (LONG)sizeX,
		(LONG)posY + (LONG)sizeY
	};

	//if (_state == BLOCK)
	//{
	//	posY -= 14;
	//}
	//if (_state == WALL)
	//{
	//	posY -= 14;
	//}
	return S_OK;
}

void tile::update()
{
}

void tile::render()
{
	if (state == TILE)
	{
		image->render(getMemDC(), posX, posY);
	}
	else
	{
		image->render(getMemDC(), posX, posY-14);
	}
}

void tile::release()
{
}

bool tile::GetCheck()
{
	return setCheck;
}

RECT tile::GetTileRect()
{
	return tileRect;
}

int tile::GetTileState()
{
	return state;
}
tile::tile()
{
}

tile::~tile()
{
}

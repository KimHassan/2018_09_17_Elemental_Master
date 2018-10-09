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
	sizeX = 64;
	sizeY = 64;
	tileRect =
	{
		(LONG)posX,
		(LONG)posY,
		(LONG)posX + (LONG)sizeX,
		(LONG)posY + (LONG)sizeY
	};

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
	else if (state == BLOCK)
	{
		image->render(getMemDC(), posX, posY-14);
		if (KEYMANAGER->isToggleKey(VK_F1))
		{
			char str[128];
			sprintf(str, "(Y:%d,X:%d)", arrayY, arrayX);
			
			Rectangle(getMemDC(), tileRect.left, tileRect.top, tileRect.right, tileRect.bottom);
			TextOut(getMemDC(), tileRect.left+5, tileRect.top+10, str, strlen(str));
		}
	}
	else if (state == WALL)
	{
		image->render(getMemDC(), posX, posY - 14);
		if (KEYMANAGER->isToggleKey(VK_F1))
		{
			char str[128];
			sprintf(str, "(Y:%d,X:%d)", arrayY, arrayX);

			Rectangle(getMemDC(), tileRect.left, tileRect.top, tileRect.right, tileRect.bottom);
			TextOut(getMemDC(), tileRect.left + 5, tileRect.top + 10, str, strlen(str));
		}
	}
	else
	{
		image->render(getMemDC(), posX, posY);
	}
}

void tile::DestroyBlock()
{

}

void tile::ChangeToBomb()
{
	ChangeToTile();
	state = TILESTATE::BOMB;
}

void tile::ChangeToBoom()
{
	//if (state == BOMB)
	//	return;
	ChangeToTile();
	state = TILESTATE::BOOM;
}
void tile::ChangeToTile()
{
	state = TILESTATE::TILE;
	if (TILEMANAGER->GetStageName() == "FireStage")
		image = IMAGEMANAGER->findImage("fTile");
	if (TILEMANAGER->GetStageName() == "WaterStage")
		image = IMAGEMANAGER->findImage("wTile1");
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

#include "stdafx.h"
#include "Item.h"


HRESULT Item::init(int _arrayX, int _arrayY)
{
	arrayX = _arrayX;
	arrayY = _arrayY;
	x = TILEMANAGER->GetTileList("w")[arrayY][arrayX].GetTileRect().left;
	y = TILEMANAGER->GetTileList("w")[arrayY][arrayX].GetTileRect().top;
	rc = RectMake(x, y, 64, 64);
	count = 0;
	maxCount = 1000;
	isEnd = false;
	return S_OK;
}

void Item::update()
{
	count++;
	if (count > maxCount)
	{
		isEnd = true;
	}
}

void Item::render()
{
	img->render(getMemDC(), x, y);
}

void Item::release()
{
	img = NULL;
	delete img;
}

void Item::useItem(p_Player *p)
{
	
}

Item::Item()
{
}


Item::~Item()
{
}

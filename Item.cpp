#include "stdafx.h"
#include "Item.h"


HRESULT Item::init(string str,int _arrayX, int _arrayY)
{
	arrayX = _arrayX;
	arrayY = _arrayY;
	x = TILEMANAGER->GetTileList("w")[arrayX][arrayY].GetTileRect().left;
	y = TILEMANAGER->GetTileList("w")[arrayX][arrayY].GetTileRect().top;
	rc = RectMake(x, y, 64, 64);
	return S_OK;
}

void Item::update()
{
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

void Item::getItem(p_Player *p)
{
	
}

Item::Item()
{
}


Item::~Item()
{
}

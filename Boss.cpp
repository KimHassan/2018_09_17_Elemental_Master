#include "stdafx.h"
#include "Boss.h"


HRESULT Boss::init()
{
	arrayY = 2;
	arrayX = 5;
	img = IMAGEMANAGER->findImage("Boss");
	x = TILEMANAGER->GetTileList("x")[arrayY][arrayX].GetTileRect().left;
	y = TILEMANAGER->GetTileList("x")[arrayY][arrayX].GetTileRect().top;
	return S_OK;
}

void Boss::update()
{

}

void Boss::render()
{

}

void Boss::release()
{

}

Boss::Boss()
{
}


Boss::~Boss()
{
}

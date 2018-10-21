#include "stdafx.h"
#include "PowerUpItem.h"
#include "BulletManager.h"

HRESULT PowerUpItem::init( int _arrayX, int _arrayY)
{
	Item::init(_arrayX, _arrayY);
	img = IMAGEMANAGER->findImage("item1");
	power = 1;

	return S_OK;
}


void PowerUpItem::useItem(p_Player *p)
{
	p->getBullet()->setPower(p->getBullet()->getPower() + 1);
}

PowerUpItem::PowerUpItem()
{
}


PowerUpItem::~PowerUpItem()
{
}

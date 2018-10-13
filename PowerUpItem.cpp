#include "stdafx.h"
#include "PowerUpItem.h"
#include "BulletManager.h"

HRESULT PowerUpItem::init(string str, int _arrayX, int _arrayY)
{
	Item::init(str, _arrayX, _arrayY);
	power = 1;

	return S_OK;
}


void PowerUpItem::getItem(p_Player *p)
{
	p->getBullet()->setPower(p->getBullet()->getPower() + 1);
}

PowerUpItem::PowerUpItem()
{
}


PowerUpItem::~PowerUpItem()
{
}

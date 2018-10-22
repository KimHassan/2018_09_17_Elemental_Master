#include "stdafx.h"
#include "SpeedUpItem.h"


SpeedUpItem::SpeedUpItem()
{
}


SpeedUpItem::~SpeedUpItem()
{

}

HRESULT  SpeedUpItem::init(int _arrayX, int _arrayY)
{
	Item::init(_arrayX, _arrayY);
	img = IMAGEMANAGER->findImage("item2");
	power = 1;

	return S_OK;
}
void SpeedUpItem::useItem(p_Player *p)
{
	p->setSpeed(p->getSpeed() + 0.5);
}
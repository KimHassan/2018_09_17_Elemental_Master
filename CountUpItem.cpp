#include "stdafx.h"
#include "CountUpItem.h"


CountUpItem::CountUpItem()
{
}


CountUpItem::~CountUpItem()
{

}

HRESULT CountUpItem::init(int _arrayX, int _arrayY)	
{
	Item::init(_arrayX, _arrayY);
	img = IMAGEMANAGER->findImage("item3");
	power = 1;
	return S_OK;
}
void	CountUpItem::useItem(p_Player *p)			
{
	p->getBullet()->setMax(p->getBullet()->getMax() + 1);
}
#pragma once
#include "Item.h"
class SpeedUpItem :
	public Item
{
public:
	virtual HRESULT init(int _arrayX, int _arrayY);
	virtual void useItem(p_Player *p);
	SpeedUpItem();
	~SpeedUpItem();
};


#pragma once
#include "Item.h"
class PowerUpItem :
	public Item
{
	
public:
	virtual HRESULT init(int _arrayX, int _arrayY);
	virtual void useItem(p_Player *p);
	PowerUpItem();
	~PowerUpItem();
};


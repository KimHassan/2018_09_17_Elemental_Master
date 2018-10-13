#pragma once
#include "Item.h"
class PowerUpItem :
	public Item
{
	
public:
	virtual HRESULT init(string str, int _arrayX, int _arrayY);
	virtual void getItem(p_Player *p);
	PowerUpItem();
	~PowerUpItem();
};


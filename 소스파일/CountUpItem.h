#pragma once
#include "Item.h"
class CountUpItem :
	public Item
{

public:
	virtual HRESULT init(int _arrayX, int _arrayY);
	virtual void useItem(p_Player *p);
	CountUpItem();
	~CountUpItem();
};


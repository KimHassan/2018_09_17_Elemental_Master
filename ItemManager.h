#pragma once
#include "Item.h"
#include "PowerUpItem.h"
#include "CountUpItem.h"
#include "SpeedUpItem.h"


class ItemManager :
	public singletonBase<ItemManager>
{
	vector<Item*> vItem;
	vector<Item*>::iterator viItem;

public:
	HRESULT init();
	void update();
	void setItem(int arrayX,int arrayY);
	vector<Item*> getvItem() {return vItem;}
	void render();
	ItemManager();
	~ItemManager();
};


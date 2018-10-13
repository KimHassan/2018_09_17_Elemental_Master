#pragma once
#include "gameNode.h"
#include "Item.h"
#include "PowerUpItem.h"
#include "CountUpItem.h"
#include "SpeedUpItem.h"


class ItemManager :
	public gameNode
{
	vector<Item*> vItem;
	vector<Item*>::iterator viItem;

public:
	HRESULT init();
	void udpate();
	void setItem(int arrayX,int arrayY);
	void render();
	ItemManager();
	~ItemManager();
};


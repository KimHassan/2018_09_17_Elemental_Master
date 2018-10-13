#include "stdafx.h"
#include "ItemManager.h"


HRESULT ItemManager::init()
{
	return S_OK;
}

void ItemManager::udpate()
{
}

void ItemManager::render()
{
	for (int i = 0; i < vItem.size(); i++)
	{
		vItem[i]->render();
	}
}
void ItemManager::setItem(int arrayX, int arrayY)
{
	int num = rand() % 3;
	switch (num)
	{
		case 0:
		{
			PowerUpItem *it = new PowerUpItem;
			vItem.push_back(it);
		}
		case 1:
		{
			PowerUpItem *it = new PowerUpItem;
			vItem.push_back(it);
		}
		case 2:
		{
			PowerUpItem *it = new PowerUpItem;
			vItem.push_back(it);
		}
	}


}
ItemManager::ItemManager()
{
}


ItemManager::~ItemManager()
{
}

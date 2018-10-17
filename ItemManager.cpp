#include "stdafx.h"
#include "ItemManager.h"


HRESULT ItemManager::init()
{
	return S_OK;
}

void ItemManager::update()
{
	for (int i = 0; i < vItem.size(); i++)
	{
		vItem[i]->update();
		if (vItem[i]->getIsEnd())
		{
			vItem.erase(vItem.begin() + i);
		}
	}
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
	int num = rand() % 5;
	//PowerUpItem *it = new PowerUpItem;
	//it->init(arrayX, arrayY);
	//vItem.push_back(it);
	//
	switch (num)
	{
		case 0:
		{
			PowerUpItem *it = new PowerUpItem;
			it->init(arrayX, arrayY);
			vItem.push_back(it);
			break;
		}
		case 1:
		{
			SpeedUpItem *it = new SpeedUpItem;
			it->init(arrayX, arrayY);
			vItem.push_back(it);
			break;
		}
		case 2:
		{
			CountUpItem *it = new CountUpItem;
			it->init(arrayX, arrayY);
			vItem.push_back(it);
			break;
		}
		case 3:
		{
		}
		case 4:
		{
		}
	}
	


}
ItemManager::ItemManager()
{
}


ItemManager::~ItemManager()
{
}

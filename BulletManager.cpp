#include "stdafx.h"
#include "BulletManager.h"

HRESULT BulletManager::init(UINT _max)
{
	max = _max;
	power = 3;
	count = 0;
	return S_OK;

}
void BulletManager::setBomb(int arrayY, int arrayX)
{
	if (vBomb.size() >= max)
		return;

	Bomb *bomb = new Bomb;
	bomb->init(arrayY, arrayX);
	vBomb.push_back(bomb);
}
void BulletManager::setBoom(int arrayY, int arrayX)
{

	Boom *boom = new Boom;
	boom->init(arrayY, arrayX);
	vBoom.push_back(boom);

}
void BulletManager::update()
{
	//ÆøÅº
	for (int i = 0; i < vBomb.size(); i++)
	{
		vBomb[i]->update();

		if (vBomb[i]->getEnd())
		{
			bool LeftDestroy = false;
			bool RightDestroy = false;
			bool UpDestroy = false;
			bool DownDestroy = false;
			for (int j = 0; j < power; j++)
			{
				setBoom(vBomb[i]->getArrayY(), vBomb[i]->getArrayX());
				if (j > 0)
				{
					if (LeftDestroy == false)
					{
						switch (TILEMANAGER->GetTileList("WaterStage")[vBomb[i]->getArrayY()][vBomb[i]->getArrayX()-j].GetTileState())
						{
						case WALL:
							LeftDestroy = true;
							break;
						case BLOCK:
							LeftDestroy = true;
							setBoom(vBomb[i]->getArrayY(), vBomb[i]->getArrayX()-j);
							TILEMANAGER->GetTileList("WaterStage")[vBomb[i]->getArrayY()][vBomb[i]->getArrayX()-j].DestroyBlock();
							break;
						case TILE:
							setBoom(vBomb[i]->getArrayY(), vBomb[i]->getArrayX()-j);
							break;
						}
					}
					if (RightDestroy == false)
					{
						switch (TILEMANAGER->GetTileList("WaterStage")[vBomb[i]->getArrayY()][vBomb[i]->getArrayX()+ j].GetTileState())
						{
						case WALL:
							RightDestroy = true;
							break;
						case BLOCK:
							RightDestroy = true;
							setBoom(vBomb[i]->getArrayY(), vBomb[i]->getArrayX() + j);
							TILEMANAGER->GetTileList("WaterStage")[vBomb[i]->getArrayY()][vBomb[i]->getArrayX() + j].DestroyBlock();
							break;
						case TILE:
							setBoom(vBomb[i]->getArrayY(), vBomb[i]->getArrayX() + j);
							break;
						}
					}
					if (UpDestroy == false)
					{
						switch (TILEMANAGER->GetTileList("WaterStage")[vBomb[i]->getArrayY() - j][vBomb[i]->getArrayX()].GetTileState())
						{
						case WALL:
							UpDestroy = true;
							break;
						case BLOCK:
							UpDestroy = true;
							setBoom(vBomb[i]->getArrayY() - j, vBomb[i]->getArrayX());
							TILEMANAGER->GetTileList("WaterStage")[vBomb[i]->getArrayY() - j][vBomb[i]->getArrayX()].DestroyBlock();
							break;
						case TILE:
							setBoom(vBomb[i]->getArrayY() - j, vBomb[i]->getArrayX());
							break;
						}
					}
					if (DownDestroy == false)
					{
						switch (TILEMANAGER->GetTileList("WaterStage")[vBomb[i]->getArrayY() + j][vBomb[i]->getArrayX()].GetTileState())
						{
						case WALL:
							DownDestroy = true;
							break;
						case BLOCK:
							DownDestroy = true;
							setBoom(vBomb[i]->getArrayY() + j, vBomb[i]->getArrayX());
							TILEMANAGER->GetTileList("WaterStage")[vBomb[i]->getArrayY() + j][vBomb[i]->getArrayX()].DestroyBlock();
							break;
						case TILE:
							setBoom(vBomb[i]->getArrayY() + j, vBomb[i]->getArrayX());
							break;
						}
					}
					
				}
			}
			vBomb.erase(vBomb.begin() + i);
		}
	}
	//Æø¹ßÀÌÆåÆ®
	for (int i = 0; i < vBoom.size(); i++)
	{
		vBoom[i]->update();
		if (vBoom[i]->getEnd())
		{
			vBoom.erase(vBoom.begin() + i);
		}
	}
}

void BulletManager::render()
{
	for (int i = 0; i < vBomb.size(); i++)
	{
		vBomb[i]->render();
	}
	for (int i = 0; i < vBoom.size(); i++)
	{
		vBoom[i]->render();
	}
}

void BulletManager::release()
{

}
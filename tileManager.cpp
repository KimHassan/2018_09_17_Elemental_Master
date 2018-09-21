#include "stdafx.h"
#include "tileManager.h"

//"wBlock"
//"wWall",
//"wTile1"
//"wTile2"
//"wTile3"

HRESULT tileManager::init()
{
	tileFirstX = 0;
	tileFirstY = 0;

	lastArrX = 20;
	lastArrY = 20;

	int tempPattern[400] = //0 = TILE, 1 = BLOCK, 2 = WALL, 3 = EMPTY
	{
		2, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 2, 2, 1, 1, 2, 2, 1, 0,
		1, 2, 0, 0, 2, 2, 0, 0, 2, 1, 0, 1, 2, 0, 0, 0, 0, 2, 1, 0,
		0, 0, 1, 2, 0, 0, 2, 1, 0, 0, 0, 0, 0, 1, 2, 2, 1, 0, 0, 0,
		0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0


	};

	maketilestage("WaterStage", tempPattern);

	return S_OK;
}

void tileManager::render(const char *stageName)
{
	if (tileSets.find(stageName) == tileSets.end())
		return;

	auto it = tileSets.find(stageName)->second;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (it[i][j].GetCheck() == true)
				it[i][j].render();
		}
	}

}

void tileManager::maketilestage(const char *stageName, int *tilePattern)
{
	if (stageName == "WaterStage")
	{
		for (int y = 0; y < lastArrY; y++)
		{
			for (int x = 0; x < lastArrX; x++)
			{
				if (tilePattern[y * lastArrX + x] == TILE)
				{
					pushTile("WaterStage", "wTile1", y, x, TILE, true);
				}
				else if (tilePattern[y * lastArrX + x] == BLOCK)
				{
					
					pushTile("WaterStage", "wBlock", y, x, BLOCK, true);
				}
				else if (tilePattern[y * lastArrX + x] == WALL)
				{
					
					pushTile("WaterStage", "wWall", y, x, WALL, true);
				}
				else
				{
					continue;
				}
			}
		}
	}
	else if (stageName == "FireStage")
	{

	}

}

void tileManager::pushTile(const char *stageName, const char *imageName, int _arrayY, int _arrayX, int _state, bool _setCheck)
{
	auto wIter = tileSets.find(stageName)->second;

	if (wIter == nullptr)
		return;

	tile t = tile();
	t.init(imageName, tileFirstX + 64* _arrayX, tileFirstY + 64 * _arrayY, _arrayX, _arrayY, _state, _setCheck);

	wIter[_arrayY][_arrayX] = t;
}

tile** tileManager::GetTileList(const char * stageName)
{
	auto it = tileSets.find(stageName)->second;

	if (it != nullptr)
		return it;

}

tileManager::tileManager()
{
	tile **t = new tile*[20];

	for (int i = 0; i < 20; i++)
	{
		t[i] = new tile[20];
	}

	tileSets.insert(make_pair("WaterStage", t));
	tileSets.insert(make_pair("FireStage", t));

}

tileManager::~tileManager()
{
}

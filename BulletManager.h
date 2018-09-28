#pragma once
#include "gameNode.h"
#include "Bomb.h"
#include "Boom.h"

class BulletManager : public gameNode
{
private:
	vector<Bomb*> vBomb;
	vector<Bomb*>::iterator viBomb;
	vector<Boom*> vBoom;
	vector<Boom*>::iterator viBoom;
	UINT max;
	UINT count;
	UINT power;

public:
	HRESULT init(UINT _max);
	void setBomb(int arrayY, int arrayX);
	void setBoom(int arrayY, int arrayX);
	void update();
	void render();
	void release();
};

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

	string boomName;
	string bombName;

public:
	HRESULT init(string _boomName, string _bombName, UINT _max);
	void setBomb(int arrayY, int arrayX);
	void setBoom(int arrayY, int arrayX);
	void update();
	void render();
	void setMax(int _max) { max = _max; }
	void setPower(int _power) { power = _power; }
	int getMax() {return max;}
	int getPower() { return power; }
	void release();
};

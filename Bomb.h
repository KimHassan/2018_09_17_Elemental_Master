#pragma once
#include "gameNode.h"

class Bomb :
	public gameNode
{
private:
	image *img;
	int x, y;
	int frameX, frameY;
	UINT count;
	RECT rc;
	bool end;

public:
	Bomb();
	~Bomb();

	HRESULT init(int _posX, int _posY);
	void update();
	void render();
	void release();
	int getX() { return x; }
	int getY() { return y; }
	bool getEnd() { return end; }
	RECT getRect() { return rc; }
};

class BombManager : public gameNode
{
private:
	Bomb *bomb;
	vector<Bomb*> vBomb;
	vector<Bomb*>::iterator viBomb;
	UINT max;
	UINT count;

public:
	void init(UINT _max);
	void setBomb(int _posX, int _posY);
	void update();
	void render();
	void release();
};

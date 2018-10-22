#pragma once
#include "gameNode.h"

class Bomb :
	public gameNode
{
private:
	image *img;
	int arrayX, arrayY;
	int x, y;
	int frameX, frameY;
	UINT count;
	RECT rc;
	bool end;

public:
	Bomb();
	~Bomb();

	HRESULT init(string str, int _posX, int _posY);
	void update();
	void render();
	void release();
	int getX() { return x; }
	int getY() { return y; }
	int getArrayX() { return arrayX; }
	int getArrayY() { return arrayY; }
	bool getEnd() { return end; }
	RECT getRect() { return rc; }
};





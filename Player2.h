#pragma once
#include "gameNode.h"
class Player2 :
	public gameNode
{
private:
	image *img;
	int x, y;
	int frameX, frameY;
	UINT count;
	RECT rc;

public:
	Player2();
	~Player2();

	HRESULT init(int _posX, int _posY);
	void update();
	void render();
	void release();
	int getX() { return x; }
	int getY() { return y; }
	RECT getRect() { return rc; }
};


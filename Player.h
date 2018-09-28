#pragma once
#include "gameNode.h"
#include "Bomb.h"



class Player :
	public gameNode
{
private:
	image *img;
	tile *tile;

	int x, y;
	int frameX, frameY;
	int arrayX, arrayY;
	int map[20][20];

	UINT count;
	RECT rc;
	BombManager *b;

public:
	Player();
	~Player();

	HRESULT init(int _posX, int _posY);
	void update();
	void render();
	void release();
	int getX() { return x; }
	int getY() { return y; }
	RECT getRect() { return rc; }
};
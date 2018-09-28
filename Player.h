#pragma once
#include "gameNode.h"
#include "BulletManager.h"
class Player :
	public gameNode
{
private:
	image *img;
	tile *tile;

	int x, y;
	int width, height;
	POINT center;
	int frameX, frameY;
	int arrayX, arrayY;
	int map[20][20];

	UINT speed;
	UINT count;
	RECT rc;
	BulletManager *b;

public:
	Player();
	~Player();

	HRESULT init(int _posX, int _posY);
	void update();
	void MoveUpdate();
	void FrameUpdate();
	void setBomb();
	void render();
	void release();
	int getX() { return x; }
	int getY() { return y; }
	RECT getRect() { return rc; }
	
};
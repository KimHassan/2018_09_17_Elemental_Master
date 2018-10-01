#pragma once
#include "gameNode.h"
#include "BulletManager.h"
#include "Heart.h"
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

	Heart *hp;

	bool isDead;
	string stageName;
public:
	Player();
	~Player();

	HRESULT init(string _stageName, int _arrayY, int _arrayX);
	void update();
	void MoveUpdate();
	void FrameUpdate();
	void setBomb();
	void Dead();
	void render();
	void release();
	int getX() { return x; }
	int getY() { return y; }
	RECT getRect() { return rc; }
	
};
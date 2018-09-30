#pragma once
#include "gameNode.h"
#include "BulletManager.h"
#include "Heart.h"
class Player2 :
	public gameNode
{
private:
	image * img;
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

	string stageName;
public:
	Player2();
	~Player2();

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
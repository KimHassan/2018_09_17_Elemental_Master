#pragma once
#include "gameNode.h"
class Boss :
	public gameNode
{
	image *img;
	int x, y;
	int width, height;
	POINT center;
	int frameX, frameY;
	int arrayX, arrayY;

	UINT speed;
	UINT count;
	RECT rc;
	BulletManager *b;

	Heart *hp;

public:
	HRESULT init();
	void update();
	void render();
	void release();
	Boss();
	~Boss();
};


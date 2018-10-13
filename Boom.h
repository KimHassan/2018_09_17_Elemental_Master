#pragma once
#include "gameNode.h"


class Boom : public gameNode
{
private:
	image * img;
	int arrayX, arrayY;
	int x, y;
	int frameX, frameY;
	UINT count;
	RECT rc;
	bool end;

public:
	HRESULT init(string str,int _arrayY, int _arrayX);
	void update();
	void render();
	void release();
	int getX() { return x; }
	int getY() { return y; }
	bool getEnd() { return end; }
	RECT getRect() { return rc; }

};

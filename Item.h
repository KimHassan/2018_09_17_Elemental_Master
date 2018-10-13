#pragma once
#include "gameNode.h"
#include "p_Player.h"

class Item :
	public gameNode
{
protected:
	RECT rc;
	int arrayX, arrayY;
	float x, y;
	image *img;
	int power;
public:
	virtual HRESULT init(string str, int _arrayX,int _arrayY);
	virtual void update();
	virtual void render();
	virtual void release();
	virtual void getItem(p_Player *p);
	Item();
	~Item();
};


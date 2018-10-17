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
	UINT count;
	UINT maxCount;
	bool isEnd;
public:
	virtual HRESULT init(int _arrayX,int _arrayY);
	virtual void update();
	virtual void render();
	virtual void release();
	virtual void useItem(p_Player *p);
	virtual bool getIsEnd() {return isEnd;}
	virtual void setIsEnd() {isEnd = true; }
	virtual RECT getRect() {return rc;}
	int getArrayX() { return arrayX; }
	int getArrayY() { return arrayY; }
	Item();
	~Item();
};


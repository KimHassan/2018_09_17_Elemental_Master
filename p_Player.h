#pragma once
#include "gameNode.h"
#include "Heart.h"
#include "BulletManager.h"
class p_Player :
	public gameNode
{
protected:
	image *img;
	image *dead_sign;


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
	bool isReverse;
	int alpha;
	bool isEnd;
	string stageName;
public:
	p_Player();
	~p_Player();

	virtual HRESULT init(string _stageName, int _arrayY, int _arrayX);
	virtual void update();
	virtual void MoveUpdate();
	virtual void FrameUpdate();
	virtual void setBomb();
	virtual void Dead();
	virtual void render();
	virtual void release();
	virtual void respawn();
	virtual int getX() { return x; }
	virtual int getY() { return y; }
	virtual int getArrayX() { return arrayX; }
	virtual int getArrayY() { return arrayY; }
	virtual void setSpeed(int num) { speed = num; }
	virtual int getSpeed() { return speed; }
	virtual BulletManager *getBullet() { return b; }
	virtual bool getEnd() { return isEnd; }
	virtual RECT getRect() { return rc; }
};


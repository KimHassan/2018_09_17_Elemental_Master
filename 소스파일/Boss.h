#pragma once
#include "gameNode.h"
#include "progressBar.h"
class Boss :
	public gameNode
{
	image *img;
	BulletManager *b;
	progressBar *hpBar;
	int x, y;
	POINT center;
	int frameX, frameY;
	int arrayX, arrayY;
	RECT rc;
	
	int alpha;
	
	UINT updateAttackCount;
	UINT attackCount;
	UINT attackingCount;
	
	bool isDamaged;
	bool isDead;
	UINT damagedCount;
	int hp;

	bool isMoving;
	bool isMoving2;
	int moveX;
	int moveY;
	UINT moveCount;
	UINT updateMoveCount;

	

public:
	HRESULT init();

	void update();
	void render();
	void release();

	void attack();
	void attack1();
	void attack2();
	void attack3();
	void attack4();

	void cheat();

	void move();

	int getArrayX() { return arrayX; }
	int getArrayY() { return arrayY; }
	bool getDead() {	return isDead;}
	BulletManager *getBullet() { return b; }
	Boss();
	~Boss();
};


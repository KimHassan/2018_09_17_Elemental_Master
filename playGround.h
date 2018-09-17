#pragma once
#include "gameNode.h"
#include "Player.h"
#include "Player2.h"

class playGround : public gameNode
{
private:
	Player *p1;
	Player2 *p2;

	
	

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(void);

	playGround();
	~playGround();
};


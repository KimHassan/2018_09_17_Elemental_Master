#pragma once
#include "gameNode.h"
#include "TitleScene.h"
#include "PVPScene.h"
#include "PVEScene.h"
class playGround : public gameNode
{
private:

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(void);

	playGround();
	~playGround();
};


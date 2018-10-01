#pragma once
#include "Scene.h"
#include "Player.h"
#include "Player2.h"


class PVPScene :
	public Scene
{
	Player *p1;
	Player2 *p2;

public:
	virtual HRESULT init();
	virtual void update();
	virtual void render();
	virtual void release();
	PVPScene();
	~PVPScene();
};


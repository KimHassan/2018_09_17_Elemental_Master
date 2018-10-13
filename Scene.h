#pragma once
#include "gameNode.h"
class Scene :
	public gameNode
{
protected:

	image* backGround;
	int alpha;
	image *black;
	bool isGameStart;
	

public:
	virtual HRESULT init();
	virtual void gameStart();
	virtual void update();
	virtual void render();
	virtual void release();
	Scene();
	~Scene();
};


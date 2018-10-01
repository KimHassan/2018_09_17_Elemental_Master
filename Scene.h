#pragma once
#include "gameNode.h"
class Scene :
	public gameNode
{
protected:

	image* backGround;

public:
	virtual HRESULT init();
	virtual void update();
	virtual void render();
	virtual void release();
	Scene();
	~Scene();
};


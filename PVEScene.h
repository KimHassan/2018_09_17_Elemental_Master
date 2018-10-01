#pragma once
#include "Scene.h"
class PVEScene :
	public Scene
{
public:
	virtual HRESULT init();
	virtual void update();
	virtual void render();
	virtual void release();
	PVEScene();
	~PVEScene();
};


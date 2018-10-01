#pragma once
#include "Scene.h"
class TitleScene :
	public Scene
{
public:
	virtual HRESULT init();
	virtual void update();
	virtual void render();
	virtual void release();
	TitleScene();
	~TitleScene();
};


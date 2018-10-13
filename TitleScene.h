#pragma once
#include "Scene.h"
class TitleScene :
	public Scene
{
	image *bg;
	image *leftSelect;
	image *rightSelect;
	image *howToSelect;
	image* black;

	RECT  leftSelectRect;
	RECT  rightSelectRect;
	RECT  howToSelectRect;
	RECT rc;

	bool isleftSelect;
	bool isrightSelect;
	bool ishowToSelect;
	bool isGameStart;
	
	int alpha;
	int moveScene;
public:
	virtual HRESULT init();
	virtual void update();
	virtual void render();
	virtual void release();
	TitleScene();
	~TitleScene();
};


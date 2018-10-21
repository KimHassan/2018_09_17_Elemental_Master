#pragma once
#include "Scene.h"
class TitleScene :
	public Scene
{
	image * title;

	image *bg;
	image *leftSelect;
	image *rightSelect;
	image *leftSelect2;
	image *rightSelect2;
	image *howToSelect;
	image *howToScene;
	image *exitButton;
	image *backButton;
	image* black;


	RECT  leftSelectRect;
	RECT  rightSelectRect;
	RECT  howToSelectRect;
	RECT buttonRect;
	RECT exitRect;
	RECT rc;
	
	int changeScene;
	bool isleftSelect;
	bool isrightSelect;
	bool ishowToSelect;
	bool isGameStart;
	bool ishowToScene;
	

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


#pragma once
#include "Scene.h"
#include "Player.h"
#include "Player2.h"
#include "Boss.h"
#include "progressBar.h"

class PVEScene :
	public Scene
{
private:	
	Player *p1;
	Player2 *p2;
	Boss *b;
	image *ending;

	int mentAlpha;
	int winPlayer;
	int isEnd;
	bool isIntro;
	bool isStart;
	POINT mentPosition;
	image *img_GameStart;

	UINT itemCount;
	UINT updateItemCount;

public:
	void Intro();
	virtual HRESULT init();
	virtual void update();
	virtual void render();
	virtual void release();
	PVEScene();
	~PVEScene();
};


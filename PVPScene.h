#pragma once
#include "Scene.h"
#include "Player.h"
#include "Player2.h"


class PVPScene :
	public Scene
{
	Player *p1;
	Player2 *p2;

	image *img_p1Win;
	image *img_p2Win;
	image *img_GameStart;
	POINT mentPosition;

	int mentAlpha;
	int winPlayer;
	bool isEnd;
	bool isIntro;
	bool isStart;


public:
	virtual HRESULT init();
	void Intro();
	virtual void update();
	virtual void render();
	virtual void release();
	PVPScene();
	~PVPScene();
};


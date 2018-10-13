#include "stdafx.h"
#include "PVPScene.h"


PVPScene::PVPScene()
{
}


PVPScene::~PVPScene()
{
}

HRESULT PVPScene::init()
{
	Scene::init();
	TILEMANAGER->init("WaterStage");
	p1 = new Player;
	p1->init("WaterStage",3,1);

	p2 = new Player2;
	p2->init("WaterStage",6,10);

	

	img_p1Win		 = IMAGEMANAGER->findImage("p1Win");
	img_p2Win		 = IMAGEMANAGER->findImage("p2Win");
	img_GameStart = IMAGEMANAGER->findImage("gameStart");
	mentPosition = PointMake(200, 210);
	mentAlpha = 0;
	winPlayer = 0;
	isEnd = false;
	isIntro = false;
	isStart = false;
	return S_OK;
}
void PVPScene::Intro()
{
	if (isIntro == false)
	{
		mentAlpha += 5;
		if (mentAlpha >= 255)
		{
			mentAlpha = 255;
			isIntro = true;
		}
	}
	else
	{
		mentAlpha -= 5;
		if (mentAlpha <= 0)
		{
			mentAlpha = 0;
			isStart = true;
		}
	}
}

void PVPScene::update()
{
	if (isEnd == true)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
			SCENEMANAGER->changeScene("TitleScene");
	}
	else
	{
		Scene::update();
		if(isGameStart == true && isStart == false)
			Intro();
		if (isStart == true)
		{

			p1->update();
			p2->update();
			if (p1->getEnd() == true)
			{
				winPlayer = 1;
				mentAlpha += 3;
				if (mentAlpha >= 255)
				{
					mentAlpha = 255;
					isEnd = true;
				}
			}
			else if(p2->getEnd() == true)
			{
				winPlayer = 2;
				mentAlpha += 3;
				if (mentAlpha >= 255)
				{
					mentAlpha = 255;
					isEnd = true;
				}
			}
		}

	}
		
}
void PVPScene::render()
{
	TILEMANAGER->render("WaterStage");

	p1->render();

	p2->render();
	if(winPlayer == 1)
		img_p1Win->alphaRender(getMemDC(),mentPosition.x,mentPosition.y,mentAlpha);
	else if(winPlayer == 2)
		img_p2Win->alphaRender(getMemDC(), mentPosition.x, mentPosition.y, mentAlpha);
	if(isStart == false)
		img_GameStart->alphaRender(getMemDC(), mentPosition.x, mentPosition.y, mentAlpha);
	Scene::render();
}
void PVPScene::release()
{
	img_p1Win	   = NULL;
	img_p2Win	   = NULL;
	img_GameStart  = NULL;
	delete img_p1Win;
	delete img_p2Win;
	delete img_GameStart;
}
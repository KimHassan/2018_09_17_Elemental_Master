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
			ITEMMANAGER->update();
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
	for (int y = 0; y < TILEMANAGER->GetTileLastArrY(); y++)
	{
		for (int x = 0; x < TILEMANAGER->GetTileLastArrX(); x++)
		{
			TILEMANAGER->GetTileList("w")[y][x].render();
		}
		if (y == p1->getArrayY())
			p1->render();
		if (y == p2->getArrayY())
			p2->render();
		for (int i = 0; i < p1->getBullet()->getvBomb().size(); i++)
		{
			if(p1->getBullet()->getvBomb()[i]->getArrayY() == y)
				p1->getBullet()->getvBomb()[i]->render();
		}
		for (int i = 0; i < p1->getBullet()->getvBoom().size(); i++)
		{
			if (p1->getBullet()->getvBoom()[i]->getArrayY() == y)
				p1->getBullet()->getvBoom()[i]->render();
		}
		for (int i = 0; i < p2->getBullet()->getvBomb().size(); i++)
		{
			if (p2->getBullet()->getvBomb()[i]->getArrayY() == y)
				p2->getBullet()->getvBomb()[i]->render();
		}
		for (int i = 0; i < p2->getBullet()->getvBoom().size(); i++)
		{
			if (p2->getBullet()->getvBoom()[i]->getArrayY() == y)
				p2->getBullet()->getvBoom()[i]->render();
		}
		for (int i = 0; i < ITEMMANAGER->getvItem().size(); i++)
		{
			if(ITEMMANAGER->getvItem()[i]->getArrayY() == y)
				ITEMMANAGER->getvItem()[i]->render();
		}
	}
	//p1->render();

	//p2->render();
	//ITEMMANAGER->render();
	
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
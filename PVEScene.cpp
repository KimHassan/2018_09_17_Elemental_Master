#include "stdafx.h"
#include "PVEScene.h"


PVEScene::PVEScene()
{
}


PVEScene::~PVEScene()
{
}

HRESULT PVEScene::init()
{
	Scene::init();
	TILEMANAGER->init("BossStage");

	p1 = new Player;
	p1->init("BossStage", 0, 1);

	p2 = new Player2;
	p2->init("BossStage", 7, 13);

	b = new Boss;
	b->init();

	mentPosition = PointMake(200, 210);
	mentAlpha = 0;
	img_GameStart = IMAGEMANAGER->findImage("gameStart");
	ending = IMAGEMANAGER->findImage("Victory");

	winPlayer = 0;
	isEnd = 0;
	isIntro = false;
	isStart = false;
	p1->update();
	p2->update();
	itemCount = 0;
	updateItemCount = 0;

	backButton = IMAGEMANAGER->findImage("back_Button");
	SOUNDMANAGER->play("BossScene", 0.5);

	return S_OK;
}
void PVEScene::Intro() //시작전 딜레이
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

void PVEScene::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		if (PtInRect(&RectMake(0, 0, 100, 100), _ptMouse))
			SCENEMANAGER->changeScene("TitleScene");
	if (isEnd == 1)
	{
		alpha += 5;
		if (alpha >= 255)
		{
			alpha = 255;
			if (p1->getEnd() == true && p2->getEnd() == true)
			{
				SCENEMANAGER->changeScene("TitleScene");
				return;
			}
			isEnd = 2;
		}

	}
	if (isEnd == 2)
	{
		if (alpha == 255)
		{
			SOUNDMANAGER->stop("BossScene");
			SOUNDMANAGER->play("Victory");
		}
		alpha -= 5;
		if (alpha < 0)
		{
			alpha = 0;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
			SCENEMANAGER->changeScene("TitleScene");
	}

	if (isEnd >= 1)
		return;

	Scene::update();

	if (isGameStart == true && isStart == false)
		Intro();

	if (isStart == true)
	{
		ITEMMANAGER->update();
		p1->update();
		p2->update();
		b->update();
		if (b->getDead() == true)
			isEnd = 1;

		itemCount++;
		if (itemCount > updateItemCount)
		{
			itemCount = 0;
			updateItemCount = rand() % 1000 + 300;
			int max = rand() % 6;
			for (int i = 0; i < max; i++)
			{
				int tempX = rand() % 13 + 1;
				int tempY = rand() % 8 + 1;
				ITEMMANAGER->setItem(tempX, tempY);
			}
		}
		if (p1->getEnd() == true && p2->getEnd() == true)
		{
			isEnd = 1;
		}
	}
}
void PVEScene::render()
{
	IMAGEMANAGER->findImage("inGameBg")->render(getMemDC());
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
			if (p1->getBullet()->getvBomb()[i]->getArrayY() == y)
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
		for (int i = 0; i < b->getBullet()->getvBomb().size(); i++)
		{
			if (b->getBullet()->getvBomb()[i]->getArrayY() == y)
				b->getBullet()->getvBomb()[i]->render();
		}
		for (int i = 0; i < b->getBullet()->getvBoom().size(); i++)
		{
			if (b->getBullet()->getvBoom()[i]->getArrayY() == y)
				b->getBullet()->getvBoom()[i]->render();
		}
		for (int i = 0; i < ITEMMANAGER->getvItem().size(); i++)
		{
			if (ITEMMANAGER->getvItem()[i]->getArrayY() == y)
				ITEMMANAGER->getvItem()[i]->render();
		}
	}
	b->render();
	if (isStart == false)
		img_GameStart->alphaRender(getMemDC(), mentPosition.x, mentPosition.y, mentAlpha);
	if (isEnd < 3)
		black->alphaRender(getMemDC(), alpha);
	if (isEnd == 2)
		ending->render(getMemDC());
	backButton->render(getMemDC());
	Scene::render();
}
void PVEScene::release()
{
	p1->release();
	p2->release();
	b->release();
	ending		= NULL;
	backButton=  NULL;
	img_GameStart = NULL;

	delete ending;
	delete 	backButton;
	delete img_GameStart;
	SOUNDMANAGER->stop("BossScene");
	SOUNDMANAGER->stop("Victory");
}
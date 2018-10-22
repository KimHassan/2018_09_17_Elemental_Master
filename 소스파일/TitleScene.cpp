#include "stdafx.h"
#include "TitleScene.h"


TitleScene::TitleScene()
{
}


TitleScene::~TitleScene()
{

}

HRESULT TitleScene::init()
{
	title	     = IMAGEMANAGER->findImage("Main_Scene");
	bg			 = IMAGEMANAGER->findImage("Select_Scene");
	leftSelect   = IMAGEMANAGER->findImage("Select_Scene_Left1");
	rightSelect  = IMAGEMANAGER->findImage("Select_Scene_Right1" );
	leftSelect2  = IMAGEMANAGER->findImage("Select_Scene_Left2");
	rightSelect2 = IMAGEMANAGER->findImage("Select_Scene_Right2");
	howToSelect  = IMAGEMANAGER->findImage("Select_Scene_How_To");
	black		 = IMAGEMANAGER->findImage("Black");
	exitButton   = IMAGEMANAGER->findImage("exit_Button");
	backButton   = IMAGEMANAGER->findImage("back_Button");
	howToScene   = IMAGEMANAGER->findImage("HowTo_Scene");


	leftSelectRect = RectMake(340, 151, 297, 364);
	rightSelectRect	= RectMake(643, 150, 317, 334);
	howToSelectRect	= RectMake(256, 203, 70, 43);
	buttonRect = RectMake(0, 0, 100, 100);
	exitRect = RectMake(1180, 0, 100, 100);

	isleftSelect  = false;
	isrightSelect = false;
	ishowToSelect = false;
	ishowToScene  = false;
	isGameStart   = false;

	
	alpha = 0;
	moveScene = 0;
	SOUNDMANAGER->play("TitleScene", 1);
	changeScene = 0;

	return S_OK;
}
void TitleScene::update()
{
	if (changeScene == 0)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			changeScene = 1;
		}

		return;
	}

	if (changeScene == 1)
	{
		alpha += 5;

		if (alpha >= 255)
		{
			alpha = 255;
			changeScene = 2;
		}
	}

	if (changeScene == 2)
	{
		alpha -= 5;
		if (alpha <= 0)
		{
			alpha = 0;
			changeScene = 5;
		}
	}

	if (changeScene < 3)
		return;

	if (isGameStart)
	{
		alpha+=5;
		if (alpha >= 255)
		{
			switch (moveScene)
			{
			case 1:
				SCENEMANAGER->changeScene("PVEScene");
				break;
			case 2:
				SCENEMANAGER->changeScene("PVPScene");
				break;
			}
		}
	}

	else
	{
		if (PtInRect(&exitRect, _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				PostQuitMessage(0);
			}
		}

		if (ishowToScene)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				if (PtInRect(&buttonRect, _ptMouse))
				{
					ishowToScene = false;
				}
			}
			return;
		}
		if (PtInRect(&leftSelectRect, _ptMouse))
		{
			isleftSelect = true;
			isrightSelect = false;
			ishowToSelect = false;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{

				moveScene = 1;
				isGameStart = true;

			}
		}
		else if (PtInRect(&rightSelectRect, _ptMouse))
		{
			isrightSelect = true;
			isleftSelect = false;
			ishowToSelect = false;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{

				moveScene = 2;
				isGameStart = true;

			}
		}
		else if (PtInRect(&howToSelectRect, _ptMouse))
		{
			ishowToSelect = true;
			isleftSelect = false;
			isrightSelect = false;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				ishowToScene = true;
			}
		}

		else
		{
			ishowToSelect = false;
			isleftSelect = false;
			isrightSelect = false;
		}
	}
}
void TitleScene::render()
{
	IMAGEMANAGER->findImage("Black")->render(getMemDC(), 0, 0);

	bg->render(getMemDC());

	if (isleftSelect && !isGameStart)
		leftSelect->render(getMemDC(), 297, 121);
	
	if (isrightSelect && !isGameStart)
		rightSelect->render(getMemDC(), 640, 128);

	if (ishowToSelect)
		howToSelect->render(getMemDC(), 258, 203);

	if (isGameStart && moveScene == 1)
		leftSelect2->render(getMemDC(), 297, 121);

	if (isGameStart && moveScene == 2)
		rightSelect2->render(getMemDC(), 640, 128);

	exitButton->render(getMemDC(), 1180, 0);

	if (ishowToScene)
	{
		howToScene->render(getMemDC(), 0, 0);
		backButton->render(getMemDC(), 0, 0);
	}
	if (changeScene < 2)
		title->render(getMemDC(), 0, 0);
	black->alphaRender(getMemDC(), alpha);
}
void TitleScene::release()
{
	title = NULL;
	bg			= NULL;
	leftSelect	= NULL;
	rightSelect	= NULL;
	howToSelect	= NULL;
	leftSelect2= NULL;
	rightSelect2 = NULL;
	black		= NULL;
	howToScene = NULL;

	delete title;
	delete bg;
	delete leftSelect;
	delete rightSelect;
	delete leftSelect2;
	delete rightSelect2;
	delete howToSelect;
	delete black;
	delete howToScene;

	SOUNDMANAGER->stop("TitleScene");
}
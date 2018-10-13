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
	bg			=  IMAGEMANAGER->findImage("Title_Scene");
	leftSelect  =  IMAGEMANAGER->findImage("Title_Scene_Left");
	rightSelect =  IMAGEMANAGER->findImage("Title_Scene_Right" );
	howToSelect =  IMAGEMANAGER->findImage("Title_Scene_How_To");

	leftSelectRect	= RectMake(70 *2 + 30,35*2,253*2 - 30,290*2);
	rightSelectRect	= RectMake(323*2,40*2,221*2,238*2);
	howToSelectRect	= RectMake(50 *2 + 30,84*2,48 *2,29 *2);

	isleftSelect	=    false;
	isrightSelect	=    false;
	ishowToSelect	=    false;

	black = IMAGEMANAGER->findImage("Black");
	alpha = 0;
	isGameStart = false;
	moveScene = 0;
	return S_OK;
}
void TitleScene::update()
{
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
		}
	}

}
void TitleScene::render()
{

	bg->scaleRender(getMemDC(), 0, 0,2,2);
	if (isleftSelect)
	{
		leftSelect->scaleRender(getMemDC(), 70 * 2, 35 * 2, 2, 2);
	}
	if(isrightSelect)
		rightSelect->scaleRender(getMemDC(), 323*2, 40*2,2,2);
	if(ishowToSelect)
		howToSelect->scaleRender(getMemDC(), 50*2, 84*2,2,2);
	black->alphaRender(getMemDC(), alpha);
}
void TitleScene::release()
{
	bg			= NULL;
	leftSelect	= NULL;
	rightSelect	= NULL;
	howToSelect	= NULL;
	black		= NULL;

	delete bg;
	delete leftSelect;
	delete rightSelect;
	delete howToSelect;
	delete black;
}
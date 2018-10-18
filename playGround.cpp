#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}

playGround::~playGround()
{

}

HRESULT playGround::init()
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("wBlock", "image/Water_Block.bmp", 64, 78, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("wWall",  "image/Water_Wall.bmp", 64, 78, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("wTile1", "image/Water_Tile_1.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("wTile2", "image/Water_Tile_2.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("wTile3", "image/Water_Tile_3.bmp", 64, 64, true, RGB(255, 0, 255));


	IMAGEMANAGER->addImage("fWall1", "image/Fire_Block1.bmp", 64, 78, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fWall2", "image/Fire_Block2.bmp", 64, 78, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fBlock", "image/Fire_Wall.bmp", 64, 78, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fTile", "image/Fire_Tile.bmp", 64, 64, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("Player1_Hp", "image/p1_hp.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Player2_Hp", "image/p2_hp.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("MainScene", "image/MainScene.bmp", 1280, 720, true, RGB(0, 0, 0));

	IMAGEMANAGER->addImage("dead", "image/dead.bmp", 3, 20, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("battle",  "image/battle.bmp", 0, 0, 1536, 79, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("버튼",    "image/button.bmp", 0, 0, 122, 62, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Player1", "image/character1.bmp", 0, 0, 280, 400, 4, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Player2", "image/character2.bmp", 0, 0, 280, 400, 4, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Bub",     "image/BlueBub.bmp", 0, 0, 184, 46, 4, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("Bub2", "image/RedBub.bmp", 0, 0, 184, 46, 4, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("Boom",	   "image/Boomcenter.bmp", 0, 0, 180, 60, 3, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("Boom2", "image/Boomcenter2.bmp", 0, 0, 180, 60, 3, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("Title_Scene", "image/title_scene.bmp", 640, 380, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Title_Scene_Left", "image/left(70,35).bmp", 253, 290, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Title_Scene_Right", "image/right(323,40).bmp", 221, 238, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Title_Scene_How_To", "image/how_to_button(50,84).bmp", 48, 29, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Black", "image/black.bmp", 1280, 720, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("p1Win", "image/p1Win.bmp", 880, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("p2Win", "image/p2Win.bmp", 880, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("gameStart", "image/gameStart.bmp", 880, 300, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Bubble", "image/Bubble.bmp", 64, 73, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Bubble2", "image/Bubble2.bmp", 64, 73, true, RGB(0, 248, 0));
	IMAGEMANAGER->addImage("Bubble3", "image/Bubble3.bmp", 64, 73, true, RGB(0, 78, 248));

	SCENEMANAGER->addScene("TitleScene", new TitleScene);
	SCENEMANAGER->addScene("PVPScene", new PVPScene);
	SCENEMANAGER->addScene("PVEScene", new PVEScene);


	SCENEMANAGER->changeScene("TitleScene");

	


	return S_OK;
}

void playGround::release()
{
	gameNode::release();

}

void playGround::update()
{
	SCENEMANAGER->update();
	

}

void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================================================================
	//IMAGEMANAGER->findImage("배경")->render(getMemDC());

	SCENEMANAGER->render();

	//SetTextColor(getMemDC(), RGB(255, 255, 255));
	TIMEMANAGER->render(getMemDC());
	//==================================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);

}

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
	TILEMANAGER->init("WaterStage");
	p1 = new Player;
	p1->init("WaterStage",3,1);

	p2 = new Player2;
	p2->init("WaterStage",8,3);

	return S_OK;
}
void PVPScene::update()
{
	p1->update();
	p2->update();
}
void PVPScene::render()
{
	TILEMANAGER->render("WaterStage");

	p1->render();

	p2->render();
}
void PVPScene::release()
{

}
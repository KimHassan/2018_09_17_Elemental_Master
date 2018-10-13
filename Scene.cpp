#include "stdafx.h"
#include "Scene.h"


Scene::Scene()
{
}


Scene::~Scene()
{

}

HRESULT Scene::init()		
{
	black = IMAGEMANAGER->findImage("Black");
	alpha = 255;
	isGameStart = false;
	return S_OK;
}
void Scene::gameStart()
{
	alpha -= 3;
	if (alpha <= 0)
		isGameStart = true;
}
void Scene:: update()	
{
	if (isGameStart == false)
		gameStart();
	else
		return;

}
void Scene::render()		
{
	if (isGameStart == false)
		black->alphaRender(getMemDC(), alpha);
}
void Scene::release()	
{

}
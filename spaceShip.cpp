#include "stdafx.h"
#include "spaceShip.h"
#include "enemyManager.h"

spaceShip::spaceShip()
{
}


spaceShip::~spaceShip()
{

}

HRESULT spaceShip::init()
{
	_ship = IMAGEMANAGER->addImage("플레이어", "rocket.bmp", 52, 64, true, RGB(255, 0, 255));
	_ship->setX(WINSIZEX / 2);
	_ship->setY(WINSIZEY / 2 + 200);

	_missile = new missile;
	_missile->init(30, 300);

	_ygh = new yankeeGoHome;
	_ygh->init(30, 500);

	//현재체력과 최대체력은 100으로
	_currentHP = _maxHP = 100;

	//프로그레스 바 할당 후 위치 셋팅
	_hpBar = new progressBar;
	_hpBar->init(_ship->getX(), _ship->getY() - 20, 52, 10);
	_hpBar->setGauge(_currentHP, _maxHP);

	_alphaValue = 0;

	return S_OK;
}

void spaceShip::release()
{
	SAFE_DELETE(_missile);
	SAFE_DELETE(_ygh);
}

void spaceShip::update() 
{
	if ( KEYMANAGER->isStayKeyDown(VK_LEFT) && _ship->getX() > 0 )
	{
		_ship->setX(_ship->getX() - 5);
	}

	if ( KEYMANAGER->isStayKeyDown(VK_RIGHT) && _ship->getX() + _ship->getWidth() < WINSIZEX )
	{
		_ship->setX(_ship->getX() + 5);
	}
	if ( KEYMANAGER->isStayKeyDown(VK_UP) && _ship->getY() > 0 )
	{
		_ship->setY(_ship->getY() - 5);
	}

	if ( KEYMANAGER->isStayKeyDown(VK_DOWN) && _ship->getY() + _ship->getHeight() < WINSIZEY )
	{
		_ship->setY(_ship->getY() + 5);
	}

	if ( KEYMANAGER->isOnceKeyDown(VK_SPACE) ) _missile->fire(_ship->getCenterX(), _ship->getY() - 20);

	if ( KEYMANAGER->isOnceKeyDown('C') ) _ygh->fire(_ship->getCenterX(), _ship->getY() - 15);

	if ( KEYMANAGER->isOnceKeyDown(VK_F11) )
	{
		char temp[128];
		vector<string> vStr;

		vStr.push_back(itoa(_currentHP, temp, 10));
		vStr.push_back(itoa(_maxHP, temp, 10));
		vStr.push_back(itoa(_ship->getX(), temp, 10));
		vStr.push_back(itoa(_ship->getY(), temp, 10));

		TXTDATA->txtSave("세이부.txt", vStr);
	}
	if ( KEYMANAGER->isOnceKeyDown(VK_F12) )
	{
		vector<string> vStr;

		vStr = TXTDATA->txtLoad("세이부.txt");

		_currentHP = (atoi(vStr[0].c_str()));
		_maxHP = (atoi(vStr[1].c_str()));
		_ship->setX(atof(vStr[2].c_str()));
		_ship->setY(atof(vStr[3].c_str()));

	}

	if ( _alphaValue >= 255 ) _alphaValue = 255;
	else _alphaValue++;

	collision();

	_missile->update();
	_ygh->update();

	_hpBar->setX(_ship->getX());
	_hpBar->setY(_ship->getY() - 20);
	_hpBar->setGauge(_currentHP, _maxHP);
	_hpBar->update();
}

void spaceShip::render() 
{
	_ship->alphaRender(getMemDC(), _alphaValue);
	//_ship->render(getMemDC(), _ship->getX(), _ship->getY());
	_missile->render();
	_ygh->render();

	_hpBar->render();
}

void spaceShip::collision(void)
{
	for ( int i = 0; i < _ygh->getVBullet().size(); ++i )
	{

		for ( int j = 0; j < _em->getVMinion().size(); ++j )
		{
			RECT temp;
			if ( IntersectRect(&temp, &_ygh->getVBullet()[i].rc, &_em->getVMinion()[j]->getRect()) )
			{
				_ygh->removeYankee(i);
				_em->removeMinion(j);

				break;
			}
		}
	}

}

void spaceShip::hitDamage(float damage)
{
	_currentHP -= damage;
}

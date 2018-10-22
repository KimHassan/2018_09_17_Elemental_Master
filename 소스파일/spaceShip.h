#pragma once
#include "gameNode.h"
#include "bullets.h"
#include "progressBar.h"

//������� ���ѷ��� ������ ���� ���漱��
class enemyManager;

class spaceShip : public gameNode
{
private:
	image* _ship;
	missile* _missile;
	yankeeGoHome* _ygh;

	enemyManager* _em;

	//���α׷��� ��
	progressBar* _hpBar;
	float _currentHP, _maxHP;

	int _alphaValue;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void collision(void);

	void hitDamage(float damage);

	image* getShipImage() { return _ship; }

	yankeeGoHome* getYankeeMissile() { return _ygh; }

	void setEmMemoryAddressLink(enemyManager* em) { _em = em; }


	spaceShip();
	~spaceShip();
};


#pragma once
#include "gameNode.h"
#include "bullets.h"
#include <vector>
#include "minion.h"

class spaceShip;

class enemyManager : public gameNode
{
private:
	typedef vector<enemy*>				vEnemy;
	typedef vector<enemy*>::iterator	viEnemy;

private:
	vEnemy	_vMinion;
	viEnemy _viMinion;

	bullet* _bullet;

	spaceShip* _ship;

public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void setMinion(void);

	void minionBulletFire(void);

	void collision();

	//�� ����� �Լ�
	void removeMinion(int arrNum);

	void setSpaceShipMemoryAddressLink(spaceShip* ship) { _ship = ship; }

	//�� ���Ϳ� ���� ������
	vector<enemy*> getVMinion() { return _vMinion; }
	vector<enemy*>::iterator getVIMinion() { return _viMinion; }
};


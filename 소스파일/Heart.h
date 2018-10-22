#pragma once
#include "gameNode.h"
class Heart :
	public gameNode
{
	int currentHp;
	int maxHp;
	float x, y;

	image* img;
public:
	HRESULT init(const char* imageName, float _x,float _y,int _maxHp);
	void render();
	void Hit();
	void Heal();
	void release();
	int GetCurrentHp()
	{
		return currentHp;

	}

	Heart();
	~Heart();
};


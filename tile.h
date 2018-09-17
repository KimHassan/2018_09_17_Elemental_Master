#pragma once
#include "gameNode.h"

enum TILESTATE
{
	TILE = 0, //그냥 타일
	BLOCK = 1,	//부술 수 있는 타일
	WALL = 2,		//부술 수 없는 타일

};

class tile : public gameNode
{
private:
	image *image;

	int arrayX, arrayY;//list를 2차원 배열 느낌이 나게 하기 위하여생성 ex : tile[2][0] == it->GetArrayY() == 2 && it->GetArrayX() == 0
	int state;

	float posX;
	float posY;
	float sizeX;
	float sizeY;

	RECT tileRect;

	bool setCheck;

public:
	HRESULT init(const char *imageName, float _posX, float _posY, int _arrayX, int _arrayY, int _state, bool _setCheck);
	void update();
	void render();
	void release();

	bool GetCheck();
	RECT GetTileRect();
	int GetTileState();

public:
	tile();
	virtual ~tile();
};


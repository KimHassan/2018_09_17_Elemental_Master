#pragma once
#include "gameNode.h"

enum TILESTATE
{
	TILE = 0, //�׳� Ÿ��
	BLOCK = 1,	//�μ� �� �ִ� Ÿ��
	WALL = 2,		//�μ� �� ���� Ÿ��

};

class tile : public gameNode
{
private:
	image *image;

	int arrayX, arrayY;//list�� 2���� �迭 ������ ���� �ϱ� ���Ͽ����� ex : tile[2][0] == it->GetArrayY() == 2 && it->GetArrayX() == 0
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


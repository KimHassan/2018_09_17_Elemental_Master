#pragma once
#include "image.h"

#define IMAGEMANAGER imageManager::getSingeton()
#define WINSIZEX 800
#define WINSIZEY 600

//'backBuffer'�� �̸��� ���� �� ��Ʈ���� �ϳ� static���� �����д�
static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);

class gameNode
{
private:
	HDC _hdc;			//����� DC
	bool _managerInit;	//�Ŵ������� init�Ҳ���

public:
	virtual HRESULT init();
	virtual HRESULT init(bool managerInit);
	virtual void release();
	virtual void update();
	virtual void render(void);

	//����ۿ� �����ϱ� ���� ������
	image* getBackBuffer() { return _backBuffer; }

	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

	gameNode();
	virtual ~gameNode();
};


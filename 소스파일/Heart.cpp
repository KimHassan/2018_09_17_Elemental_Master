#include "stdafx.h"
#include "Heart.h"


Heart::Heart()
{
}


Heart::~Heart()
{
}

HRESULT Heart::init(const char* imageName, float _x, float _y, int _maxHp)
{
	x = _x;
	y = _y;

	maxHp = _maxHp;
	currentHp = maxHp;

	img = IMAGEMANAGER->findImage(imageName);

	return S_OK;


}
void Heart::render()
{
	for (int i = 0; i < currentHp; i++)
	{
		img->render(getMemDC(), x, y + i * 50);
	}
}

void Heart::Hit()
{
	currentHp--;

}
void Heart::Heal()
{
	if (currentHp >= maxHp)
		return;
	currentHp++;
}

void Heart::release()
{
	img = NULL;
	delete img;
}
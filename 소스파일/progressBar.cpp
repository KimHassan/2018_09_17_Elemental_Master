#include "stdafx.h"
#include "progressBar.h"


progressBar::progressBar()
{
}


progressBar::~progressBar()
{

}

HRESULT progressBar::init(int x, int y)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, 53 * 3, 5 * 3);
	_progressBarTop		= IMAGEMANAGER->addImage("frontBar", "image/hpBarTop.BMP", x, y, 53* 3, 5 *3, true, RGB(255, 0, 255));
	_progressBarBottom = IMAGEMANAGER->addImage("backBar",
		"image/hpBarBottom.BMP", x, y, 53 * 3, 5 * 3, true, RGB(255, 0, 255));

	//���������� �̹����� ����
	_width = _progressBarTop->getWidth();

	return S_OK;
}

void progressBar::release()									  
{
	
}

void progressBar::update(int x, int y)
{
	_x = x;
	_y = y;
	_rcProgress = RectMakeCenter(_x, _y, _progressBarTop->getWidth(), _progressBarTop->getHeight());
}

void progressBar::render()									  
{
	//���α׷��� �� (��)
	IMAGEMANAGER->render("backBar", 
		getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2,
		0, 0,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());

	//���α׷��� �� (��)
	IMAGEMANAGER->render("frontBar", getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2, 
		0, 0,
		_width, _progressBarBottom->getHeight());
}

//������ �����
void progressBar::setGauge(float currentGauge, float maxGauge)
{
	_width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();
}


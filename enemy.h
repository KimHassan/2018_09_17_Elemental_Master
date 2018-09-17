#pragma once
#include "gameNode.h"

class enemy : public gameNode
{
protected:
	image* _imageName;
	RECT _rc;

	//������ ��ȣ�� ���� �δ� ������ �����ִ� (�� �� ���촺)
	int _currentFrameX;
	int _currentFrameY;

	int _count;				//ī��Ʈ
	int _fireCount;			//�߻� ī��Ʈ
	int _rndFireCount;		//�����ϰ� �߻��ϱ� ���� ī��Ʈ

public:
	enemy();
	~enemy();

	HRESULT init();
	HRESULT init(const char* imageName, POINT position);
	void release(void);
	void update(void);
	void render(void);

	void move(void);
	void draw(void);

	bool bulletCountFire();

	inline RECT getRect() { return _rc; }
};


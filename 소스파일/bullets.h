#pragma once
#include "gameNode.h"
#include <vector>

//�Ѿ� ����ü
struct tagBullet
{
	image* bulletImage;		//�Ѿ��� �̹���
	RECT rc;				//�Ѿ��� ��Ʈ
	float x, y;				//�Ѿ� ��ǥ
	float radius;			//�Ѿ� ������
	float speed;			//�Ѿ� ������
	float angle;			//�Ѿ� �ޱ�
	float fireX, fireY;		//�Ѿ� �߻���ġ
	bool isFire;			//�߻�����
	int count;				//������ ���� ī��Ʈ
};

class bullet : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	const char* _imageName;
	float _range;
	int _bulletMax;

public:
	bullet();
	~bullet();

	HRESULT init(const char* imageName, int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y, float angle, float speed);

	void move(void);

	void removeBullet(int arrNum);

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
};

//������ �صΰ� �߻��ϴ� �̻���
class missile : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;			//��Ÿ�
public:
	missile();
	~missile();

	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y);

	void move(void);
};

//�߻��Ҷ� �����ؼ� �� �̻���
class yankeeGoHome : public gameNode
{
private:
	vector<tagBullet>				_vBullet;
	vector<tagBullet>::iterator		_viBullet;

	float _range;
	int _bulletMax;

public:
	yankeeGoHome();
	~yankeeGoHome();

	HRESULT init(int missileMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y);

	void move();

	void removeYankee(int arrNum);

	//�Ѿ˿� ���� ������
	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }

};
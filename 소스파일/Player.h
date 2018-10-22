#pragma once
#include "p_Player.h"

class Player :
	public p_Player
{

public:
	Player();
	~Player();

	virtual HRESULT init(string _stageName, int _arrayY, int _arrayX);
	virtual void MoveUpdate();
	virtual void FrameUpdate();
	virtual void setBomb();
	virtual void respawn();

};
#pragma once
#include "p_Player.h"
class Player2 :
	public p_Player
{

public:
	Player2();
	~Player2();

	virtual HRESULT init(string _stageName, int _arrayY, int _arrayX);
	virtual void MoveUpdate();
	virtual void FrameUpdate();
	virtual void setBomb();
	virtual void respawn();

};
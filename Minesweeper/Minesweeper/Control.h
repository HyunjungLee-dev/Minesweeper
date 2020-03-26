#pragma once
#include"Mecro.h"



enum KEY
{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT =77
};

// 유저가 조작하는 클래스, 유저가 선택한 좌표를 넘겨주고 블럭타입이 어떤 것인지 확인하고
// 그에 따른 반응을 받아야 한다.

class Control   
{
	int m_ix;
	int m_iy;

public:
	Control();
	~Control();
	void PosControl(int w, int h);
};


#pragma once
#include"Mecro.h"



enum KEY
{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT =77
};

// ������ �����ϴ� Ŭ����, ������ ������ ��ǥ�� �Ѱ��ְ� ��Ÿ���� � ������ Ȯ���ϰ�
// �׿� ���� ������ �޾ƾ� �Ѵ�.

class Control   
{
	int m_ix;
	int m_iy;

public:
	Control();
	~Control();
	void PosControl(int w, int h);
};


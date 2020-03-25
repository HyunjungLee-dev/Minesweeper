#pragma once
#include"Mecro.h"
#include"Draw.h"

//�Ѱ�

#define CONSOLE_W  80
#define CONSOLE_H  30

enum SELECT_TYPE	   // Ÿ��Ʋ�� �������� ���� enum
{
	TYPE_BEGINNER = 1,
	TYPE_INTERMEDIATE,
	TYPE_ADVANCED,
	TYPE_CUSTOM,
	TYPE_EXIT
};

enum START_TYPE	  // init�� �ٸ��� ���ֱ� ���� enum
{
	LEVELSELECT,
	CUSTOMSELECT
};

class Minesweeper
{
	Draw draw;
	const int m_iWidth;
	const int m_iHeight;
public:
	void Display();	  // ��ü
	SELECT_TYPE Tilte();
	void Init(START_TYPE type);
	Minesweeper();
	~Minesweeper();
};


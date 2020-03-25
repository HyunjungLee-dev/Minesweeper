#pragma once
#include"Mecro.h"
#include"Draw.h"

//총괄

#define CONSOLE_W  80
#define CONSOLE_H  30

enum SELECT_TYPE	   // 타이틀의 선택지를 위한 enum
{
	TYPE_BEGINNER = 1,
	TYPE_INTERMEDIATE,
	TYPE_ADVANCED,
	TYPE_CUSTOM,
	TYPE_EXIT
};

enum START_TYPE	  // init를 다르기 해주기 위한 enum
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
	void Display();	  // 전체
	SELECT_TYPE Tilte();
	void Init(START_TYPE type);
	Minesweeper();
	~Minesweeper();
};


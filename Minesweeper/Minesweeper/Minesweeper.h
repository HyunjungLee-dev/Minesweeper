#pragma once
#include"MapFactory.h"
#include"Control.h"


enum SELECT_TYPE	   // 타이틀의 선택지를 위한 enum
{
	TYPE_BEGINNER = 1,
	TYPE_INTERMEDIATE,
	TYPE_ADVANCED,
	TYPE_CUSTOM,
	TYPE_EXIT
};

class Minesweeper
{
	Draw draw;
	Control control;
	Map* map;
	MapFactory* factory;
	SELECT_TYPE m_eType;
	 int m_iWidth;
	 int m_iHeight;
public:
	void Display();	  
	void Tilte();
	void Init();
	void CreateMap();
	void PrintMap();
	void Play();
	Minesweeper();
	~Minesweeper();
};


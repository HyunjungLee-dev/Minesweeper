#include "Minesweeper.h"



Minesweeper::Minesweeper():m_iHeight(0),m_iWidth(0)
{
}											 

void Minesweeper::Init()
{
	system("cls");

	if (m_eType == TYPE_BEGINNER)
	{
		m_iWidth = 9; m_iHeight = 9;
	}
	else if (m_eType == TYPE_INTERMEDIATE)
	{
		m_iWidth = 16; m_iHeight = 16;
	}
	else if (m_eType == TYPE_ADVANCED)
	{
		m_iWidth = 30; m_iHeight = 16;
	}
	else if (m_eType == TYPE_CUSTOM)
	{
		;
	}
	CreateMap();
	PrintMap();
}

void Minesweeper::Tilte()
{
	int Select;

	int x = CONSOLE_W * 0.5;  
	int y = CONSOLE_H * 0.2;// °¡µ¶¼º

	draw.DrawMidText("[Mineswweeper]", x, y);
	draw.DrawMidText("select a difficulty level", x, y+2);
	draw.DrawMidText("1.beginner", x, y+4);
	draw.DrawMidText("2.intermediate", x, y+6);
	draw.DrawMidText("3.advanced", x, y+8);
	draw.DrawMidText("4.user custom", x, y+10);
	draw.DrawMidText("5.exit", x, y + 12);
	draw.DrawMidText("select : ", x, y + 14);
	cin >> Select;
	m_eType = (SELECT_TYPE)Select;

}

void  Minesweeper::CreateMap()
{
	map = factory->makeMap();

	for (int x = 0; x < m_iWidth; x++)
	{
		for (int y = 0; y < m_iHeight; y++)
		{
			Block* block;
			block = factory->makeNone();
			block->SetBlock(x,y);
			map->AddBlock(block);
		}
	}
}

void Minesweeper::PrintMap()
{

	map->Print();
}

void Minesweeper::Play()
{
	while (1)
	{
		control.PosControl(m_iWidth, m_iHeight);
	}
}



void Minesweeper::Display()
{
	Tilte();
	switch (m_eType)
	{
	case TYPE_BEGINNER:
	case TYPE_INTERMEDIATE:
	case TYPE_ADVANCED:
	case TYPE_CUSTOM:
		Init();
		Play();
		break;
	case TYPE_EXIT:
		return;
	default:
		break;
	}
}



Minesweeper::~Minesweeper()
{
	delete factory;
}

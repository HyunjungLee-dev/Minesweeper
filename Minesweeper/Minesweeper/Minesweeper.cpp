#include "Minesweeper.h"



Minesweeper::Minesweeper():m_iHeight(0),m_iWidth(0)
{
}											 

void Minesweeper::Init(START_TYPE type)
{
	if (type == LEVELSELECT)
		;
	else if (type == CUSTOMSELECT)
		;
}

SELECT_TYPE Minesweeper::Tilte()
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
	return (SELECT_TYPE)Select;

}

void Minesweeper::Display()
{
	switch (Tilte())
	{
	case TYPE_BEGINNER:
		break;
	case TYPE_INTERMEDIATE:
		break;
	case TYPE_ADVANCED:
		break;
	case TYPE_CUSTOM:
		break;
	case TYPE_EXIT:
		return;
	default:
		break;
	}
}



Minesweeper::~Minesweeper()
{
}

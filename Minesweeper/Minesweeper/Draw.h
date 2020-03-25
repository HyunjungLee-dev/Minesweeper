#pragma once
#include"Mecro.h"
class Draw
{
public:
	void DrawMidText(string str, int x, int y);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	Draw();
	~Draw();
};


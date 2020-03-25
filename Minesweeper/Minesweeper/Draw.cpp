#include "Draw.h"



Draw::Draw()
{
}

void Draw::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}

Draw::~Draw()
{
}

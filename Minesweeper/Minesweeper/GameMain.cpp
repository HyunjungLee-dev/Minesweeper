#include"Minesweeper.h"

void main()
{
	//_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 979;	  디버그 체크용
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", CONSOLE_H, CONSOLE_W);
	system(buf);
	Minesweeper minesweeper;
	minesweeper.Display();

}
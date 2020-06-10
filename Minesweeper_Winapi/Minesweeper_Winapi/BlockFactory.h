#pragma once
#include"Block.h"

class BlockFactory
{
public:
	None* MakeNone();
	//Click* MakeClick();
	Number* MakeNumber(IMG type);
	Flag* MakeFlag();
	Mine* MakeMine();

	BlockFactory();
	~BlockFactory();
};


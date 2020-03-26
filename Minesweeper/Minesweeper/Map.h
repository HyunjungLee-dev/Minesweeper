#pragma once
#include"Block.h"

class Map
{
	list<Block*> map;
	int m_iMineCount;
	int m_iNoneCount;
	int m_iFlagCount;
	int m_iQmarkCount;

public:
	Map();
	~Map();
	void AddBlock(Block* block);
	void Count(int num, BLOCKTYPE btype);
	void Print();
};


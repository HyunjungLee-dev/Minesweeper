#include "Map.h"



Map::Map()
{
}

void Map::AddBlock(Block* block)
{
	Count(1, block->GetType());
	map.push_back(block);
}

void Map::Count(int num, BLOCKTYPE btype)
{
	if (btype == BLOCKTYPE_NONE)
		m_iNoneCount + (num);
	else if (btype == BLOCKTYPE_FLAG)
		m_iFlagCount + (num);
	else if (btype == BLOCKTYPE_QMARK)
		m_iQmarkCount + (num);
	else if (btype == BLOCKTYPE_MINE)
		m_iMineCount + (num);
}

void Map::Print()
{
	list<Block*>::iterator begin = map.begin();
	list<Block*>::iterator end = map.end();
	if (!map.empty())
	{
		while (begin!=end)
		{
			(*begin)->DrawBlock();
			begin++;
		}
	}
}


Map::~Map()
{
}

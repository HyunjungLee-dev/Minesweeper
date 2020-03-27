#include "Map.h"



Map::Map() : m_iMineCount(0), m_iNoneCount(0)
{
}

void Map::AddBlock(Block* block)
{
	m_iNoneCount++;
	map.push_back(block);
}	

void Map::StartBlock(int x, int y, int w, int h)
{	
	

	if (x < 0 || y < 0 || x > w || y >h)
		return;
	else if (CheckBlock(x, y) == true)
	{ 
		StartBlock(x+1,y,w,h);
	}
	else
		return;
}

void Map::ChageBlock(Block* block)
{
	list<Block*> tmp;
	tmp.push_back(block);
	list<Block*>::iterator begin = map.begin();
	list<Block*>::iterator end = map.end();

	if (!map.empty())
	{
		while (begin != end)
		{
			if ((*begin)->GetX() == (*tmp.begin())->GetX() && (*begin)->GetY() == (*tmp.begin())->GetY())
			{
				map.splice(begin, tmp,tmp.begin());
				m_iMineCount++;
				map.erase(begin);
				break;
			}
			begin++;
		}
	}
}


void Map::Print(bool benter)
{
	list<Block*>::iterator begin = map.begin();
	list<Block*>::iterator end = map.end();
	if (!map.empty())
	{
		while (begin!=end)
		{
			(*begin)->DrawBlock(benter);
			begin++;
		}
	}
}

bool Map::CheckBlock(int x, int y)
{
	list<Block*>::iterator begin = map.begin();
	list<Block*>::iterator end = map.end();

	if (!map.empty())
	{
		while (begin != end)
		{
			if ((*begin)->GetX() == x && (*begin)->GetY() == y)
			{
				if ((*begin)->GetType() == BLOCKTYPE_MINE)
				{
					return false;
				}
				(*begin)->DrawBlock(true);
				m_iNoneCount--;
				SearchMine(x, y);
				break;
			}
			begin++;
		}
		return true;
	}
}


void Map::SearchMine(int x, int y)
{
	list<Block*>::iterator begin = map.begin();
	list<Block*>::iterator end = map.end();

	int mineNum = 0;
	if (!map.empty())
	{
		while (begin != end)
		{
			if ((*begin)->GetX() == x-1&& (*begin)->GetY() == y+1 && (*begin)->GetType() == BLOCKTYPE_MINE) mineNum++; //�ϼ�
			if ((*begin)->GetX() == x  && (*begin)->GetY() == y + 1 && (*begin)->GetType() == BLOCKTYPE_MINE) mineNum++; //��
			if ((*begin)->GetX() == x +1 && (*begin)->GetY() == y + 1 && (*begin)->GetType() == BLOCKTYPE_MINE) mineNum++; //�ϵ�
			if ((*begin)->GetX() == x - 1 && (*begin)->GetY() == y  && (*begin)->GetType() == BLOCKTYPE_MINE) mineNum++; //��
			if ((*begin)->GetX() == x +1 && (*begin)->GetY() == y  && (*begin)->GetType() == BLOCKTYPE_MINE) mineNum++; //��
			if ((*begin)->GetX() == x - 1 && (*begin)->GetY() == y - 1 && (*begin)->GetType() == BLOCKTYPE_MINE) mineNum++; //����
			if ((*begin)->GetX() == x  && (*begin)->GetY() == y - 1 && (*begin)->GetType() == BLOCKTYPE_MINE) mineNum++; //��
			if ((*begin)->GetX() == x + 1 && (*begin)->GetY() == y - 1 && (*begin)->GetType() == BLOCKTYPE_MINE)//����
			{
				mineNum++;
			}
			begin++;
		}
		if (mineNum == 0)
			return;
		else
			draw.DrawPoint(to_string(mineNum),x + 1, y + 1);
	}
 }

Map::~Map()
{
	for (list<Block*>::iterator it = map.begin(); it != map.end(); it++)
		delete (*it);
	map.clear();
}

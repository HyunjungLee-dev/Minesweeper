#include "Map.h"



Map::Map() 
{
	m_iMineCount = 0;
	m_iNoneCount = 0;
}

void Map::Init(int startX, int startY,HDC hdc)
{
	m_backbufferDC = hdc;
	m_MineCheck = false;

	for (int x = 1; x <= WIDTH; x++)
	{
		for (int y = 1; y <= HEIGHT; y++)
		{
			Block* block;
			block = m_pFactory->MakeNone();

			float sizeX = startX + BitmapManager::GetSingleton()->GetImg(block->GetType())->GetSize().cx  * x ;
			float sizeY = startY + BitmapManager::GetSingleton()->GetImg(block->GetType())->GetSize().cy * y;

			block->Setpos(sizeX, sizeY);
			block->SetRect();
			m_iNoneCount++;
			m_pMap.push_back(block);
		}
	}

	for (int i = 0; i < DEFULTMINE; i++)
	{
		Block* block;
		block = m_pFactory->MakeMine();
		int randx = startX  + BitmapManager::GetSingleton()->GetImg(block->GetType())->GetSize().cx * (rand() % 30);
		int randy = startY  + BitmapManager::GetSingleton()->GetImg(block->GetType())->GetSize().cy * (rand() % 16);
		block->Setpos(randx, randy);
		ChageBlock(block);
		m_iMineCount++;
	}
}

void Map::ChageBlock(Block* block)
{
	vector<Block*>::iterator iter = m_pMap.begin();
	vector<Block*>::iterator end = m_pMap.end();

	if (!m_pMap.empty())
	{
		while (iter != end)
		{
			if ((*iter)->GetPos().m_fX == block->GetPos().m_fX &&
				(*iter)->GetPos().m_fY == block->GetPos().m_fY)
			{
				(*iter) = block;
				(*iter)->SetRect();
				break;
			}
			iter++;
		}
	}

}

bool Map::CheckBlock(int x, int y)	  //Àç±Í
{
	vector<Block*>::iterator iter = m_pMap.begin();
	vector<Block*>::iterator end = m_pMap.end();

	if (!m_pMap.empty())
	{
		while (iter != end)
		{
			if ((*iter)->GetPos().m_fX == x && (*iter)->GetPos().m_fY== y)
			{
				if ((*iter)->GetType() == IMG_MINE)
				{
					(*iter)->SetClick(true);
					return false;
				}
				else
				{
					int sizeX = BitmapManager::GetSingleton()->GetImg((*iter)->GetType())->GetSize().cx;
					int sizeY = BitmapManager::GetSingleton()->GetImg((*iter)->GetType())->GetSize().cy;

					(*iter)->SetClick(true);
					m_iNoneCount--;
					int Num = SearchMine(x, y);
					if (Num == 0)
					{
						for (int i = -1; i <= 1; i++)
						{
							for (int j = -1; j <= 1; j++)
							{
								if (CheckBlock(x + i * sizeX, y + j * sizeY))
									break;
							}
						}
					}
					else 
					{
						return true;
					}
				}
			}
			iter++;
		}
		return true;
	}
}

int Map::SearchMine(int x, int y)
{
	vector<Block*>::iterator iter = m_pMap.begin();
	vector<Block*>::iterator end = m_pMap.end();

	int mineNum = 0;
	if (!m_pMap.empty())
	{
		while (iter != end)
		{
			int sizeX = BitmapManager::GetSingleton()->GetImg((*iter)->GetType())->GetSize().cx;
			int sizeY = BitmapManager::GetSingleton()->GetImg((*iter)->GetType())->GetSize().cy;

			if ((*iter)->GetPos().m_fX == x - sizeX && (*iter)->GetPos().m_fY == y + sizeY && (*iter)->GetType() == IMG_MINE) mineNum++; //ºÏ¼­
			if ((*iter)->GetPos().m_fX == x && (*iter)->GetPos().m_fY == y + sizeY && (*iter)->GetType() == IMG_MINE) mineNum++; //ºÏ
			if ((*iter)->GetPos().m_fX == x + sizeX && (*iter)->GetPos().m_fY == y + sizeY && (*iter)->GetType() == IMG_MINE) mineNum++; //ºÏµ¿
			if ((*iter)->GetPos().m_fX == x - sizeX && (*iter)->GetPos().m_fY == y && (*iter)->GetType() == IMG_MINE) mineNum++; //¼­
			if ((*iter)->GetPos().m_fX == x + sizeX && (*iter)->GetPos().m_fY == y && (*iter)->GetType() == IMG_MINE) mineNum++; //µ¿
			if ((*iter)->GetPos().m_fX == x - sizeX && (*iter)->GetPos().m_fY == y - sizeY && (*iter)->GetType() == IMG_MINE) mineNum++; //³²¼­
			if ((*iter)->GetPos().m_fX == x && (*iter)->GetPos().m_fY == y - sizeY && (*iter)->GetType() == IMG_MINE) mineNum++; //³²
			if ((*iter)->GetPos().m_fX == x + sizeX && (*iter)->GetPos().m_fY == y - sizeY && (*iter)->GetType() == IMG_MINE)//³²µ¿
			{
				mineNum++;
			}
			iter++;
		}
		if (mineNum == 0)
			return mineNum;
		else
		{
			Block* block;
			block = m_pFactory->MakeNumber((IMG)mineNum);
			block->Setpos(x, y);
			block->SetClick(true);
			ChageBlock(block);
			return mineNum;
		}
	}
}

bool Map::Collision(POINT pos, MOUSE button)
{
	for (int i = 0; i < m_pMap.size(); i++)
	{
		if (PtInRect(&m_pMap.at(i)->GetRct(), pos))
		{
			if (button == LBUTTONDOWN)
			{
				if (!CheckBlock(m_pMap.at(i)->GetPos().m_fX, m_pMap.at(i)->GetPos().m_fY))
				{
					return false;
				}

			}
			else
			{
				if (!m_pMap.at(i)->GetClick())
				{
					m_BlockPos = m_pMap.at(i)->GetPos();
					return true;
				}
				else
					return false;
			}
		}
	}
}

void Map::OpenMine()
{
	for (int i = 0; i < m_pMap.size(); i++)
	{
		if(m_pMap.at(i)->GetType() == IMG_MINE)
			m_pMap.at(i)->SetClick(true);
	}
}

void Map::Render()
{
	BitmapManager::GetSingleton()->GetImg(IMG_BACK)->Draw(m_backbufferDC, 0, 0);
	for (int i = 0; i < m_pMap.size(); i++)
	{
		m_pMap.at(i)->DrawBlock(m_backbufferDC);
	}
}

void Map::Release()
{
	for (vector<Block*>::iterator it = m_pMap.begin(); it != m_pMap.end(); it++)
	{
		delete (*it);
	}
	m_pMap.clear();
}


Map::~Map()
{
}

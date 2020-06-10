#pragma once
#include"BlockFactory.h"

class Map
{
	vector<Block*> m_pMap;
	BlockFactory* m_pFactory;

	int m_iMineCount;
	int m_iNoneCount;


	HDC m_backbufferDC;

public:
	void Init(int startX, int startY, HDC hdc);

	bool CheckBlock(int x, int y);
	void ChageBlock(Block* block);
	int SearchMine(int x, int y);

	bool Collision(POINT pos);

	void Render();
	void Release();
	Map();
	~Map();
	
};


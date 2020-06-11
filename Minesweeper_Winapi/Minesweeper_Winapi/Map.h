#pragma once
#include"BlockFactory.h"

class Map
{
	vector<Block*> m_pMap;
	BlockFactory* m_pFactory;

	int m_iMineCount;
	int m_iNoneCount;

	bool m_MineCheck;

	HDC m_backbufferDC;
	POS m_BlockPos;

public:
	void Init(int startX, int startY, HDC hdc);

	bool CheckBlock(int x, int y);
	void ChageBlock(Block* block);
	int SearchMine(int x, int y);
	void OpenMine();

	bool Collision(POINT pos, MOUSE button);

	void Render();
	void Release();

	POS GetBlockPos() { return m_BlockPos; }
	bool GetMineCheck() {return m_MineCheck;}
	Map();
	~Map();
	
};


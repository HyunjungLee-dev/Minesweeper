#pragma once
#include"BlockFactory.h"

class Map
{

	vector<Block*> m_pMap;
	BlockFactory* m_pFactory;

	int m_iNoneCount;
	int m_iMineCount;
	bool m_MineCheck;


	HDC m_backbufferDC;
	POS m_BlockPos;

public:
	void Init(int startX, int startY, HDC hdc);
	void SetMine(int startX, int startY);


	bool CheckBlock(int x, int y);
	void ChageBlock(Block* block);
	bool SearchMine(int x, int y);
	int MineNumber(int x, int y);
	void OpenMine();
	void CloseBlock();

	bool Collision(POINT pos, MOUSE button);

	void Render();
	void Release();

	POS GetBlockPos() { return m_BlockPos; }
	bool GetMineCheck() {return m_MineCheck;}
	int GetNoneCount() { return m_iNoneCount; }
	Map();
	~Map();
	
};


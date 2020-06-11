#pragma once
#include"Map.h"
class GameManager
{
private:
	HWND m_hWnd;
	HDC m_backbufferDC;
	RECT m_ClientRct;

	int m_iFlagCount;
	bool m_bGOver;
	BlockFactory*  m_factory;
	vector<Block*> m_FlagList;

	Map m_Map;
public:
	//Init
	void Init(HWND hWnd);

	//Update
	void Update();
	void Collision(POINT pos);
	void PutFlag(POINT pos);


	//Render
	void Render();
	void FlagRender();

	//Release
	void Release();

	GameManager();
	~GameManager();
};


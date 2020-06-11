#pragma once
#include"Map.h"
class GameManager
{
private:
	HWND m_hWnd;
	HDC m_backbufferDC;
	RECT m_ClientRct;

	int m_iFlagCount;
	int  m_iMineCount;

	int m_SecTime;
	DWORD	m_dwLastTime;
	DWORD	m_dwCurTime;
	float	m_fDeltaTime;

	GAMESTATE m_eState;

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
	GAMESTATE StateCheck();

	//Render
	void Render();
	void FlagRender();
	void Text();

	//Release
	void Release();

	GameManager();
	~GameManager();
};


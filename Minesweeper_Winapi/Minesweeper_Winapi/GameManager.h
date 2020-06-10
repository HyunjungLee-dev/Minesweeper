#pragma once
#include"Map.h"
class GameManager
{
private:
	HWND m_hWnd;
	HDC m_backbufferDC;
	RECT m_ClientRct;

	bool m_bGameover;

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


	//Release
	void Release();

	GameManager();
	~GameManager();
};


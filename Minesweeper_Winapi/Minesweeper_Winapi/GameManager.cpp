#include "GameManager.h"



GameManager::GameManager()
{
}

void GameManager::Init(HWND hWnd)
{
	m_hWnd = hWnd;
	GetClientRect(m_hWnd, &m_ClientRct);
	BitmapManager::GetSingleton()->Init(hWnd, m_ClientRct.right, m_ClientRct.bottom);
	m_backbufferDC = BitmapManager::GetSingleton()->GetBufferDC();

	m_bGameover = false;

	m_Map.Init(m_ClientRct.right * 0.02 , m_ClientRct.bottom * 0.04,m_backbufferDC);
}

void GameManager::Update()
{
	Render();
}

void GameManager::Collision(POINT pos)
{
	m_Map.Collision(pos);
}

void GameManager::PutFlag(POINT pos)
{
}


void GameManager::Render()
{
	HDC hdc = GetDC(m_hWnd);
	m_Map.Render();
	BitmapManager::GetSingleton()->GetBackBuffer().Draw(hdc,0,0);
	ReleaseDC(m_hWnd, hdc);
}

void GameManager::Release()
{
	m_Map.Release();
	BitmapManager::GetSingleton()->Release();
	BitmapManager::Release();
}

GameManager::~GameManager()
{
}

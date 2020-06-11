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
	m_bGOver = false;


	m_Map.Init(m_ClientRct.right * 0.02 , m_ClientRct.bottom * 0.04,m_backbufferDC);
}

void GameManager::Update()
{
	if (m_bGOver)
	{
		m_Map.OpenMine();
	}
	Render();
}

void GameManager::Collision(POINT pos)
{
	if (m_Map.Collision(pos, RBUTTONDOWN))
	{
		for (vector<Block*>::iterator iter = m_FlagList.begin(); iter != m_FlagList.end(); iter++)
		{
			if ((*iter)->GetPos().m_fX == m_Map.GetBlockPos().m_fX &&
				(*iter)->GetPos().m_fY == m_Map.GetBlockPos().m_fY) // 이미 깃발이 있다면
			{
				return;
			}
		}
	}

	if (!m_Map.Collision(pos, LBUTTONDOWN))
		m_bGOver = true;
}

void GameManager::PutFlag(POINT pos)
{
	if (m_Map.Collision(pos, RBUTTONDOWN))
	{

		for(vector<Block*>::iterator iter=m_FlagList.begin(); iter != m_FlagList.end(); iter++)
		{	
			if ((*iter)->GetPos().m_fX == m_Map.GetBlockPos().m_fX &&
				(*iter)->GetPos().m_fY == m_Map.GetBlockPos().m_fY) // 이미 깃발이 있다면
			{
				m_iFlagCount--;
				m_FlagList.erase(iter);
				return;
			}
		}

		Block* block;
		block = m_factory->MakeFlag();
		block->Setpos(m_Map.GetBlockPos().m_fX, m_Map.GetBlockPos().m_fY);
		block->SetRect();
		m_FlagList.push_back(block);
		m_iFlagCount++;
	}
}

void GameManager::FlagRender()
{
	for (vector<Block*>::iterator iter = m_FlagList.begin(); iter != m_FlagList.end(); iter++)
	{
		(*iter)->DrawBlock(m_backbufferDC);
	}
}

void GameManager::Render()
{
	HDC hdc = GetDC(m_hWnd);
	m_Map.Render();
	FlagRender();
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

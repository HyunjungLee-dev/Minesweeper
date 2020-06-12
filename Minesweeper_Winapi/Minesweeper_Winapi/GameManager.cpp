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


	m_iFlagCount = 0;
	m_iMineCount = DEFULTMINE;
	m_SecTime = 0;
	m_eState = GAME_WAIT;

	m_dwLastTime = GetTickCount();
	m_dwCurTime = GetTickCount();


	m_Map.Init(m_ClientRct.right * 0.02 , m_ClientRct.bottom * 0.04,m_backbufferDC);

}

void GameManager::ReStart(GAMESTATE state)
{
	m_iFlagCount = 0;
	m_iMineCount = DEFULTMINE;
	m_SecTime = 0;
	m_eState = GAME_WAIT;

	m_dwLastTime = GetTickCount();
	m_dwCurTime = GetTickCount();


	if (state == GAME_REPLAY)
	{
		m_FlagList.clear();
		m_Map.CloseBlock();
	}
	else if (state == GAME_RESET)
	{
		m_FlagList.clear();
		m_Map.Release();
		m_Map.Init(m_ClientRct.right * 0.02, m_ClientRct.bottom * 0.04, m_backbufferDC);
	}
}

void GameManager::Update()
{
	m_dwCurTime = GetTickCount();
	m_fDeltaTime = (m_dwCurTime - m_dwLastTime) / 1000.0f;

	if (m_fDeltaTime > 1.0f)
	{
		if(m_eState == GAME_PLAY && m_SecTime < 999)
			m_SecTime++;
		m_dwLastTime = m_dwCurTime;
	}

	if (m_Map.GetNoneCount() == m_FlagList.size() && m_iMineCount == 0)
		m_eState = GAME_WIN;

	if (m_eState == GAME_DIE)
	{
		m_Map.OpenMine();
	}
	Render();
}

GAMESTATE GameManager::StateCheck()
{
	return 	m_eState;
}

void GameManager::Collision(POINT pos)
{
	if (m_Map.Collision(pos, RBUTTONDOWN))
	{
		for (vector<Block*>::iterator iter = m_FlagList.begin(); iter != m_FlagList.end(); iter++)
		{
			if ((*iter)->GetPos().m_fX == m_Map.GetBlockPos().m_fX &&
				(*iter)->GetPos().m_fY == m_Map.GetBlockPos().m_fY) 
			{
				return;
			}
		}
	}

	if (!m_Map.Collision(pos, LBUTTONDOWN))
		m_eState = GAME_DIE;
	else
		m_eState = GAME_PLAY;
}

void GameManager::PutFlag(POINT pos)
{
	if (m_Map.Collision(pos, RBUTTONDOWN))
	{
		m_eState = GAME_PLAY;
		for(vector<Block*>::iterator iter=m_FlagList.begin(); iter != m_FlagList.end(); iter++)
		{	
			if ((*iter)->GetPos().m_fX == m_Map.GetBlockPos().m_fX &&
				(*iter)->GetPos().m_fY == m_Map.GetBlockPos().m_fY) 
			{
				m_iFlagCount--;
				m_iMineCount++;
				m_FlagList.erase(iter);
				return;
			}
		}

		if (m_iMineCount != 0)
		{
			Block* block;
			block = m_factory->MakeFlag();
			block->Setpos(m_Map.GetBlockPos().m_fX, m_Map.GetBlockPos().m_fY);
			block->SetRect();
			m_FlagList.push_back(block);
			m_iFlagCount++;
			m_iMineCount--;
		}
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
	Text();
	BitmapManager::GetSingleton()->GetBackBuffer().Draw(hdc,0,0);
	ReleaseDC(m_hWnd, hdc);
}

void GameManager::Text()
{

	SetBkMode(m_backbufferDC, TRANSPARENT);
	SetTextColor(m_backbufferDC, 0xffffff);
	SetTextAlign(m_backbufferDC, TA_CENTER);

	TCHAR str[128];

	wsprintf(str, TEXT("%d"), m_SecTime);
	TextOut(m_backbufferDC, m_ClientRct.right * 0.21, m_ClientRct.bottom * 0.94, str, lstrlen(str));


	wsprintf(str, TEXT("%d"), m_iMineCount);
	TextOut(m_backbufferDC, m_ClientRct.right * 0.78, m_ClientRct.bottom * 0.94, str, lstrlen(str));
}

void GameManager::Release()
{
	m_FlagList.clear();
	m_Map.Release();
	BitmapManager::GetSingleton()->Release();
	BitmapManager::Release();
}

GameManager::~GameManager()
{
}

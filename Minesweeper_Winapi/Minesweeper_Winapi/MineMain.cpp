#include"GameManager.h"
#include"resource.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK EndDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Áö·Ú Ã£±â");

GameManager g_game;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;
	RECT rt = { 0, 0, 870 ,530 };
	srand((unsigned int)time(NULL));
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(g_hInst, MAKEINTRESOURCE(IDI_MINE));
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, rt.right - rt.left, rt.bottom - rt.top, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	//Init
	g_game.Init(hWnd);
	while (true)
	{
		if (PeekMessage(&Message, NULL, 0, 0, PM_REMOVE))
		{
			if (Message.message == WM_QUIT)
				break;
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
		else
		{
			//Update
			g_game.Update();
		}

	}
	//Release
	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	 POINT pos;
	 pos.x = LOWORD(lParam);
	 pos.y = HIWORD(lParam);

	switch (iMessage)
	{
	case WM_LBUTTONDOWN:
		g_game.Collision(pos);
		if (g_game.StateCheck() == GAME_DIE)
			DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, EndDlgProc);
		return 0;
	case WM_RBUTTONDOWN:
		g_game.PutFlag(pos);
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_HELP:
			ShellExecute(NULL, TEXT("open"), TEXT("https://support.microsoft.com/hub/4338813/windows-help"), NULL,NULL, SW_SHOW);
			break;
		case ID_ANOTHER:
			ShellExecute(NULL, TEXT("open"), TEXT("https://www.microsoft.com/ko-kr/store/games/windows"), NULL, NULL, SW_SHOW);
			break;
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

BOOL CALLBACK EndDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

}
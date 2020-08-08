#include<windows.h>
#include<stdlib.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

DWORD WINAPI ThreadProcOne(LPVOID);
DWORD WINAPI ThreadProcTwo(LPVOID);
DWORD WINAPI ThreadProcThree(LPVOID);
DWORD WINAPI ThreadProcFour(LPVOID);

BOOL gbDone = FALSE;
RECT gRect;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndClass;
	MSG iMsg;
	HWND hwnd;
	TCHAR szAppName[] = TEXT("MyApplication");

	wndClass.cbClsExtra = 0;
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = szAppName;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&wndClass);

	hwnd = CreateWindow(szAppName, TEXT("MultiThrading Program"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	UpdateWindow(hwnd);
	ShowWindow(hwnd, iCmdShow);

	while (GetMessage(&iMsg, NULL, 0, 0))
	{
		TranslateMessage(&iMsg);
		DispatchMessage(&iMsg);
	}

	return iMsg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HANDLE hThreadOne = NULL;
	static HANDLE hThreadTwo = NULL;
	static HANDLE hThreadThree = NULL;
	static HANDLE hThreadFour = NULL;
	switch (iMsg)
	{
	case WM_CREATE:
		GetClientRect(hwnd, &gRect);
		hThreadOne = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProcOne, (LPVOID)hwnd, 0, NULL);
		hThreadTwo = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProcTwo, (LPVOID)hwnd, 0, NULL);
		hThreadThree = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProcThree, (LPVOID)hwnd, 0, NULL);
		hThreadFour = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProcFour, (LPVOID)hwnd, 0, NULL);
		break;
	
	case WM_SIZE:
		GetClientRect(hwnd, &gRect);
		break;

	case WM_DESTROY:
		if (hThreadOne)
		{
			CloseHandle(hThreadOne);
			hThreadOne = NULL;
		}
		if (hThreadTwo)
		{
			CloseHandle(hThreadTwo);
			hThreadTwo = NULL;
		}
		if (hThreadThree)
		{
			CloseHandle(hThreadThree);
			hThreadThree = NULL;
		}
		if (hThreadFour)
		{
			CloseHandle(hThreadFour);
			hThreadFour = NULL;
		}

		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

DWORD WINAPI ThreadProcOne(LPVOID Param)
{
	HDC hdc;
	long i;
	TCHAR str[255];
	hdc = GetDC((HWND)Param);
	SetBkColor(hdc, RGB(0, 0, 0));
	SetTextColor(hdc, RGB(0, 255, 0));

	for (i = 0; i < 429496729; i++)
	{
		wsprintf(str, TEXT("Thread One : Increasing Order: %ld"), i);
		TextOut(hdc, 5, 5, str, wcslen(str));

		wsprintf(str, TEXT("Thread Two : Decreasing Order: %ld"), 429496729 - i);
		TextOut(hdc, 5, 25, str, wcslen(str));
	}
	ReleaseDC((HWND)Param, hdc);
	return 0;
}

DWORD WINAPI ThreadProcTwo(LPVOID Param)
{
	HDC hdc;
	HBRUSH hBrush;
	RECT rc;

	hdc = GetDC((HWND)Param);
	while (gbDone == FALSE)
	{
		rc.left = gRect.right / 2 + (rand() % gRect.right / 2);
		rc.top = rand() % gRect.bottom / 2;
		rc.right = gRect.right / 2 + (rand() % gRect.right / 20);
		rc.bottom = rand() % gRect.bottom / 2;

		hBrush = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
		FillRect(hdc, &rc, hBrush);
		DeleteObject(hBrush);
	}
	ReleaseDC((HWND)Param, hdc);
	return 0;
}

DWORD WINAPI ThreadProcThree(LPVOID Param)
{
	HDC hdc;
	HBRUSH hBrush;
	RECT rc;

	hdc = GetDC((HWND)Param);
	while (gbDone == FALSE)
	{
		rc.left = gRect.right / 2 + (rand() % gRect.right / 2);
		rc.top = gRect.bottom / 2 + rand() % gRect.bottom / 2;
		rc.right = gRect.right / 2 + (rand() % gRect.right / 2);
		rc.bottom = gRect.bottom / 2 + rand() % gRect.bottom / 2;

		hBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		SelectObject(hdc, hBrush);
		Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
		DeleteObject(SelectObject(hdc, GetStockObject(WHITE_BRUSH)));
	}
	ReleaseDC((HWND)Param, hdc);
	return 0;
}

DWORD WINAPI ThreadProcFour(LPVOID Param)
{
	HDC hdc;
	HBRUSH hBrush;
	RECT rc;

	hdc = GetDC((HWND)Param);
	while (gbDone == FALSE)
	{
		rc.left = gRect.left/2 + (rand() % gRect.right / 2);
		rc.top = gRect.bottom / 2 + rand() % gRect.bottom / 2;
		rc.right = gRect.left/2 + (rand() % gRect.right / 2);
		rc.bottom = gRect.bottom / 2 + rand() % gRect.bottom / 2;

		hBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		SelectObject(hdc, hBrush);
		RoundRect(hdc, rc.left, rc.top, rc.right, rc.bottom, rand() % 20, rand() % 20);
		DeleteObject(SelectObject(hdc, GetStockObject(WHITE_BRUSH)));
	}
	ReleaseDC((HWND)Param, hdc);
	return 0;
}


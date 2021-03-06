#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

DWORD WINAPI ThreadProcOne(LPVOID);
DWORD WINAPI ThreadProcTwo(LPVOID);

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

	hwnd = CreateWindow(szAppName, TEXT("First MultiThrading Program"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

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
	HANDLE hThreadOne = NULL;
	HANDLE hThreadTwo = NULL;

	switch (iMsg)
	{
	case WM_CREATE:
		hThreadOne = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProcOne, (LPVOID)hwnd, 0, NULL);
		hThreadTwo = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProcTwo, (LPVOID)hwnd, 0, NULL);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd, TEXT("This is MultiThreading Program"), TEXT("Message"), MB_OK);
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

	for (i = 0; i < 429496729; i++)
	{
		wsprintf(str, TEXT("Thread One : Increasing Order: %ld"), i);
		TextOut(hdc, 5, 5, str, wcslen(str));
	}
	ReleaseDC((HWND)Param, hdc);
	return 0;
}

DWORD WINAPI ThreadProcTwo(LPVOID Param)
{
	HDC hdc;
	long i;
	TCHAR str[255];
	hdc = GetDC((HWND)Param);

	for (i = 429496729; i > 0; i--)
	{
		wsprintf(str, TEXT("Thread Two : Decreasing Order: %ld"), i);
		TextOut(hdc, 5, 25, str, wcslen(str));
	}
	ReleaseDC((HWND)Param, hdc);
	return 0;
}
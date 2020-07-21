#include<Windows.h>

#define MyTimer 105

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;
	MSG iMsg;
	HWND hwnd;
	TCHAR szAppName[] = TEXT("Change Color");

	wndclass.cbClsExtra = 0;
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.cbWndExtra = 0;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName, TEXT("Change Color"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);


	while (GetMessage(&iMsg, NULL, 0, 0))
	{
		TranslateMessage(&iMsg);
		DispatchMessage(&iMsg);
	}

	return ((int)iMsg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	RECT rc;
	PAINTSTRUCT ps;
	static HBRUSH brush[8];
	static int iPaintFlag = -1;

	switch (iMsg)
	{
	case WM_CREATE:
		brush[0] = CreateSolidBrush(RGB(255, 0, 0));
		brush[1] = CreateSolidBrush(RGB(0, 255, 0));
		brush[2] = CreateSolidBrush(RGB(0, 0, 255));
		brush[3] = CreateSolidBrush(RGB(0, 255, 255));
		brush[4] = CreateSolidBrush(RGB(255, 0, 255));
		brush[5] = CreateSolidBrush(RGB(255, 255, 0));
		brush[6] = CreateSolidBrush(RGB(255, 255, 255));
		brush[7] = CreateSolidBrush(RGB(0, 0, 0));

		SetTimer(hwnd, MyTimer, 1000, NULL);
		break;

	case WM_TIMER:
		KillTimer(hwnd, MyTimer);
		iPaintFlag++;
		if (iPaintFlag > 7)
			iPaintFlag = 0;
		InvalidateRect(hwnd, NULL, TRUE);
		SetTimer(hwnd, MyTimer, 1000, NULL);
		break;

	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
		SelectObject(hdc, brush[iPaintFlag]);
		FillRect(hdc, &rc, brush[iPaintFlag]);
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}

	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}




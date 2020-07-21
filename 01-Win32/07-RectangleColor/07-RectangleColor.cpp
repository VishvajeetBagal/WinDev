#include<Windows.h>

#define MyTimer 204

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmd, int iCmdShow)
{
	WNDCLASSEX wndclass;
	MSG iMsg;
	HWND hwnd;
	TCHAR szAppName[] = TEXT("Rectangle Color");

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName, TEXT("Rectangle Color"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&iMsg, NULL, 0, 0))
	{
		
		TranslateMessage(&iMsg);
		DispatchMessage(&iMsg);
	}

	return((int)iMsg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	RECT rc;
	PAINTSTRUCT ps;
	static int iPaintFlag = -1;
	HBRUSH hbrush;
	RECT rct;
	
	switch (iMsg)
	{
		
	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
		hbrush = CreateSolidBrush(RGB(255,128, 0));
		SelectObject(hdc, hbrush);
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom / 3);
		
		DeleteObject(SelectObject(hdc, GetStockObject(WHITE_BRUSH)));
		
		Rectangle(hdc, rc.left, rc.bottom/3 , rc.right , rc.right);
		
		hbrush = CreateSolidBrush(RGB(0, 255, 0));
		SelectObject(hdc, hbrush);
		Rectangle(hdc, rc.left, 2* (rc.bottom / 3), rc.right, rc.bottom);
		DeleteObject(SelectObject(hdc, GetStockObject(WHITE_BRUSH)));


		EndPaint(hwnd, &ps);

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}


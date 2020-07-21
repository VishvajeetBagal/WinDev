#include<windows.h>
#include"BitMap.h"


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstaance, LPSTR szCmdLine, int iCmdShow)
{
	HWND hwnd;
	MSG iMsg;
	WNDCLASSEX wndclass;
	TCHAR szAppName[] = TEXT("Load Bitmap");

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

	hwnd = CreateWindow(szAppName, TEXT("Load Bitmap"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

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
	static HINSTANCE hInstance;
	HBITMAP hBitMap;
	BITMAP bitmap;
	RECT rc;
	HDC hdc,hdcmem;
	PAINTSTRUCT ps;

	switch (iMsg)
	{
	case WM_CREATE:
		hInstance = GetModuleHandle(NULL);
		break;

	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
		hBitMap = LoadBitmap(hInstance, MAKEINTRESOURCE(MYBITMAP));
		hdcmem = CreateCompatibleDC(NULL);
		SelectObject(hdcmem, hBitMap);
		GetObject(hBitMap, sizeof(BITMAP), &bitmap);
		StretchBlt(hdc, 50, 50, 500, 500, hdcmem, 0, 0, 1000, 1000, SRCCOPY);
		DeleteObject(hdcmem);
		DeleteObject(hBitMap);
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);

}
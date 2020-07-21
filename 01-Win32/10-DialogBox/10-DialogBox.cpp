#include<windows.h>
#include"DialogBox.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AboutDlgProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE ghInstance;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstaance, LPSTR szCmdLine, int iCmdShow)
{
	ghInstance = hInstance;
	HMENU  hMenu;
	hMenu = LoadMenu(hInstance, MAKEINTRESOURCE(MYMENU));
	
	
	HWND hwnd;
	MSG iMsg;
	WNDCLASSEX wndclass;
	TCHAR szAppName[] = TEXT("Dialog Box");

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

	hwnd = CreateWindow(szAppName, TEXT("Dialog Box"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, hMenu, hInstance, NULL);

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
	static int idcolor[] = { WHITE_BRUSH,LTGRAY_BRUSH,GRAY_BRUSH,DKGRAY_BRUSH,BLACK_BRUSH };
	HBRUSH hbrush;

	switch (iMsg)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDM_WHITE:
			hbrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
			SetClassLong(hwnd, GCL_HBRBACKGROUND, (long)hbrush);
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case IDM_LTGRAY:
			hbrush = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
			SetClassLong(hwnd, GCL_HBRBACKGROUND, (long)hbrush);
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case IDM_GRAY:
			hbrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
			SetClassLong(hwnd, GCL_HBRBACKGROUND, (long)hbrush);
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case IDM_DKGRAY:
			hbrush = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
			SetClassLong(hwnd, GCL_HBRBACKGROUND, (long)hbrush);
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case IDM_BLACK:
			hbrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
			SetClassLong(hwnd, GCL_HBRBACKGROUND, (long)hbrush);
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case IDM_APPABOUT:
			DialogBox(ghInstance, TEXT("About Box"), hwnd, AboutDlgProc);
			break;

			case WM_DESTROY:
				PostQuitMessage(0);
				break;

		}
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
BOOL CALLBACK AboutDlgProc(HWND hdlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		switch (LOWORD (wParam))
		{
		case IDOK:
		case IDCANCEL:
			EndDialog(hdlg, FALSE);
				return TRUE;

		}
		break;
	}
	return FALSE;
		
}

	
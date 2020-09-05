#include<windows.h>
#include"3_Function.h"
#pragma comment(lib,"3_Function.lib")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG iMsg;
	TCHAR szAppName[] = TEXT("My Application");

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

	hwnd = CreateWindow(szAppName, TEXT("First Window"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

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
	int i = 5;
	int j;
	int k=5;
	int l = 3;

	//int d;
	TCHAR str[255];
	switch (iMsg)
	{
	case WM_CREATE:
		j = MakeCube(i);
		wsprintf(str, TEXT("Cube of %d -> %d \n Press Ok To Next "), i, j);
		MessageBox(hwnd, str, TEXT("Cube"), MB_OK);

		k = AreaofSquare(i);
		wsprintf(str, TEXT("Area of Square %d-> %d \n Press Ok To Next"), i, k);
		MessageBox(hwnd, str, TEXT("Area of Square"), MB_OK);

		l = AreaofRectangle(i,k);
		wsprintf(str, TEXT("Area of Rectangle %d ,%d-> %d \n Press Ok To Next"), i,k, l);
		MessageBox(hwnd, str, TEXT("Area of Rectangle"), MB_OK);
		break;

	
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}


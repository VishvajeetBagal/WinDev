#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX	wndclass;
	HWND hwnd;
	MSG iMsg;
	TCHAR szAppName[] = TEXT("MyApplication");

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

	hwnd = CreateWindow(szAppName,TEXT("My Window"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInstance,NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&iMsg, NULL, 0, 0))
	{
		TranslateMessage(&iMsg);
		DispatchMessage(&iMsg);
	}

	return ((int)&iMsg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	int No1 = 20, No2 = 10, No3;
	TCHAR str[256];
	switch (iMsg)
	{
	case WM_CREATE:
		No3 = No1 + No2;
		wsprintf(str, TEXT("Addition of %d and %d is %d"), No1, No2, No3);
		MessageBox(hwnd, str, TEXT("Display Addition"), MB_OK);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}

	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}
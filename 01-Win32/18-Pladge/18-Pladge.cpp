#include<Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdline, int iCmdShow)
{
	WNDCLASSEX wndclass;
	MSG iMsg;
	HWND hWnd;
	TCHAR szAppName[] = TEXT("Pladge");

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

	hWnd = CreateWindow(szAppName, TEXT("Pladge"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	UpdateWindow(hWnd);
	ShowWindow(hWnd, iCmdShow);

	while (GetMessage(&iMsg, NULL, 0, 0))
	{
		TranslateMessage(&iMsg);
		DispatchMessage(&iMsg);
	}

	return (int)(iMsg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	RECT rc;
	TCHAR str[255] = TEXT("\0");
	PAINTSTRUCT ps;

	switch (msg)
	{
	case WM_PAINT:
		GetClientRect(hWnd, &rc);
		hdc = BeginPaint(hWnd, &ps);
		SetTextColor(hdc, RGB(255, 128, 0));
		SetBkColor(hdc, RGB(0, 0, 0));
		wsprintf(str, TEXT("India is my country"));
		
		TextOut(hdc, MM_TEXT, MM_TEXT, str, wcslen(str));
		wsprintf(str, TEXT("and all Indians are my brothers and sisters."));
		TextOut(hdc, MM_TEXT, MM_TEXT + 20, str, wcslen(str));
		wsprintf(str, TEXT("I love my country"));
		TextOut(hdc, MM_TEXT, MM_TEXT + 40, str, wcslen(str));
		wsprintf(str, TEXT("and I am proud of its rich and varied heritage"));
		TextOut(hdc, MM_TEXT, MM_TEXT + 60, str, sizeof(str));

		SetTextColor(hdc, RGB(255, 255, 255));
		wsprintf(str, TEXT("I shall always strive to be worthy of it."));
		TextOut(hdc, MM_TEXT, MM_TEXT + 90, str, wcslen(str));
		wsprintf(str, TEXT("I shall give respect to my parents,"));
		TextOut(hdc, MM_TEXT, MM_TEXT + 110, str, wcslen(str));
		wsprintf(str, TEXT("teachers and elders"));
		TextOut(hdc, MM_TEXT, MM_TEXT + 130, str, wcslen(str));
		wsprintf(str, TEXT("and treat everyone with courtesy."));
		TextOut(hdc, MM_TEXT, MM_TEXT + 150, str, wcslen(str));

		SetTextColor(hdc, RGB(0, 255, 0));
		wsprintf(str, TEXT("To my country and my people,"));
		TextOut(hdc, MM_TEXT, MM_TEXT + 180, str, wcslen(str));
		wsprintf(str, TEXT("I pledge my devotion."));
		TextOut(hdc, MM_TEXT, MM_TEXT + 200, str, wcslen(str));
		wsprintf(str, TEXT("In their well being and prosperity alone, "));
		TextOut(hdc, MM_TEXT, MM_TEXT + 220, str, wcslen(str));
		wsprintf(str, TEXT("lies my happiness.Jai Hind!"));
		TextOut(hdc, MM_TEXT, MM_TEXT + 240, str, wcslen(str));


		EndPaint(hWnd, &ps);

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
#include<Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR csCmd, int iShow)
{
	WNDCLASSEX wndClass;
	MSG msg;
	HWND hWnd;
	TCHAR szAppName[] = TEXT("HelloWorld");

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

	if (!RegisterClassEx(&wndClass))
	{
		MessageBox(NULL, TEXT("Error in window creation"), TEXT("Error"), MB_OK);
		return 0;
	}

	hWnd = CreateWindow(szAppName, TEXT("Hello World"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	UpdateWindow(hWnd);
	ShowWindow(hWnd, iShow);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	RECT rc;
	TCHAR str[] = TEXT("Hello World");
	PAINTSTRUCT ps;
	static int iPaintFlag = -1;

	switch (msg)
	{

	case WM_CHAR:
		switch (wParam)//wParam:Dableli Key consider hote
		{
		case 'r':
		case 'R':
			iPaintFlag = 1;
			InvalidateRect(hWnd, NULL, TRUE);
			break;

		case 'g':
		case 'G':
			iPaintFlag = 2;
			InvalidateRect(hWnd, NULL, TRUE);
			break;

		case 'b':
		case 'B':
			iPaintFlag = 3;
			InvalidateRect(hWnd, NULL, TRUE);
			break;

		case 'c':
		case 'C':
			iPaintFlag = 4;
			InvalidateRect(hWnd, NULL, TRUE);
			break;

		case 'm':
		case 'M':
			iPaintFlag = 5;
			InvalidateRect(hWnd, NULL, TRUE);
			break;

		case 'y':
		case 'Y':
			iPaintFlag = 6;
			InvalidateRect(hWnd, NULL, TRUE);
			break;



		}


	case WM_PAINT:
		GetClientRect(hWnd, &rc);
		hdc = BeginPaint(hWnd, &ps);
		SetBkColor(hdc, RGB(0, 0, 0));
		if (iPaintFlag == 1)
		{
			SetTextColor(hdc, RGB(255, 0, 0));
		}
		else if (iPaintFlag == 2)
		{
			SetTextColor(hdc, RGB(0, 255, 0));
		}
		else if (iPaintFlag == 3)
		{
			SetTextColor(hdc, RGB(0, 0, 255));
		}
		else if (iPaintFlag == 4)
		{
			SetTextColor(hdc, RGB(0, 255, 255));
		}
		else if (iPaintFlag == 5)
		{
			SetTextColor(hdc, RGB(255, 0, 255));
		}
		else if (iPaintFlag == 6)
		{
			SetTextColor(hdc, RGB(255, 255, 0));
		}
		else if (iPaintFlag == -1)
		{
			SetTextColor(hdc, RGB(255, 255, 255));
		}
		DrawText(hdc, str, -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hWnd, &ps);

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

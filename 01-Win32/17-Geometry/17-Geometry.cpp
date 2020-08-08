#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow) {

	WNDCLASSEX wndclass;
	MSG iMsg;
	TCHAR szAppName[] = TEXT("MyApplication");
	HWND hwnd;

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

	hwnd = CreateWindow(szAppName,TEXT("Simple Geometry"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInstance,NULL);

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
	static HBRUSH hBrush;
	static HPEN hPen;
	HDC hdc;
	static RECT rc;
	PAINTSTRUCT ps;

	switch (iMsg) 
	{

	
	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);

		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		hPen = CreatePen(PS_SOLID, 8, RGB(0, 0, 0));
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);

		// Left Eye
		
		hBrush = CreateSolidBrush(RGB(0, 0, 0));
		hPen = CreatePen(PS_SOLID, 8, RGB(0, 0, 0));
		SelectObject(hdc, hBrush);
		SelectObject(hdc, hPen);
		Ellipse(hdc, rc.right / 2 - 200, rc.bottom / 2 - 200, rc.right / 2 - 70, rc.bottom / 2 - 70);
		//Arc(hdc, rc.right / 2 - 200, rc.bottom / 2 - 200, rc.right / 2 - 70, rc.bottom / 2 - 70, rc.left / 2 - 200, rc.bottom / 2 - 200, rc.right / 2 - 70, rc.bottom / 2 - 150);
		//Arc(hdc, rc.right / 2 - 10, rc.bottom / 2 - 10, rc.right / 2 + 10, rc.bottom / 2 + 10, rc.left / 2 - 10, rc.bottom / 2 + 70, rc.right / 2 + 70, rc.bottom / 2 + 90);
		



		// Right Eye
		
		hBrush = CreateSolidBrush(RGB(0, 0, 0));
		hPen = CreatePen(PS_SOLID, 8, RGB(0, 0, 0));
		SelectObject(hdc, hBrush);
		SelectObject(hdc, hPen);
		Ellipse(hdc, rc.right / 2 + 100, rc.bottom / 2 - 170, rc.right / 2 + 170, rc.bottom / 2 - 90);
		//Arc(hdc, rc.right / 2 + 100, rc.bottom / 2 - 170, rc.right / 2 + 170, rc.bottom / 2 - 90, rc.right / 2 - 200, rc.bottom / 2 - 200, rc.right / 2 + 170, rc.bottom / 2 - 150);

		//Nose
		hBrush = CreateSolidBrush(RGB(0, 0, 0));
		hPen = CreatePen(PS_SOLID, 8, RGB(0, 0, 0));
		SelectObject(hdc, hBrush);
		SelectObject(hdc, hPen);
		Ellipse(hdc, rc.right / 2 - 100, rc.bottom / 2 - 10, rc.right / 2 + 70, rc.bottom / 2 + 90);
		//Arc(hdc, rc.right / 2 - 100, rc.bottom / 2 - 10, rc.right / 2 + 70, rc.bottom / 2 + 90, rc.left / 2 - 90, rc.bottom / 2 + 70, rc.right / 2 + 70, rc.bottom / 2 + 90);

		// Mouth
		hPen = CreatePen(PS_SOLID, 10, RGB(0, 0, 0));
		hBrush = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hdc, hBrush);
		SelectObject(hdc, hPen);
		Arc(hdc, rc.right / 2 - 250, rc.bottom / 2 + 100, rc.right / 2 + 250, rc.bottom / 2 + 250, rc.right / 2 - 250, rc.bottom / 2 + 200, rc.right / 2 + 250, rc.bottom / 2 + 200);

		DeleteObject(hBrush);
		DeleteObject(hPen);
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
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

	hwnd = CreateWindow(szAppName, TEXT("Simple Geometry"), WS_OVERLAPPEDWINDOW, (GetSystemMetrics(SM_CXSCREEN)/2-400), (GetSystemMetrics(SM_CYSCREEN)/2-300), 800, 600, NULL, NULL, hInstance, NULL);

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
	static POINT pts[10] = { 0 };
	PAINTSTRUCT ps;
	int flag1 = 10;
	int flag2 = 5;
	
	

	switch (iMsg)
	{


	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		
		pts[0] = { (int)25 * rc.right / 100,(int)87.5 * rc.bottom / 100 };
		pts[1] = { (int)37.5 * rc.right / 100,(int)50 * rc.bottom / 100 };
		pts[2] = { (int)40.625 * rc.right / 100,(int)79.166666667 * rc.bottom / 100 };
		pts[3] = { (int)73.75 * rc.right / 100,(int)75 * rc.bottom / 100 };
		pts[4] = { (int)68.75 * rc.right / 100,(int)50 * rc.bottom / 100 };
		pts[5] = { (int)56.25 * rc.right / 100,(int)41.66666666667 * rc.bottom / 100 };
		pts[6] = { (int)53.125 * rc.right / 100,(int)28.3333 * rc.bottom / 100 };
		pts[7] = { (int)62.5 * rc.right / 100,(int)8.3333 * rc.bottom / 100 };
		pts[8] = { (int)71.25 * rc.right / 100,(int)15  * rc.bottom / 100 };

		hdc = BeginPaint(hwnd, &ps);
		hBrush = CreateSolidBrush(RGB(0, 255, 0));
		hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		SelectObject(hdc, hPen);
		DrawText(hdc, TEXT("Leo"), -1, &rc, DT_VCENTER | DT_CENTER);
		MoveToEx(hdc, pts[0].x, pts[0].y, NULL);
		for (int i = 0; i < 9; i++)
		{
			LineTo(hdc, pts[i].x, pts[i].y);
		}
		LineTo(hdc, pts[8].x, pts[8].y);

		MoveToEx(hdc, pts[2].x, pts[2].y, NULL);
		for (int i = 0; i < 6; i++)
		{
			LineTo(hdc, pts[i].x, pts[i].y);
		}
		LineTo(hdc, pts[1].x, pts[1].y);
		
		DeleteObject(hPen);

		hBrush = CreateSolidBrush(RGB(0, 255, 0));
		SelectObject(hdc, hBrush);
		for (int i = 0; i < 9; i++) {

			if (i == 5 )
				Ellipse(hdc, pts[i].x - flag1, pts[i].y - flag1, pts[i].x + flag1, pts[i].y + flag1);
			else
				Ellipse(hdc, pts[i].x - flag2, pts[i].y - flag2, pts[i].x + flag2, pts[i].y + flag2);
		}
		DeleteObject(hBrush);


		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hdc, hBrush);
		for (int i = 0; i < 1000; i++) 
		{

			SetPixel(hdc, rand() % rc.right, rand() % rc.bottom, RGB(255, 255, 255));
		}
		DeleteObject(hBrush);
		
		

		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
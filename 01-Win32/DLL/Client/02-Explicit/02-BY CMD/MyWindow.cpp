#include<windows.h>

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
	HMODULE hDll = NULL;
	typedef int (*MakeSquareFunctionPointer)(int);
	MakeSquareFunctionPointer makeSquareFunctionPointer = NULL;
	int i = 5;
	int	j;
	TCHAR str[255];
	
	switch (iMsg)
	{
	case WM_CREATE:
		hDll = LoadLibrary(TEXT("MyMath.dll"));
		if (hDll == NULL)
		{
			MessageBox(hwnd, TEXT("LoadLibraray Fail"), TEXT("Error"),MB_OK);
			DestroyWindow(hwnd);
		}
		
		makeSquareFunctionPointer=(MakeSquareFunctionPointer)GetProcAddress(hDll, "MakeSquare");
		
		if (makeSquareFunctionPointer == NULL)
		{
			FreeLibrary(hDll);
			MessageBox(hwnd,TEXT("GetProc Address Faild"), TEXT("Error"), MB_OK);
		}
		j = makeSquareFunctionPointer(i);
		
		wsprintf(str, TEXT("Square of %d , %d "), i, j);
		MessageBox(hwnd, str, TEXT("Square"), MB_OK);
		FreeLibrary(hDll);

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}



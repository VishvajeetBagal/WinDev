#include<Windows.h>
#include"MyMath.h"

//Entry Point Function

BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReson, LPVOID lpReserved)
{
	//Code
	switch (dwReson)
	{
	case DLL_PROCESS_ATTACH:
		break;
	
	case DLL_THREAD_ATTACH:
		break;
	
	case DLL_THREAD_DETACH:
		break;
	
	case DLL_PROCESS_DETACH:
		break;
	
	default:
		break;

	}
	return TRUE;
}

//Exported Function Defnation
extern "C" int MakeSquare(int num)
{
	//Code
	return num * num;
}

extern "C" int MakeCube(int side)
{
	return side * side * side;
}

//extern "C" int MakeCube(int side)



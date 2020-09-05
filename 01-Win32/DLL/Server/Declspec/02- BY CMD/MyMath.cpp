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
__declspec(dllexport) int MakeSquare(int num)
{
	//Code
	return num * num;
}



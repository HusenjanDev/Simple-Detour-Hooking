#include <Windows.h>
#include <iostream>
#include "detours.h"

DWORD Address = 0x8D24F0;

int hookedFunctionOne(int arg)
{
	std::cout << "Function has been hooked!" << std::endl;
	return arg;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH) {
		while (true)
		{
			if (GetAsyncKeyState(VK_F1))
			{
				DetourTransactionBegin();
				DetourUpdateThread(GetCurrentThread());
				DetourAttach(&(LPVOID&)Address, &hookedFunctionOne);
				DetourTransactionCommit();
			}
			if (GetAsyncKeyState(VK_F2))
			{
				DetourTransactionBegin();
				DetourUpdateThread(GetCurrentThread());
				DetourDetach(&(LPVOID&)Address, &hookedFunctionOne);
				DetourTransactionCommit();
			}
			if (GetAsyncKeyState(VK_F3))
			{
				break;
			}
		}
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		FreeLibrary(hModule);
	}

	return TRUE;
}
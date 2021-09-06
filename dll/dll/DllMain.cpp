#include <Windows.h>
#include <iostream>
#include "detours.h"

// Address of the function that will be replaced.
DWORD Address = 0x8D24F0;

// hookedFunctionOne will be attached/replaced with the original function.
int hookedFunctionOne(int arg)
{
	std::cout << "Function has been hooked!" << std::endl;
	return arg;
}

// DLL Main.
BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	// The following code will execute once the DLL has been attached to an process.
	if (dwReason == DLL_PROCESS_ATTACH) {
		// Continuely running while loop.
		while (true)
		{
			// When the f1 key has been pressed it attaches the hookedFunctionOne() onto function.
			if (GetAsyncKeyState(VK_F1))
			{
				DetourTransactionBegin();
				DetourUpdateThread(GetCurrentThread());
				DetourAttach(&(LPVOID&)Address, &hookedFunctionOne);
				DetourTransactionCommit();
			}
			// When the f2 key has been pressed it detatches the hookedFunctionOne() and the original function will continue running.
			if (GetAsyncKeyState(VK_F2))
			{
				DetourTransactionBegin();
				DetourUpdateThread(GetCurrentThread());
				DetourDetach(&(LPVOID&)Address, &hookedFunctionOne);
				DetourTransactionCommit();
			}
			// Completely detatches the Dynamic Link Library.
			if (GetAsyncKeyState(VK_F3))
			{
				break;
			}
		}
	}
	// The following code will execute when the Dynamic Link Library is getting detatched.
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		// This completely frees our dynamic link library.
		FreeLibrary(hModule);
	}

	return TRUE;
}
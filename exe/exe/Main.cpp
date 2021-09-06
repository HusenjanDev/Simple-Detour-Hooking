#include <Windows.h>
#include <iostream>

// This function will be replaced with an hooked function.
static int functionOne(int arg)
{
	std::cout << "Arg: " << arg << std::endl;
	return arg;
}

int main()
{
	// This is an function pointer and its used to get the memory address of functionOne() function.
	int (*functionOnePtr)(int) = &functionOne;

	// We will need to continuely run the program.
	while (true)
	{
		// Printing out the functionOne() memory address.
		std::cout << "Address: " << *functionOnePtr << std::endl;

		// Using the functionOne(). This will be replaced with an hookedFunction.
		std::cout << "Sum: " << functionOne(10) << std::endl;

		// These are some additional code to make our console look cleaner.
		Sleep(400);
		system("CLS");
	}

	return 0;
}
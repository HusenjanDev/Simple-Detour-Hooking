#include <Windows.h>
#include <iostream>

static int functionOne(int arg)
{
	std::cout << "Arg: " << arg << std::endl;
	return arg;
}

int main()
{
	int (*functionOnePtr)(int) = &functionOne;

	std::cout << "Address: " << *functionOnePtr << std::endl;
	Sleep(1500);

	while (true)
	{
		std::cout << "Address: " << *functionOnePtr << std::endl;
		std::cout << "Sum: " << functionOne(10) << std::endl;
		Sleep(400);
		system("CLS");
	}
}
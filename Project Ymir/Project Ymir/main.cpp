#include <Windows.h>
#include <iostream>

#include "Error Handling\KLogger.h"

/*
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmd, int cmdShow)
{
	int i;
	std::cout << "Hellow world\n";
	std::cin >> i;

	return 0;
}
*/

// now using CUI for simple implementation.
int main()
{
	KLogger::Log("test");
	return 0;
}

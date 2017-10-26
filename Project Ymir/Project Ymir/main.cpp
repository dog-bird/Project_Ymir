#include <Windows.h>
#include <iostream>
#include <exception>

#include "Error Handling\Error.h"

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
	try {
	}
	catch (KException& k_ex) {
		KLogger::Log(k_ex);
	}
	catch (std::exception& ex) {
		
	}
	return 0;
}

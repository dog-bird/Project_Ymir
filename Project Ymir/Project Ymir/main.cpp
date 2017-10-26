#include <Windows.h>
#include <iostream>
#include <exception>

#include "Engine\Engine.h"
#include "Error Handling\Error.h"

/*
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmd, int cmdShow)
{
	int i;
	std::cin >> i;

	return 0;
}
*/

// now using CUI for simple implementation.
int main()
{
	KSEngine::Engine* pApp;
	KSEngine::EngineStruct es;
	es.SetResolution(1920, 1080);

	try {
		pApp = new KSEngine::Engine();
		pApp->Init(es);
		pApp->Run();
	}
	catch (KException& k_ex) {
		KLogger::Log(k_ex);
	}
	catch (std::exception& ex) {
		
	}
	return 0;
}

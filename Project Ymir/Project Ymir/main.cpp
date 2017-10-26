#include <Windows.h>
#include <iostream>
#include <exception>

#include "Engine\Engine.h"
#include "ErrorHandling\Error.h"

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
	KSEngine::Engine* pApp = new KSEngine::Engine();
	KSEngine::EngineStruct es;
	es.SetResolution(1920, 1080);

	try {
		pApp->Init(es);
		pApp->Run();
		pApp->CleanUp();
	}
	catch (KException& k_ex) {
		KLogger::Log(k_ex);
	}
	catch (std::exception& ex) {
		
	}		
	delete pApp;

	return 0;
}

#pragma once

#include <Windows.h>

namespace KSEngine {
	class EngineStruct
	{
	public:
		// resolutioin		
		void SetResolution(int width, int height);
		int width = 0;
		int height = 0;
		int frame = 60;

		// window information. do not care cross platform
		HINSTANCE hInstance = nullptr;
		HINSTANCE hPrevInstance = nullptr;
		LPSTR cmd = nullptr;
		int cmdShow = 0;
	};

	class Engine
	{
	public:
		Engine();
		~Engine();

		// Init Engine components
		void Init(EngineStruct& es);
		// Release resources and engine components.
		void CleanUp();

		// Run Loop.
		int Run();
	private:
		
	};
};
#include "Engine.h"

#include "../Error Handling/Error.h"

using namespace KSEngine;

void KSEngine::EngineStruct::SetResolution(int width, int height)
{
	this->width = width;
	this->height = height;
}

KSEngine::Engine::Engine()
{
}

KSEngine::Engine::~Engine()
{
}

void KSEngine::Engine::Init(EngineStruct & es)
{
	KLogger::Log("*** Init Engine ***");
	IEngineComponent::InitSystem(this);

	KLogger::Log("*** Init Engine Success ***");
}

void KSEngine::Engine::CleanUp()
{
}

int KSEngine::Engine::Run()
{
	return 0;
}

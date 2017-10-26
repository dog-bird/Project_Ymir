#include "Engine.h"

#include "../Error Handling/Error.h"
#include "../SceneMgr/SceneMgr.h"

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

	Scene::SceneMgr* pMgr = new Scene::SceneMgr();
	pMgr->Init();

	KLogger::Log("*** Init Engine Success ***");
}

void KSEngine::Engine::CleanUp()
{
}

int KSEngine::Engine::Run()
{
	return 0;
}

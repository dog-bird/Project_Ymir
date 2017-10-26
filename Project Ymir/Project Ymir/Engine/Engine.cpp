#include "Engine.h"

#include <algorithm>

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
	std::fill_n(m_compList, (int)EngineTag::ENGINE_TAG_END, nullptr);
}

KSEngine::Engine::~Engine()
{
}

void KSEngine::Engine::Init(EngineStruct & es)
{
	KLogger::Log("*** Init Engine ***");
	IEngineComponent::InitSystem(this);

	KScene::SceneMgr* pMgr = new KScene::SceneMgr();
	pMgr->Init();
	AddEngineComponent(pMgr);

	KLogger::Log("*** Init Engine Success ***");
}

void KSEngine::Engine::CleanUp()
{
	KLogger::Log("*** CleanUp Engine ***");

	m_compList[EngineTag::ENGINE_TAG_SCENEMGR]->CleanUp();
	delete m_compList[EngineTag::ENGINE_TAG_SCENEMGR];

	KLogger::Log("*** CleanUp Engine Success ***");
}

int KSEngine::Engine::Run()
{
	return 0;
}

void KSEngine::Engine::AddEngineComponent(IEngineComponent * pCom)
{
	if (pCom == nullptr)
		throw MAKE_EXCEPTION("Engine Component Init Failed");

	if (m_compList[pCom->GetTag()] != nullptr) {
		throw MAKE_EXCEPTION(g_tagName[pCom->GetTag()]);
	}

	m_compList[pCom->GetTag()] = pCom;
}

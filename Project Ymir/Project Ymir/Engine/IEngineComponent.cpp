#include "IEngineComponent.h"

using namespace KSEngine;

Engine* IEngineComponent::m_pEngine = nullptr;

KSEngine::IEngineComponent::IEngineComponent()
{
}

KSEngine::IEngineComponent::~IEngineComponent()
{
}

void KSEngine::IEngineComponent::InitSystem(Engine * pEngine)
{
	m_pEngine = pEngine;
}

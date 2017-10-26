#include "IEngineComponent.h"

#include <sstream>

#include "../ErrorHandling/Error.h"
#include <iostream>

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

Result KSEngine::IEngineComponent::Init()
{
	Result re = InternalInit();

	std::stringstream ss;
	ss << "**" << g_tagName[m_tag] << " " << g_debugInfo[re] << " **";
	KLogger::Log(ss.str());

	return re;
}

Result KSEngine::IEngineComponent::CleanUp()
{
	Result re = InternalCleanUp();

	std::stringstream ss;
	ss << "**" << g_tagName[m_tag] << " " << g_debugInfo[0] << " **";
	KLogger::Log(ss.str());

	return Result();
}

EngineTag KSEngine::IEngineComponent::GetTag()
{
	return m_tag;
}

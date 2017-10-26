#pragma once

#include "../Utils/def.h"

namespace KSEngine {
	class Engine;

	// ENGINE_TAG_END is used to count the number of components
	// Do no move this tag.
	enum EngineTag
	{
		ENGINE_TAG_SCENEMGR,
		ENGINE_TAG_END
	};

	// string for debug info.
	namespace {
		const char* g_tagName[][32] = {"Scene Manager"};
		const char* g_debugInfo[][32] = { "Init Ok", "Init Failed" };
	}
	class IEngineComponent {
	public:
		IEngineComponent();
		virtual ~IEngineComponent();

		static void InitSystem(Engine* pEngine);

		Result Init();
		virtual void Update() = 0;

	protected:
		virtual Result InternalInit() = 0;
		static Engine* m_pEngine;
		EngineTag m_tag;
	private:
	};
};
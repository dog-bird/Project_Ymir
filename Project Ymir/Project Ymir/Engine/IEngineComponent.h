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
		const char g_tagName[][64] = {"Scene Manager"};
		const char g_debugInfo[][64] = { "Init Ok", "Init Failed", 
			"CleanUp Ok", "CleanUp Failed" };
	}

	class IEngineComponent {
	public:
		IEngineComponent();
		virtual ~IEngineComponent();

		static void InitSystem(Engine* pEngine);

		Result Init();
		Result CleanUp();

		virtual void Update() = 0;
		EngineTag GetTag();
	protected:
		virtual Result InternalInit() = 0;
		virtual Result InternalCleanUp() = 0;

		static Engine* m_pEngine;
		EngineTag m_tag;
	private:
	};
};
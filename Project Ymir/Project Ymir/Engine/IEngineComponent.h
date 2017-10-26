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

	class IEngineComponent {
	public:
		IEngineComponent();
		virtual ~IEngineComponent();

		static void InitSystem(Engine* pEngine);

		virtual Result Init() = 0;
		virtual void Update() = 0;

	protected:
		static Engine* m_pEngine;
		EngineTag m_tag;
	private:
	};
};
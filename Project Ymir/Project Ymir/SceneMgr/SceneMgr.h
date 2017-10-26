#pragma once

#include "../Engine/IEngineComponent.h"
#include "Scene.h"

namespace Scene {
	const int MAX_SCENE_NUMBER = 3;

	class SceneMgr : public KSEngine::IEngineComponent{
	public:
		SceneMgr();
		~SceneMgr();

		Result InternalInit();
		void Update();
	private:
		int		m_curSceneNum;
		Scene*	m_curScene[MAX_SCENE_NUMBER];
		Scene*	m_pSceneList;
	};
};
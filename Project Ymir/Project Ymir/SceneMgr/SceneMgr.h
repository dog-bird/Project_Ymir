#pragma once

#include "../Engine/IEngineComponent.h"
#include "Scene.h"

namespace KScene {
	const int MAX_SCENE_NUMBER = 3;

	class SceneMgr : public KSEngine::IEngineComponent{
	public:
		SceneMgr();
		~SceneMgr();

		void Update();

		bool MoveScene(int sceneId);
		// bool MoveScene(int sceneId, Effect);
	protected:
		virtual	Result InternalInit();
		virtual Result InternalCleanUp();

	private:
		int		m_curSceneNum = 0;
		Scene*	m_curScene[MAX_SCENE_NUMBER];
		Scene**	m_pSceneList = nullptr;
		int		m_listSize = -1;
	};
};
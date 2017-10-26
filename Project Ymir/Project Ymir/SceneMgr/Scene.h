#pragma once

#include <string>

#include "../Utils/def.h"

namespace KScene {
	class SceneMgr;

	enum SceneStatus {
		SCENE_ACTIVE,
		SCENE_DEACIVE,
		SCENE_WINDOW
	};

	class Scene {
	public:
		Scene();
		~Scene();

		friend SceneMgr;

		void Update();

	protected:
		// list. Use zone.

		// GameObject List.

	private:
		static SceneMgr* m_pMgr;

		int m_sceneId = -1;
		std::string m_sceneName;
		Rect2D m_size;
	};
};
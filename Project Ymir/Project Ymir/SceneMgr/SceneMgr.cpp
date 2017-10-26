#include "SceneMgr.h"

#include <algorithm>

using namespace KScene;

SceneMgr::SceneMgr()
{
	std::fill_n(m_curScene, 3, nullptr);

	m_tag = KSEngine::ENGINE_TAG_SCENEMGR;
}

SceneMgr::~SceneMgr()
{
	InternalCleanUp();
}

Result SceneMgr::InternalInit()
{
	return R_OK;
}

Result KScene::SceneMgr::InternalCleanUp()
{
	// Release Scenes
	if (m_listSize > 0)
	{
		delete[] m_pSceneList;
		m_listSize = -1;
	}

	return R_OK;
}

void SceneMgr::Update()
{
}

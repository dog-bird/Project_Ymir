#include "SceneMgr.h"


Scene::SceneMgr::SceneMgr()
{
	m_tag = KSEngine::ENGINE_TAG_SCENEMGR;
}

Scene::SceneMgr::~SceneMgr()
{
}

Result Scene::SceneMgr::InternalInit()
{
	return R_OK;
}

void Scene::SceneMgr::Update()
{
}

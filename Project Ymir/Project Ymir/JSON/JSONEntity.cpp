#include "JSONEntity.h"

using namespace JSON;

JSON::JSONEntity::JSONEntity()
{
}

JSON::JSONEntity::~JSONEntity()
{
}

Type JSON::JSONEntity::GetType()
{
	return m_type;
}

bool JSON::JSONEntity::GetValue(std::string name, JSONEntity *& object)
{
	JSONEntity* child = FindChild(name);
	if (child == nullptr)
		return false;
	if (child->GetType() != Object || child->GetType() != Array)
		return false;

	object = child;
	return true;
}

bool JSON::JSONEntity::GetValue(std::string name, std::string & str)
{
	JSONEntity* child = FindChild(name);
	if (child == nullptr)
		return false;
	if (child->GetType() != String)
		return false;

	str = child->m_value;
	return true;
}

bool JSON::JSONEntity::GetValue(std::string name, int & num)
{
	JSONEntity* child = FindChild(name);
	if (child == nullptr)
		return false;
	if (child->GetType() != Number)
		return false;

	num = atoi(child->m_value.c_str());
	return true;
}

bool JSON::JSONEntity::GetValue(std::string name, bool & b)
{
	JSONEntity* child = FindChild(name);
	if (child == nullptr)
		return false;
	if (child->GetType() != Boolean)
		return false;

	b = child->m_value == "true" ? true : false;
	return true;
}

void JSON::JSONEntity::AddChild(JSONEntity * pChild, std::string name)
{
	pChild->m_pParent = this;

	if (m_pChild == nullptr)
		m_pChild = pChild;

	JSONEntity* cur = m_pChild;
	while (cur->m_sibling != nullptr)
	{
		cur = m_sibling;
	}
	cur->m_sibling = pChild;
}

JSONEntity * JSON::JSONEntity::FindChild(std::string name)
{
	JSONEntity* ret = m_pChild;

	while (ret != nullptr)
	{
		if (ret->m_name == name)
			break;
		ret = ret->m_sibling;
	}
}

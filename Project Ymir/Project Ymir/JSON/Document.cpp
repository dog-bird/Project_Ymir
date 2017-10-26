#include "Document.h"

#include <fstream>

JSON::Document::Document()
{
}

JSON::Document::~Document()
{
	Release();
}

bool JSON::Document::OpenFile(const char * fileName)
{

	return true;
}

std::string JSON::Document::GetErrorMsg()
{
	return m_errorMsg.str();
}

JSONObject * JSON::Document::GetRoot()
{
	return m_root;
}

void JSON::Document::Release()
{
	if (m_root == nullptr)
		return;

	// BFS
}

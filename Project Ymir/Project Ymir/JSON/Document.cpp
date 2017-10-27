#include "Document.h"

#include <fstream>

#include "Parser.h"
#include "Scanner.h"

JSON::Document::Document()
{
}

JSON::Document::~Document()
{
	Release();
}

bool JSON::Document::OpenFile(const char * fileName)
{
	std::fstream fs;
	fs.open(fileName, std::fstream::in);
	if (!fs.is_open())
	{
		m_errorMsg << "Cannot open file:" << fileName; 
		return false;
	}

	Scanner scanner(fs);
	Parser parser;
	if (!parser.Parse(scanner, &m_root))
	{
		m_errorMsg << parser.GetErrorMsg();
		return false;
	}

	return true;
}

std::string JSON::Document::GetErrorMsg()
{
	return m_errorMsg.str();
}

JSONEntity * JSON::Document::GetRoot()
{
	return m_root;
}

void JSON::Document::Release()
{
	if (m_root == nullptr)
		return;

	// BFS
}

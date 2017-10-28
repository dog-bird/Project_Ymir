#include "Parser.h"

JSON::Parser::Parser()
{
}

JSON::Parser::~Parser()
{
}

bool JSON::Parser::Parse(Scanner & scan, JSONEntity ** root)
{
	// Read token
	// ???

	// Made element
	// dfs?

	return true;
}

std::string JSON::Parser::GetErrorMsg()
{
	return m_errorMsg.str();
}

#pragma once

#include <string>

class KException
{
public:
	KException(std::string file, int line, std::string what);
	~KException() = default;

	std::string file;
	std::string what;
	int line;
};

#define MAKE_EXCEPTION(WHAT) (KException(__FILE__,__LINE__,WHAT))
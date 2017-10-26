#include "KException.h"

KException::KException(std::string file, int line, std::string what)
	:file(file),line(line),what(what)
{
}
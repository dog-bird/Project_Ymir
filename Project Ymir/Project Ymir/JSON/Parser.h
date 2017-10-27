#pragma once

#include <sstream>

#include "json_def.h"
#include "Scanner.h"

class JSONEntity;

namespace JSON {
	class Parser {
	public:
		Parser();
		~Parser();

		bool Parse(Scanner& scan, JSONEntity** root);
		std::string GetErrorMsg();
	private:
		std::stringstream m_errorMsg;
	};
}
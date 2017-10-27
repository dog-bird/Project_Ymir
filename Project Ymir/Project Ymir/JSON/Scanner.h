#pragma once

#include <fstream>

#include "json_def.h"

namespace JSON {
	class Scanner {
	public:
		Scanner(std::fstream& fs);
		~Scanner();

		Token GetToken();

	private:
		enum Status {
			S_Done,
			S_InString,
			S_Start
		};

		std::fstream& m_fs;
	};
};
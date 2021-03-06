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
		char GetCh(bool skipSpace);
		void UnGet();

		enum Status {
			S_Done,
			S_InString,
			S_InVal,
			S_InNumber,
			S_Start
		};

		std::fstream& m_fs;
		int m_line;
		int m_pos;
	};
};
#pragma once

#include <sstream>

class JSONEntity;

namespace JSON {
	class Document {
	public:
		Document();
		~Document();

		bool OpenFile(const char* fileName);
		std::string GetErrorMsg();

		JSONEntity* GetRoot();
		void Release();

	private:
		JSONEntity* m_root = nullptr;
		std::stringstream m_errorMsg;
	};
}
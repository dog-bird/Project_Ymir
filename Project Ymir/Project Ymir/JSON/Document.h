#pragma once

#include <sstream>

class JSONObject;

namespace JSON {
	class Document {
	public:
		Document();
		~Document();

		bool OpenFile(const char* fileName);
		std::string GetErrorMsg();

		JSONObject* GetRoot();
		void Release();

	private:
		JSONObject* m_root = nullptr;
		std::stringstream m_errorMsg;
	};
}
#pragma once

#include "json_def.h"

namespace JSON {
	class Parser;

	enum Type {
		Object,
		Array,
		Number,
		String,
		Boolean,
		Null,
		Invalid
	};

	class JSONEntity {
	public:
		JSONEntity();
		~JSONEntity();

		Type GetType();
		bool GetValue(std::string name, JSONEntity*& object);
		bool GetValue(std::string name, std::string& str);
		bool GetValue(std::string name, int& num);
		bool GetValue(std::string name, bool& b);

		friend Parser;
	private:
		void AddChild(JSONEntity* pChild, std::string name);
		JSONEntity* FindChild(std::string name);

		JSONEntity* m_pParent	= nullptr;
		Type m_type				= Type::Invalid;
		std::string m_name;

		std::string m_value;

		int m_numChild = 0;
		JSONEntity* m_pChild = nullptr;
		JSONEntity* m_sibling = nullptr;
	};
}
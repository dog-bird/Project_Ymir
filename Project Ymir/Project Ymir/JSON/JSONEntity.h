#pragma once

#include "json_def.h"

namespace JSON {
	class Parser;

	enum Type {
		E_Object,
		E_Array,
		E_Number,
		E_String,
		E_Boolean,
		E_Null,
		E_Invalid
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
		Type m_type				= Type::E_Invalid;
		std::string m_name;

		std::string m_value;

		int m_numChild = 0;
		JSONEntity* m_pChild = nullptr;
		JSONEntity* m_sibling = nullptr;
	};
}
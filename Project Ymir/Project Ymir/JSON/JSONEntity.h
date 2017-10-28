#pragma once

#include "json_def.h"

namespace JSON {
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
		
	private:
		JSONEntity* m_pParent	= nullptr;
		Type m_type				= Type::Invalid;
		
		int m_numChild;
		JSONEntity** m_pChild;
	};
}
#pragma once

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

	class JSONObject {
	public:
		JSONObject();
		~JSONObject();


	private:
		JSONObject* m_pParent	= nullptr;
		Type m_type				= Type::Invalid;
	};
}
#pragma once

#include <string>

namespace JSON {
	enum TokenType {
		LeftCurly,
		RightCurly,
		LeftBrace,
		RightBrace,
		Colon,
		Comma,
		String,
		Number,
		Boolean,
		Eof,
		Invalid
	};

	struct Token {
		TokenType token;
		std::string value;
		int line;
		int pos;
	};
}
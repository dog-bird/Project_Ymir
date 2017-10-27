#include "Scanner.h"

using namespace JSON;

JSON::Scanner::Scanner(std::fstream & fs)
	: m_fs(fs)
{
}

JSON::Scanner::~Scanner()
{
}

Token JSON::Scanner::GetToken()
{
	Token ret;
	Status status = S_Start;

	int line = 1, pos = 0;
	bool save = true;

	while (status != S_Done)
	{
		char ch = m_fs.get();
		pos += 1;
		save = true;

		switch (status)
		{
		case JSON::Scanner::S_InString:
			if (ch == '"')
			{
				save = false;
				status = S_Done;
			}
			// skip new line
			else if (ch == '\n')
			{
				save = false;
			}
			else if (ch == EOF)
			{
				save = false;
				status = S_Done;
				ret.token = Invalid;
			}
			// normal input
			else
			{
				// nothing to do.
			}
			break;
		case JSON::Scanner::S_Start:
			switch (ch)
			{
			case ' ':
				save = false;
				break;
			case '\t':
				save = false;
				break;
			case '\n':
				line += 1;
				pos = 1;
				save = false;
				break;
			case '{':
				ret.token = LeftCurly;
				ret.line = line;
				ret.pos = pos;
				status = S_Done;
				break;
			case '}':
				ret.token = RightCurly;
				ret.line = line;
				ret.pos = pos;
				status = S_Done;
				break;
			case '[':
				ret.token = LeftBrace;
				ret.line = line;
				ret.pos = pos;
				status = S_Done;
				break;
			case ']':
				ret.token = RightBrace;
				ret.line = line;
				ret.pos = pos;
				status = S_Done;
				break;
			case ',':
				ret.token = Comma;
				ret.line = line;
				ret.pos = pos;
				status = S_Done;
				break;
			case '"':
				ret.token = String;
				ret.line = line;
				ret.pos = pos;
				status = S_InString;
				break;
			case EOF:
				ret.token = Eof;
				ret.line = line;
				ret.pos = pos;
				status = S_Done;
				break;
			// Invalid char.
			default:
				ret.token = Invalid;
				ret.line = line;
				ret.pos = pos;
				status = S_Done;
				break;
			}
			break;
		default:
			ret.token = Invalid;
			ret.line = line;
			ret.pos = pos;
			status = S_Done;
			break;
		}

		if(save)
			ret.value.push_back(ch);
	}

	return ret;
}
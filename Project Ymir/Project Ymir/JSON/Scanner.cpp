#include "Scanner.h"

#include <cctype>

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

	bool save;

	while (status != S_Done)
	{
		char ch;
		save = true;

		switch (status)
		{
		case JSON::Scanner::S_InString:
			ch = GetCh(false);
			if (ch == '"')
			{
				save = false;
				status = S_Done;
			}
			// skip new line
			else if (ch == EOF || ch == '\n')
			{
				save = false;
				status = S_Done;
				ret.token = Invalid;
			}
			break;
		case JSON::Scanner::S_InVal:
			ch = GetCh(false);
			if (!isalpha(ch))
			{
				if (ch == '\n' || ch == '\t' || ch == ' ' || ch == EOF)
				{
					UnGet();
					save = false;
					status = S_Done;
				}
			}
			break;
		case JSON::Scanner::S_InNumber:
			ch = GetCh(false);
			if (!isdigit(ch))
			{
				if (ch == '\n' || ch == '\t' || ch == ' ' || ch == EOF)
				{
					UnGet();
					save = false;
					status = S_Done;
				}
				// All the other characters without numbers.
				else
				{
					save = false;
					status = S_Done;
					ret.token = Invalid;
				}
			}
			break;
		case JSON::Scanner::S_Start:
			ch = GetCh(true);
			ret.line = m_line;
			ret.pos = m_pos;

			if (isalpha)
			{
				ret.token = Boolean;
				status = S_InVal;
			}
			else if (isdigit(ch))
			{
				ret.token = Number;
				status = S_InNumber;
			}
			else {
				switch (ch)
				{
				case '{':
					ret.token = LeftCurly;
					status = S_Done;
					break;
				case '}':
					ret.token = RightCurly;
					status = S_Done;
					break;
				case '[':
					ret.token = LeftBrace;
					status = S_Done;
					break;
				case ']':
					ret.token = RightBrace;
					status = S_Done;
					break;
				case ',':
					ret.token = Comma;
					status = S_Done;
					break;
				case '"':
					ret.token = String;
					status = S_InString;
					break;
				case EOF:
					ret.token = Eof;
					status = S_Done;
					break;
				default:
					ret.token = Invalid;
					status = S_Done;
					break;
				}
			}
			break;

		// Invalid input.
		default:
			ret.token = Invalid;
			status = S_Done;
			break;
		}

		if(save)
			ret.value.push_back(ch);
	}

	if (ret.token == Boolean)
	{
		// check that is "true" or "false".
		if (ret.value != "true" && ret.value != "false")
		{
			ret.token = Invalid;
		}
	}

	return ret;
}

// If skip space is true,
// return char without ' ', '\t'.
// if skip space is false
// return all char.
char JSON::Scanner::GetCh(bool skipSpace)
{
	char ch;
	do {
		ch = m_fs.get();
		if (ch == '\n') {
			m_line++;
			m_pos = 1;
		}
		else
			m_pos++;

	// if skip space is true,
	// check whether that is space or not.
	} while (skipSpace && (ch=='\t' || ch == ' ' || '\n'));

	return ch;
}

void JSON::Scanner::UnGet()
{
	m_fs.unget();
}

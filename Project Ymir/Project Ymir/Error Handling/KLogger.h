#pragma once

#include <fstream>

class KException;

// KLogger
// Implemented by singletone.
class KLogger
{
public:
	static void Log(KException& ex);
	// calls from char* and rvalue char
	static void Log(char* str);
	// calls from std::string
	static void Log(std::string str);

	// Delete Log partly to get space.
	// TO_BE_IMPLEMENTED_C
	static void ReduceLog();
private:
	KLogger();
	~KLogger();

	static KLogger* Get();
	void InternalLog(const char* str);
	static KLogger* m_pInstance;
	std::fstream fs;
};
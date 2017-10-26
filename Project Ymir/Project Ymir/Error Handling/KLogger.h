#pragma once

#include <fstream>

class KException;

// KLogger
// Implemented by singletone.
class KLogger
{
public:
	static void Log(KException& ex);
	static void Log(char* str);

	// Delete Log partly to get space.
	// TO_BE_IMPLEMENTED_C
	static void ReduceLog();
private:
	KLogger();
	~KLogger();

	static KLogger* Get();
	void InternalLog(char* str);
	static KLogger* m_pInstance;
	std::fstream fs;
};
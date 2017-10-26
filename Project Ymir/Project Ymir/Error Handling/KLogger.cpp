#include "KLogger.h"

#include <chrono>
#include <ctime>

KLogger* KLogger::m_pInstance = nullptr;

void KLogger::Log(char * str)
{
	Get()->InternalLog(str);
}

KLogger::KLogger()
{
	fs.open("log.error.txt", std::fstream::out | std::fstream::app);
}

KLogger::~KLogger()
{
	fs.close();
}

KLogger * KLogger::Get()
{
	if (m_pInstance == nullptr)
		m_pInstance = new KLogger;
	return m_pInstance;
}

void KLogger::InternalLog(char * str)
{
	using std::chrono::system_clock;

	system_clock::time_point now = system_clock::now();
	std::time_t time = system_clock::to_time_t(now);
	tm time_tm;
	localtime_s(&time_tm, &time);
	fs << time_tm.tm_year - 100 << "." << time_tm.tm_mon + 1 << "." << time_tm.tm_mday << "::"
		<< time_tm.tm_hour << ":" << time_tm.tm_min << ":" << time_tm.tm_sec
		<< "::" << str << std::endl;
}

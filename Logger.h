/*
 Hume Library Version 0.4.2
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <fstream>

namespace hm
{
	enum LogLevel { ERROR, WARNING, INFO, DEBUGMSG };
	
	class Logger
	{
	public:
		virtual ~Logger();
		
		static Logger* getLogger();
		
		LogLevel getLogLevel();
		void setLogLevel(LogLevel level);
		static void log(std::string msg, LogLevel level = INFO);
		
	private:
		std::ofstream ofs;
		LogLevel level;
		
		Logger();
		Logger(Logger&);
		void operator=(Logger&);
		static Logger* instance;
		
		void initSession();
		void endSession();
	};
}

#endif

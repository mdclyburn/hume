/*
 * Logger.h
 *
 *  Created on: Nov 9, 2012
 *      Author: Marshall
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>

namespace hm
{
	enum LogLevel { ERROR, WARNING, INFO, DEBUGMSG };
	struct Message { LogLevel level; std::string msg; };
	
	class Logger
	{
	public:
		virtual ~Logger();
		
		static Logger* getLogger();
		
		LogLevel& getLogLevel();
		void setLogLevel(LogLevel level);
		static void log(std::string msg, LogLevel level = INFO);
		
	private:
		bool ready; // True when stream is open.
		std::ofstream ofs;
		LogLevel level;
		
		Logger();
		Logger(Logger&);
		void operator=(Logger&);
		static Logger* instance;
		
		void initSession();
		void endSession();
	};

	void operator<<(Logger* l, Message m);
}

#endif

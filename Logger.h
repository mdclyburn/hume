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
#include <ctime>
#include <iostream>
#include <fstream>

namespace hm
{
	// The severity of the message sent to the logger.
	enum LogLevel { ERROR, WARNING, INFO, DEBUGMSG };
	
	/*
	 A small, useful class used to write log messages out
	 to a text file.
	 */
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

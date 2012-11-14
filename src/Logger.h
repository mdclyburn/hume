/*
 * Logger.h
 *
 *  Created on: Nov 9, 2012
 *      Author: Marshall
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <sstream>
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>

namespace hm
{
	enum LogLevel
	{
		ERROR, WARNING, INFO, DEBUG, DEBUGM, DEBUGH
	};
	class Logger
	{
		public:
			Logger();
			Logger(LogLevel level);
			virtual ~Logger();

			LogLevel& getLogLevel();
			void setLogLevel(LogLevel level);
			void log(LogLevel level, std::string msg);
		private:
			void writeOut();
			std::ostringstream oss;
			LogLevel level;
	};
}

#endif

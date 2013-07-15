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
	enum LogLevel { ERROR, WARNING, INFO, DEBUG };

	class Logger
	{
		public:
			Logger();
			Logger(LogLevel level);
			virtual ~Logger();

			LogLevel& getLogLevel();
			void setLogLevel(LogLevel level);
			void log(std::string msg, LogLevel level = INFO);
		private:
			void initSession(); // Gets the object ready to log.
			std::ofstream ofs;
			LogLevel level;
	};
}

#endif

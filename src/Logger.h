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

	class Logger
	{
		public:
			Logger();
			Logger(LogLevel level);
			virtual ~Logger();

			LogLevel& getLogLevel();
			void setLogLevel(LogLevel level);
			void log(std::string msg, LogLevel level = INFO);
			void initSession();
			void endSession();
		private:
			bool ready; // True when stream is open.
			std::ofstream ofs;
			LogLevel level;
	};
}

#endif

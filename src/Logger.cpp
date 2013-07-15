/*
 * Logger.cpp
 *
 *  Created on: Nov 9, 2012
 *      Author: Marshall
 */

#include "Logger.h"

namespace hm
{
	Logger::Logger() : level(INFO)
	{
		initSession();
	}

	Logger::Logger(LogLevel level) : level(level)
	{
		initSession();
	}

	Logger::~Logger()
	{
	}

	LogLevel& Logger::getLogLevel()
	{
		return level;
	}

	void Logger::setLogLevel(LogLevel level)
	{
		this->level = level;
		return;
	}

	void Logger::log(std::string msg, LogLevel level)
	{
		if(this->level < level)
			return;

		switch(level)
		{
			case ERROR:
				ofs << "ERROR:\t";
				break;
			case WARNING:
				ofs << "WARNING:\t";
				break;
			case INFO:
				ofs << "INFO:\t";
				break;
			case DEBUG:
				ofs << "DEBUG:\t";
				break;
			default:
				ofs << "UNID'd:\t";
				break;
		}

		ofs << msg << std::endl;
		ofs.flush();

		return;
	}

	void Logger::initSession()
	{
		ofs.open("log.txt", std::ios::app | std::ios::out);
		ofs << "NEW LOGGING SESSION =============================" << std::endl;
		return;
	}
		
}

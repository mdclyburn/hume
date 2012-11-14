/*
 * Logger.cpp
 *
 *  Created on: Nov 9, 2012
 *      Author: Marshall
 */

#include "Logger.h"

namespace hm
{
	Logger::Logger() : level(ERROR)
	{

	}

	Logger::Logger(LogLevel level) : level(level)
	{

	}

	Logger::~Logger()
	{
		writeOut();
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
		if(level > this->level)
			return;

		switch(level)
		{
			case ERROR:
				oss << "ERROR:\t";
				break;
			case WARNING:
				oss << "WARNING:\t";
				break;
			case INFO:
				oss << "INFO:\t";
				break;
			case DEBUG:
				oss << "DEBUG:\t";
				break;
			case DEBUGM:
				oss << "DEBUGM:\t";
				break;
			case DEBUGH:
				oss << "DEBUGH:\t";
				break;
			default:
				oss << "UNID'd:\t";
				break;
		}

		oss << msg << std::endl;

		return;
	}

	void Logger::writeOut()
	{
		std::ofstream ofs;
		ofs.open("log.txt");
		ofs << oss.str();
		ofs.close();

		return;
	}
}

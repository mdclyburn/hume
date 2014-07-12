/*
 * Logger.cpp
 *
 *  Created on: Nov 9, 2012
 *      Author: Marshall
 */

#include "Logger.h"

hm::Logger* hm::Logger::instance = NULL;

namespace hm
{
	Logger::Logger() : level(DEBUGMSG)
	{
		initSession();
	}

	Logger::~Logger()
	{
		if(instance != NULL)
		{
			endSession();
			delete instance;
			instance = NULL;
		}
	}
	
	Logger* Logger::getLogger()
	{
		if(instance == NULL)
			instance = new Logger();
		return instance;
	}

	LogLevel Logger::getLogLevel()
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
		if(getLogger()->level < level)
			return;

		Logger* logger = getLogger();
		
		// Output time.
		time_t raw_time;
		struct tm local_time;
		time(&raw_time);
		local_time = *localtime(&raw_time);
		logger->ofs << std::to_string(local_time.tm_hour) << ":"
		<< std::to_string(local_time.tm_min) << ":"
		<< std::to_string(local_time.tm_sec) << "\t";
		
		switch(level)
		{
			case ERROR:
				logger->ofs << "ERROR:\t";
				break;
			case WARNING:
				logger->ofs << "WARNING:\t";
				break;
			case INFO:
				logger->ofs << "INFO:\t";
				break;
			case DEBUGMSG:
				logger->ofs << "DEBUGMSG:\t";
				break;
			default:
				logger->ofs << "UNID'd:\t";
				break;
		}

		getLogger()->ofs << msg << std::endl;
		getLogger()->ofs.flush();

		return;
	}

	void Logger::initSession()
	{
		ofs.open("log.txt", std::ios::app | std::ios::out);
		ofs << "NEW LOGGING SESSION =============================" << std::endl;
		return;
	}

	void Logger::endSession()
	{
		ofs << "END LOGGING SESSION =============================" << std::endl;
		ofs.close();
		return;
	}
}

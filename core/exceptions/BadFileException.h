#ifndef BADFILEEXCEPTION_H
#define BADFILEEXCEPTION_H

#include "Exception.h"

class BadFileException : public Exception
{
public:
	BadFileException();
	BadFileException(const std::string& file_name);
	virtual ~BadFileException();
};

#endif

#ifndef BADFILEEXCEPTION_H
#define BADFILEEXCEPTION_H

#include "Exception.h"

namespace hume
{
	class BadFileException : public Exception
	{
	public:
		BadFileException();
		explicit BadFileException(const std::string& file_name);
		virtual ~BadFileException();
	};
}

#endif

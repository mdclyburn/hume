#include "Exception.h"

Exception::Exception() : message("Hume encountered an unexpected error.")
{
}

Exception::Exception(const std::string& message) : message(message)
{
}

Exception::~Exception()
{
}

const std::string& Exception::get_message() const
{
	return message;
}

void Exception::set_message(const std::string& message)
{
	this->message = message;
	return;
}

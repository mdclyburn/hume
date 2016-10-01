#include "BadFileException.h"

namespace hume
{
    BadFileException::BadFileException() : Exception("The file provided is invalid.")
    {
    }

    BadFileException::BadFileException(const std::string& file_name)
    {
        message = "\'" + file_name + "\' is missing, invalid, or corrupt.";
    }

    BadFileException::~BadFileException()
    {
    }
}

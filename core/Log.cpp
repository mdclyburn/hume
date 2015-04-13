#include "Log.h"

Log::Log() : mode(LogMode::DEFAULT)
{
}

Log::~Log()
{
}

void Log::set_mode(const LogMode l)
{
    mode = l;
    return;
}

LogMode Log::get_mode()
{
    return mode;
}

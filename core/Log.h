// Hume Library Version 0.7

#ifndef LOG_H
#define LOG_H

#include <string>

#include "Component.h"
#include "LogMode.h"

class Log : public Component
{
public:
    Log();
    virtual ~Log();

    virtual void log(const std::string& msg) = 0;

    void set_mode(const LogMode l);
    LogMode get_mode();

protected:
    LogMode mode;
};

#endif

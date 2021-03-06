#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

namespace hume
{
    class Exception : public std::exception
    {
    public:
        Exception();
        explicit Exception(const std::string& message);
        virtual ~Exception();

        const std::string& get_message() const;
        void set_message(const std::string& message);

    protected:
        std::string message;
    };
}

#endif

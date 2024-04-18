#ifndef BASE_EXCEPTION_H
#define BASE_EXCEPTION_H

#include <exception>
#include <string>

class BaseException : public std::exception
{
public:
    BaseException(const std::string &time, const std::string &filename,
                  const size_t line, const std::string &class_name,
                  const std::string &method_name, const std::string &info);
    virtual const char* what() const noexcept override;
protected:
    std::string errMsg;
};

#endif

#include "baseexception.hpp"

#include <cstdio>

BaseException::BaseException(const char *filename,
                             const size_t line, const char *class_name,
                             const char *method_name, const char *info)
{
    snprintf(errMsg, errSize, "\nerror in file %s, line %zu, in method %s of class %s.\n Info: %s\n", filename, line, method_name, class_name, info);
}

const char *BaseException::what() const noexcept
{
    return errMsg;
}

#pragma once

#include "base_exception.h"

class ListOutOfBounds : public BaseException
{
public:
    ListOutOfBounds(
                    const std::string& filename,
                    const std::string& classname,
                    const int line,
                    const char *time,
                    const std::string& info = "Out of bounds access")
    : BaseException(filename, classname, line, time, info) { }
};

class EmptyList : public BaseException {
 public:
    EmptyList(
              const std::string& filename,
              const std::string& classname,
              const int line,
              const char *time,
              const std::string& info = "Empty list access")
    : BaseException(filename, classname, line, time, info) { }
};

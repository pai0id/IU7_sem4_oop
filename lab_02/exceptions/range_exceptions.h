#pragma once

#include "base_exception.h"

class RangeException : public BaseException
{
public:
    RangeException(const char *filename,
                  const char *classname,
                  int line,
                  const char *time,
                  const char *info = "Range Exception")
        : BaseException(filename, classname, line, time, info) { }
};

class InvalidRange : public RangeException {
public:
    InvalidRange(
              const char *filename,
              const char *classname,
              const int line,
              const char *time,
              const char *info = "Invalid range")
    : RangeException(filename, classname, line, time, info) { }
};

#pragma once

#include "base_exception.h"

class ListException : public BaseException
{
public:
    ListException(const char *filename,
                  const char *classname,
                  int line,
                  const char *time,
                  const char *info = "List Exception")
        : BaseException(filename, classname, line, time, info) { }
};

class ListOutOfBounds : public ListException
{
public:
    ListOutOfBounds(
                    const char *filename,
                    const char *classname,
                    const int line,
                    const char *time,
                    const char *info = "Out of bounds access")
    : ListException(filename, classname, line, time, info) { }
};

class EmptyList : public ListException
{
public:
    EmptyList(
              const char *filename,
              const char *classname,
              const int line,
              const char *time,
              const char *info = "Empty list access")
    : ListException(filename, classname, line, time, info) { }
};

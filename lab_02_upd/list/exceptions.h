#pragma once

#include "base_exception.h"

class ListOutOfBounds : public BaseException
{
public:
    ListOutOfBounds(
                    const char *filename,
                    const char *classname,
                    const int line,
                    const char *time,
                    const char *info = "Out of bounds access")
    : BaseException(filename, classname, line, time, info) { }
};

class EmptyList : public BaseException {
public:
    EmptyList(
              const char *filename,
              const char *classname,
              const int line,
              const char *time,
              const char *info = "Empty list access")
    : BaseException(filename, classname, line, time, info) { }
};

class InvalidIterator : public BaseException {
public:
    InvalidIterator(
              const char *filename,
              const char *classname,
              const int line,
              const char *time,
              const char *info = "Invalid iterator")
    : BaseException(filename, classname, line, time, info) { }
};

class InvalidRange : public BaseException {
public:
    InvalidRange(
              const char *filename,
              const char *classname,
              const int line,
              const char *time,
              const char *info = "Invalid range")
    : BaseException(filename, classname, line, time, info) { }
};

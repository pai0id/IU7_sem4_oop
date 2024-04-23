#pragma once

#include "base_exception.h"

class IteratorException : public BaseException
{
public:
    IteratorException(const char *filename,
                  const char *classname,
                  int line,
                  const char *time,
                  const char *info = "Iterator Exception")
        : BaseException(filename, classname, line, time, info) { }
};

class InvalidIterator : public IteratorException {
public:
    InvalidIterator(
              const char *filename,
              const char *classname,
              const int line,
              const char *time,
              const char *info = "Invalid iterator")
    : IteratorException(filename, classname, line, time, info) { }
};
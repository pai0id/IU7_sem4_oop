#pragma once
#include "baseexception.hpp"

class SolutionException : public BaseException 
{
    public:
    SolutionException(const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Solution exception.")
        : BaseException(filename, line, class_name, method_name, info){};
};

class SolutionNotFoundException : public SolutionException 
{
    public:
    SolutionNotFoundException(const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Solution exception.")
        : SolutionException(filename, line, class_name, method_name, info){};
};


class SolutionAlreadyInException : public SolutionException 
{
    public:
    SolutionAlreadyInException(const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Solution exception.")
        : SolutionException(filename, line, class_name, method_name, info){};
};

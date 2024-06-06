#pragma once
#include "baseexception.hpp"

class ModelStructureException : public BaseException 
{
    public:
    ModelStructureException(const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Model structure exception.")
        : BaseException(filename, line, class_name, method_name, info){};
};

class EdgeOutOfPointsException : public ModelStructureException 
{
    public:
    EdgeOutOfPointsException(const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Edge has not existing points exception.")
        : ModelStructureException(filename, line, class_name, method_name, info){};
};


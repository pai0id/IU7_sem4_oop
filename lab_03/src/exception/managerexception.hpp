#pragma once
#include "baseexception.hpp"

class ManagerException : public BaseException 
{
    public:
    ManagerException(const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Manager exception.")
        : BaseException(filename, line, class_name, method_name, info){};
};

class LoadManagerException : public ManagerException 
{
    public:
    LoadManagerException(const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Manager exception.")
        : ManagerException(filename, line, class_name, method_name, info){};
};

class LoadManagerWrongDirectorException : public LoadManagerException {
    public:
        LoadManagerWrongDirectorException(const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Manager exception.")
        : LoadManagerException(filename, line, class_name, method_name, info){};
};

class LoadManagerWrongLoaderException : public LoadManagerException {
    public:
        LoadManagerWrongLoaderException(const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Manager exception.")
        : LoadManagerException(filename, line, class_name, method_name, info){};
};

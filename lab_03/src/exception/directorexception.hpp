#pragma once
#include "baseexception.hpp"

class DirectorException : public BaseException 
{
    public:
    DirectorException(const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Director exception.")
        : BaseException(filename, line, class_name, method_name, info){};
};

class BoneModelDirectorException : public DirectorException
{
    public:
    BoneModelDirectorException(const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Bonemodel director exception.")
        : DirectorException(filename, line, class_name, method_name, info){};
};

class BoneModelDirectorWrongReaderException : public BoneModelDirectorException
{
    public:
    BoneModelDirectorWrongReaderException(const char *filename,
                     const size_t line, const char *class_name,
                     const char *method_name,
                     const char *info = "Wrong Reader type passed to director, expected BoneModelReader exception.")
        : BoneModelDirectorException(filename, line, class_name, method_name, info){};
};

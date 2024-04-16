/*Класс ошибок, наследующий std::exception*/
#ifndef _ERRORS_H_
#define _ERRORS_H_

#include <exception>
#include <string>

//базовый класс с виртуальной функцией
class ListErrorBase : public std::exception
{
protected:
    std::string message;
public:
    explicit ListErrorBase(const std::string& filename, const std::string& classname, const int line, const char* time,
                           const std::string& info)
    {
        message = "In " + filename + "\nInside " + classname + " class" + "\nAt line " + std::to_string(line) +
                  "\nAt time " + time + "\nOccured error: " + info;
    }

    virtual const char* what() const noexcept
    {
        return message.c_str();
    }
};

//класс, учитывающий утечки памяти
class ListMemoryError : public ListErrorBase
{
public:
    ListMemoryError(const std::string& filename, const std::string& classname, const int line, const char* time,
                    const std::string& info = "Error: Memory allocation")
        : ListErrorBase(filename, classname, line, time, info)
    {
    }
};

//класс, учитывающий пуст ли список
class ListEmptyError : public ListErrorBase
{
public:
    ListEmptyError(const std::string& filename, const std::string& classname, const int line, const char* time,
                   const std::string& info = "Error: List is empty")
        : ListErrorBase(filename, classname, line, time, info)
    {
    }
};

//класс, учитывающий выход за границы списка
class ListRangeError : public ListErrorBase
{
public:
    ListRangeError(const std::string& filename, const std::string& classname, const int line, const char* time,
                   const std::string& info = "Error: Index out of range")
        : ListErrorBase(filename, classname, line, time, info)
    {
    }
};

//класс, учитывающий неверный итератор
class ListIteratorError : public ListErrorBase
{
public:
    ListIteratorError(const std::string& filename, const std::string& classname, const int line, const char* time,
                      const std::string& info = "Error: Invalid iterator")
        : ListErrorBase(filename, classname, line, time, info)
    {
    }
};

#endif

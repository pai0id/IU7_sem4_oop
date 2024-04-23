#pragma once

#include <exception>
#include <cstring>

class BaseException : public std::exception
{
protected:
	static const size_t sizebuff = 256;
	char errormsg[sizebuff]{};

public:
	BaseException() noexcept = default;
	BaseException(const char *filename,
                   const char *classname,
                   const int line,
                   const char *time,
                   const char *info) noexcept
	{
		snprintf(errormsg,
                 sizebuff,
                 "\nIn: %s\n"
                 "inside: %s\n"
                 "at line: %d\n"
                 "at: %s\n"
                 "occured: %s", filename, classname, line, time, info);
	}
	~BaseException() override {}

	const char* what() const noexcept override { return errormsg; }
};

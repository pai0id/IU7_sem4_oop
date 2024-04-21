#pragma once

#include <exception>
#include <string>

class BaseException : public std::exception
{
public:
    explicit BaseException(
                           const std::string& filename,
                           const std::string& classname,
                           const int line,
                           const char *time,
                           const std::string& info) {
        m_msg = "In: "          + filename             +
                "\ninside: "    + classname            +
                "\nat line: "   + std::to_string(line) +
                "\nat: "        + time                 +
                "­\noccured: "   + info;
    }

    const char *what() const noexcept override {
        return m_msg.c_str();
    }
private:
    std::string m_msg;
};

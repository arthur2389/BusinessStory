#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#pragma once

#include <stdexcept>
#include <string>


class InvalidUserParameter: public std::exception
{
    public:
        InvalidUserParameter() noexcept=default;
        InvalidUserParameter(std::string user_parameter,
                             std::string field_name, 
                             std::string extra_description="") noexcept 
        {
            m_invalid_massege = "Invalid user parameter: '" + user_parameter +
                 "' In field: '" + field_name + "' " + extra_description;
        }
        ~InvalidUserParameter() = default;

        virtual const char* what() const noexcept {
            return m_invalid_massege.c_str();
        }

    private:
        std::string m_invalid_massege;
}; 

#endif
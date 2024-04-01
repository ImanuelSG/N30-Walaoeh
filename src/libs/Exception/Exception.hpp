#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <exception>
#include <iostream>

class NumericException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Input anda tidak valid.\nSilahkan masukkan angka sebagai input.";
    }
};

#endif
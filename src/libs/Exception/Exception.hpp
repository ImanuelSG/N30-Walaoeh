
#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <iostream>
#include <exception> // Add missing include directive
using namespace std;

class NumericException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Input anda tidak valid.\nSilahkan masukkan angka sebagai input.";
    }
};

class InvalidInputException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Input anda tidak valid.\nSilahkan masukkan input yang sesuai.";
    }
};

#endif

#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <iostream>
#include <exception> // Add missing include directive
using namespace std;

class NumericException : public exception
{
public:
    const char *what();
};

class InvalidInputException : public exception
{
public:
    const char *what();
};

class WalikotaInputException : public exception
{
public:
    const char *what();
};

#endif
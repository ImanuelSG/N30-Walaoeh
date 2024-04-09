
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

class InvalidCommandException : public exception
{
public:
    const char *what();
};

class StorageFullException : public exception{
public:
    const char *what();
};

class LadangFullException : public exception{
public:
    const char *what();
};

class TernakFullException : public exception{
public:
    const char *what();
};

class NotEnoughMoneyException : public exception{
    const char *what();
};

class NotEnoughHewanException : public exception {
    const char *what();
};


#endif
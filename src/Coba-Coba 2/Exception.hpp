#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <stdexcept>

using namespace std;

class Exception : public runtime_error
{
public:
    Exception(const string &pesan) : runtime_error(pesan) {}
};

class KekuranganUangException : public Exception
{
public:
    KekuranganUangException() : Exception("Uang tidak cukup") {}
};

class InventoryPenuhException : public Exception
{
public:
    InventoryPenuhException() : Exception("Inventory penuh") {}
};

#endif

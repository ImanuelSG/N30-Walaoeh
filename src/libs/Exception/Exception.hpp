
#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <iostream>
#include <exception> // Add missing include directive
using namespace std;

// EXCEPTION UNTUK INPUT
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
class PeternakInputException : public exception
{
public:
    const char *what();
};
class PetaniInputException : public exception
{
public:
    const char *what();
};

class PanenInputException : public exception
{
public:
    const char *what();
};


// EXCEPTION UNTUK FULL
class InventoryFullException : public exception
{
public:
    const char *what();
};

class LadangFullException : public exception
{
public:
    const char *what();
};

class TernakFullException : public exception
{
public:
    const char *what();
};


// EXCEPTION UNTUK KURANG
class NotEnoughMoneyException : public exception
{
    const char *what();
};

class NotEnoughHewanException : public exception {
    const char *what();
};
class NotEnoughFoodException : public exception {
    const char *what();
};


// EXCEPTION UNTUK KOSONG
class InventoryEmptyException : public exception {
     const char *what();
};
class LadangEmptyException : public exception {
     const char *what();
};
class TernakEmptyException : public exception {
     const char *what();
};


// EXCEPTION UNTUK INVALID INDEX
class InvalidStorageIndexException : public exception
{
    const char *what();
};

class InvalidJenisTanamanException : public exception
{
    const char *what();
};

class InvalidJenisHewanException : public exception
{
    const char *what();
};

class InvalidJenisProdukMaterialException : public exception
{
    const char *what();
};

class InvalidJenisProdukBuahException : public exception
{
    const char *what();
};

class InvalidJenisProdukHewanException : public exception
{
    const char *what();
};

class InvalidJenisBangunanException : public exception
{
    const char *what();
};

#endif
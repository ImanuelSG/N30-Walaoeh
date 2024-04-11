
#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <iostream>
#include <map>
#include <exception>
#include <sstream>
#include <cstring>
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
public:
    const char *what();
};

class NotEnoughTanamanException : public exception
{
public:
    const char *what();
};

class NotEnoughHewanException : public exception
{

public:
    const char *what();
};
class NotEnoughFoodException : public exception
{
public:
    const char *what();
};

// EXCEPTION UNTUK KOSONG
class InventoryEmptyException : public exception
{
public:
    const char *what();
};
class LadangEmptyException : public exception
{
public:
    const char *what();
};
class TernakEmptyException : public exception
{
public:
    const char *what();
};

// EXCEPTION UNTUK INVALID INDEX
class InvalidStorageIndexException : public exception
{

public:
    const char *what();
};

// EXCEPTION UNTUK PERBEDAAN JENIS
class InvalidJenisTanamanException : public exception
{
public:
    const char *what();
};

class InvalidJenisHewanException : public exception
{
public:
    const char *what();
};

class InvalidJenisProdukMaterialException : public exception
{
public:
    const char *what();
};

class InvalidJenisProdukBuahException : public exception
{
public:
    const char *what();
};

class InvalidJenisProdukHewanException : public exception
{
public:
    const char *what();
};

class InvalidJenisBangunanException : public exception
{
public:
    const char *what();
};

class InvalidJenisSellableException : public exception
{
public:
    const char *what();
};

class InvalidProdukException : public exception
{
public:
    const char *what();
};

class InvalidJenisMakananException : public exception
{
public:
    const char *what();
};

class FileNotFoundException : public exception
{
public:
    const char *what();
};

class NotEnoughMaterialException : public exception
{
private:
    int gulden;
    map<string, int> material;

public:
    NotEnoughMaterialException(int gulden, map<string, int> material);
    const char *what();
};

#endif
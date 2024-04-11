#include "Exception.hpp"

// EXCEPTION UNTUK INPUT
const char *NumericException::what()
{
    return "Input anda tidak valid.\nSilahkan masukkan angka sebagai input.";
}

const char *InvalidInputException::what()
{
    return "Input yang anda masukkan tidak valid !\nSilahkan masukkan input yang sesuai.";
}

const char *WalikotaInputException::what()
{
    return "Input yang anda masukkan merupakan milik dari Walikota!\nSilahkan masukkan input yang sesuai dengan role anda!";
}
const char *PeternakInputException::what()
{
    return "Input yang anda masukkan merupakan milik dari Peternak!\nSilahkan masukkan input yang sesuai dengan role anda!";
}
const char *PetaniInputException::what()
{
    return "Input yang anda masukkan merupakan milik dari Petani!\nSilahkan masukkan input yang sesuai dengan role anda!";
}
const char *PanenInputException::what()
{
    return "Input yang anda masukkan merupakan milik dari Petani atau Peternak!\nSilahkan masukkan input yang sesuai dengan role anda!";
}

// EXCEPTION UNTUK FULL
const char *InventoryFullException::what()
{
    return "Inventory Anda sudah penuh, tidak bisa menjalankan perintah\n";
}

const char *LadangFullException::what()
{
    return "Ladang Anda sudah penuh, tidak bisa menjalankan perintah\n";
}

const char *TernakFullException::what()
{
    return "Ternak Anda sudah penuh, tidak bisa menjalankan perintah\n";
}

// EXCEPTION UNTUK KURANG
const char *NotEnoughMoneyException::what()
{
    return "Gulden Anda tidak cukup\n";
}

const char *NotEnoughHewanException::what()
{
    return "Hewan Anda tidak cukup, tidak bisa menjalankan perintah\n";
}
const char *NotEnoughFoodException::what()
{
    return "Makanan Anda tidak cukup, tidak bisa menjalankan perintah\n";
}

// EXCEPTION UNTUK KOSONG
const char *InventoryEmptyException::what()
{
    return "Inventory Anda Kosong, tidak bisa menjalankan perintah\n";
}
const char *LadangEmptyException::what()
{
    return "Ladang Anda Kosong, tidak bisa menjalankan perintah\n";
}
const char *TernakEmptyException::what()
{
    return "Ternak Anda Kosong, tidak bisa menjalankan perintah\n";
}

// EXCEPTION UNTUK INVALID
const char *InvalidStorageIndexException::what()
{
    return "Indeks yang Anda masukkan tidak valid!.\n Pastikan Indeks Anda sesuai.\n";
}

const char *InvalidJenisTanamanException::what()
{
    return "Jenis tanaman yang Anda masukkan tidak valid!.\n Pastikan Jenis Tanaman Anda sesuai.\n";
}

const char *InvalidJenisHewanException::what()
{
    return "Jenis hewan yang Anda masukkan tidak valid!.\n Pastikan Jenis Hewan Anda sesuai.\n";
}

const char *InvalidJenisProdukMaterialException::what()
{
    return "Jenis produk material yang Anda masukkan tidak valid!.\n Pastikan Jenis Produk Material Anda sesuai.\n";
}

const char *InvalidJenisProdukBuahException::what()
{
    return "Jenis produk buah yang Anda masukkan tidak valid!.\n Pastikan Jenis Produk Buah Anda sesuai.\n";
}

const char *InvalidJenisProdukHewanException::what()
{
    return "Jenis produk hewan yang Anda masukkan tidak valid!.\n Pastikan Jenis Produk Hewan Anda sesuai.\n";
}

const char *InvalidJenisBangunanException::what()
{
    return "Jenis bangunan yang Anda masukkan tidak valid!.\n Pastikan Jenis Bangunan Anda sesuai.\n";
}

const char *InvalidProdukException::what()
{
    return "Masukkan Anda bukan jenis Makanan, silakan masukkan jenis yang benar\n";
}
const char *InvalidJenisMakananException::what()
{
    return "Jenis maknanan yang Anda pilih tidak sesuai dengan jenis hewan Anda.\n";
}

const char *InvalidJenisSellableException::what()
{
    return "Jenis sellable yang Anda masukkan tidak valid!.\n Pastikan Jenis Sellable Anda sesuai.\n";
}

// ECEPTION UNTUK NOT ENOUGH
NotEnoughMaterialException::NotEnoughMaterialException(int gulden, map<string, int> material)
{
    this->gulden = gulden;
    this->material = material;
}
const char *NotEnoughMaterialException::what()
{
    ostringstream oss;
    int gulden = this->gulden;
    map<string, int> material = this->material;
    oss << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";

    if (gulden > 0)
    {
        oss << gulden << " gulden";
    }

    if (!material.empty())
    {
        if (gulden > 0)
        {
            oss << ", ";
        }

        for (auto it = material.begin(); it != material.end(); it++)
        {
            oss << it->first << " " << it->second;
            if (it != prev(material.end()))
            {
                oss << ", ";
            }
        }
    }
    oss << "!";
    // Convert the ostringstream to a string and return its char* representation
    string result = oss.str();
    char *word = new char[result.length() + 1];
    strcpy(word, result.c_str());
    return word;
}

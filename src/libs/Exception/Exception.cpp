#include "Exception.hpp"

// EXCEPTION UNTUK INPUT
const char *NumericException::what()
{
    return "Input anda tidak valid.\nSilahkan masukkan integer sebagai input.";
}

const char *MoreThanZeroException::what()
{
    return "Input yang anda masukkan harus lebih dari 0.\nSilahkan masukkan input yang sesuai.";
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

const char *InventoryNotEnoughException::what()
{
    return "Slot inventory Anda tidak cukup, tidak bisa menjalankan perintah\n";
}

// EXCEPTION UNTUK KURANG
NotEnoughMoneyException::NotEnoughMoneyException(int kurang)
{
    this->kurang = kurang;
}
const char *NotEnoughMoneyException::what()
{
    ostringstream oss;
    oss << "Gulden Anda tidak cukup, kekurangan " << this->kurang << " gulden\n";
    // Convert the ostringstream to a string and return its char* representation
    string result = oss.str();
    char *word = new char[result.length() + 1];
    strcpy(word, result.c_str());
    return word;
}

const char *NotEnoughStockException::what()
{
    return "Stok dari barang yang diminta tidak mencukupi :( , tidak bisa membeli barang!\n";
}
const char *NotEnoughTanamanException::what()
{
    return "Tanaman Anda tidak cukup, tidak bisa menjalankan perintah\n";
}
const char *NotEnoughPanenException::what()
{
    return "Jumlah Panen Anda tidak cukup\n";
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
    return "Indeks yang Anda masukkan tidak valid!.\nPastikan Indeks Anda sesuai.\n";
}

const char *FileNotFoundException::what()
{
    return "File yang diberikan tidak ditemukan!.\nPastikan path file Anda sesuai.\n";
}

const char *InvalidJenisTanamanException::what()
{
    return "Jenis tanaman yang Anda masukkan tidak valid!.\nPastikan Jenis Tanaman Anda sesuai.\n";
}

const char *InvalidJenisHewanException::what()
{
    return "Jenis hewan yang Anda masukkan tidak valid!.\nPastikan Jenis Hewan Anda sesuai.\n";
}

const char *InvalidJenisProdukMaterialException::what()
{
    return "Jenis produk material yang Anda masukkan tidak valid!.\nPastikan Jenis Produk Material Anda sesuai.\n";
}

const char *InvalidJenisProdukBuahException::what()
{
    return "Jenis produk buah yang Anda masukkan tidak valid!.\nPastikan Jenis Produk Buah Anda sesuai.\n";
}

const char *InvalidJenisProdukHewanException::what()
{
    return "Jenis produk hewan yang Anda masukkan tidak valid!.\nPastikan Jenis Produk Hewan Anda sesuai.\n";
}

const char *InvalidJenisBangunanException::what()
{
    return "Jenis bangunan yang Anda masukkan tidak valid!.\nPastikan Jenis Bangunan Anda sesuai.\n";
}

const char *InvalidProdukException::what()
{
    return "Masukkan Anda bukan jenis Makanan, silakan masukkan jenis yang benar\n";
}
const char *InvalidJenisMakananException::what()
{
    return "Jenis makanan yang Anda pilih tidak sesuai dengan jenis hewan Anda.\n";
}

const char *InvalidJenisSellableException::what()
{
    return "Jenis sellable yang Anda masukkan tidak valid!.\nPastikan Jenis Sellable Anda sesuai.\n";
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
    oss << "Kamu tidak punya sumber daya yang cukup!\nMasih memerlukan ";

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
            oss << it->second << " " << it->first;
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

const char *InvalidSellException::what()
{
    return "Anda tidak boleh menjual bangunan!\n";
}
#include "Exception.hpp"

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
    return "Input yang anda masukkan merupakan milik dari Walikota !\nSilahkan masukkan input yang sesuai dengan role anda!";
}

const char *InvalidCommandException::what()
{
    return "Command yang Anda masukkan tidak valid!.\n Pastikan Command Anda sesuai.\n";
}

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
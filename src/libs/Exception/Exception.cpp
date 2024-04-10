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

const char *StorageFullException::what()
{
    return "Storage sudah penuh!.\n Silahkan jual barang terlebih dahulu.\n";
}

const char *LadangFullException::what()
{
    return "Ladang sudah penuh!.\n Silahkan panen terlebih dahulu.\n";
}

const char *TernakFullException::what()
{
    return "Ternak sudah penuh!.\n Silahkan panen terlebih dahulu.\n";
}

const char *NotEnoughMoneyException::what()
{
    return "Uang Anda tidak cukup!.\n Silahkan kumpulkan uang terlebih dahulu :)\n";
}

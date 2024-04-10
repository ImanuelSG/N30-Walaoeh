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

const char *StorageFullException::what(){
    return "";
}

const char *LadangFullException::what(){
    return "";
}

const char *TernakFullException::what(){
    return "";
}

const char *NotEnoughMoneyException::what(){
    return "";
}

const char *NotEnoughHewanException::what(){
    return "";
}
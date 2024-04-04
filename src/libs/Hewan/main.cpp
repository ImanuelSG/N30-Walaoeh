#include "Hewan.cpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    // Hewan a;
    // a.setIdBarang(1);
    // a.setHargaBarang(1000);
    // cout << a.getIdBarang() << endl;
    // cout << a.getHargaBarang() << endl;

    Hewan hewan = Hewan::tambahHewan();
    // // ctrl + alt + N
    // cout << "Ini Output: ";
    // cout << hewan.getIdBarang() << ' ';
    // cout << hewan.getKodeHuruf() << ' ';
    // cout << hewan.getNamaBarang() << ' ';
    // cout << hewan.getTipeHewan() << ' ';
    // cout << hewan.getWeight() << ' ';
    // cout << hewan.getHargaBarang() << endl;

    // hewan.tambahWeightHewan(10);

    // cout << "Ini Output Berat setelah ditambah: ";
    // cout << hewan.getIdBarang() << ' ';
    // cout << hewan.getKodeHuruf() << ' ';
    // cout << hewan.getNamaBarang() << ' ';
    // cout << hewan.getTipeHewan() << ' ';
    // cout << hewan.getWeight() << ' ';
    // cout << hewan.getHargaBarang() << endl;

    // ifstream inFile("../File Config/animal.txt");
    // vector<Hewan> hewanList;

    // if (!inFile)
    // {
    //     cerr << "Unable to open file" << endl;
    //     return 1;
    // }

    // while (inFile.peek() != EOF)
    // {
    //     Hewan hewan = Hewan::tambahHewan(inFile);
    //     hewanList.push_back(hewan);

    //     cout << "ID: " << hewan.getIdBarang() << ", "
    //          << "Kode: " << hewan.getKodeHuruf() << ", "
    //          << "Nama: " << hewan.getNamaBarang() << ", "
    //          << "Tipe: " << hewan.getTipeHewan() << ", "
    //          << "Berat: " << hewan.getWeight() << ", "
    //          << "Harga: " << hewan.getHargaBarang() << endl;
    // }

    // inFile.close();
    return 0;
}
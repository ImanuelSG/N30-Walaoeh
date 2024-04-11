#include "../src/libs/Hewan/Hewan.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    // Hewan a;
    // a.setIdHewan(1);
    // a.setHargaBarang(1000);
    // cout << a.getIdHewan() << endl;
    // cout << a.getHargaBarang() << endl;

    // Hewan hewan = Hewan::tambahHewan();
    // // // ctrl + alt + N
    // cout << "Ini Output: ";
    // cout << hewan.getIdHewan() << ' ';
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

    ifstream inFile("src/libs/FileConfig/animal.txt");
    vector<Hewan> hewanList;

    if (!inFile)
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    while (inFile.peek() != EOF)
    {
        Hewan hewan = Hewan::tambahHewanConfig(inFile);
        hewanList.push_back(hewan);

        cout << "ID: " << hewan.getIdHewan() << ", "
             << "Kode: " << hewan.getKodeHurufHewan() << ", "
             << "Nama: " << hewan.getNamaBarang() << ", "
             << "Tipe: " << hewan.getTipeHewan() << ", "
             << "Berat: " << hewan.getWeight() << ", "
             << "Berat Panen: " << hewan.getWeightToHarvest() << ", "
             << "Harga: " << hewan.getHargaBarang() << endl;
    }

    inFile.close();
    return 0;
}
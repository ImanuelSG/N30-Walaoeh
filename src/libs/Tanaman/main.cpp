#include "Tanaman.cpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    Tanaman t;
    t.setIdBarang(1);
    t.setHargaBarang(1000);
    cout << t.getIdBarang() << endl;
    cout << t.getHargaBarang() << endl;

    // Tanaman tanaman = Tanaman::tambahTanaman();
    //ctrl + alt + N
    // cout << "Ini Output: ";
    // cout << tanaman.getIdBarang() << ' ';
    // cout << tanaman.getKodeHuruf() << ' ';
    // cout << tanaman.getNamaBarang() << ' ';
    // cout << tanaman.getTipeTanaman() << ' ';
    // cout << tanaman.getDurationToHarvest() << ' ';
    //cout << tanaman.getHargaBarang() << endl;

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
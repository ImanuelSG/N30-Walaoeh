#include "Tanaman.cpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    // Tanaman t;
    // t.setIdTanaman(1);
    // t.setHargaBarang(1000);
    // cout << t.getIdTanaman() << endl;
    // cout << t.getHargaBarang() << endl;

    // Tanaman tanaman = Tanaman::tambahTanaman();

    // cout << "Ini Output: ";
    // cout << tanaman.getIdTanaman() << ' ';
    // cout << tanaman.getKodeHuruf() << ' ';
    // cout << tanaman.getNamaBarang() << ' ';
    // cout << tanaman.getTipeTanaman() << ' ';
    // cout << tanaman.getAge() << ' ';
    // cout << tanaman.getDurationToHarvest() << ' ';
    // cout << tanaman.getHargaBarang() << endl;

    // tanaman.tambahUmurTanaman(10);

    // cout << "Ini Output Berat setelah ditambah: ";
    // cout << tanaman.getIdTanaman() << ' ';
    // cout << tanaman.getKodeHuruf() << ' ';
    // cout << tanaman.getNamaBarang() << ' ';
    // cout << tanaman.getTipeTanaman() << ' ';
    // cout << tanaman.getAge() << ' ';
    // cout << tanaman.getDurationToHarvest() << ' ';
    // cout << tanaman.getHargaBarang() << endl;

    ifstream inFile("../File Config/plant.txt");
    vector<Tanaman> tanamanList;

    if (!inFile)
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    while (inFile.peek() != EOF)
    {
        Tanaman tanaman = Tanaman::tambahTanamanConfig(inFile);
        tanamanList.push_back(tanaman);

        cout << "ID: " << tanaman.getIdTanaman() << ", "
             << "Kode: " << tanaman.getKodeHuruf() << ", "
             << "Nama: " << tanaman.getNamaBarang() << ", "
             << "Tipe: " << tanaman.getTipeTanaman() << ", "
             << "Umur: " << tanaman.getAge() << ", "
             << "Harga: " << tanaman.getHargaBarang() << endl;
    }

    inFile.close();
    return 0;
}
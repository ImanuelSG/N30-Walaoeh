#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>

#include "../src/libs/ProdukHewan/ProdukHewan.hpp"

using namespace std;

int main()
{
     Hewan h1 = Hewan(0, 1, "CHK", "CHICKEN", "OMNIVORE", 100, 50, 10000);

     auto p1 = ProdukHewan::tambahProdukHewanOmnivora(h1);

     cout << "ID: " << p1.first.getIdProduk() << ", "
          << "Kode: " << p1.first.getKodeHuruf() << ", "
          << "Nama: " << p1.first.getNamaBarang() << ", "
          << "Tipe: " << p1.first.getTipeProduk() << ", "
          << "Origin: " << p1.first.getOrigin() << ", "
          << "Added Weight: " << p1.first.getAddedWeight() << ", "
          << "Harga: " << p1.first.getHargaBarang() << endl;

     cout << "ID: " << p1.second.getIdProduk() << ", "
          << "Kode: " << p1.second.getKodeHuruf() << ", "
          << "Nama: " << p1.second.getNamaBarang() << ", "
          << "Tipe: " << p1.second.getTipeProduk() << ", "
          << "Origin: " << p1.second.getOrigin() << ", "
          << "Added Weight: " << p1.second.getAddedWeight() << ", "
          << "Harga: " << p1.second.getHargaBarang() << endl;

     Hewan h2 = Hewan(0, 1, "COW", "COW", "HERBIVORE", 200, 100, 20000);

     ProdukHewan p2 = p2.tambahProdukHewanHerbivora(h2);

     cout << "ID: " << p2.getIdProduk() << ", "
          << "Kode: " << p2.getKodeHurufProdukHewan() << ", "
          << "Nama: " << p2.getNamaBarang() << ", "
          << "Tipe: " << p2.getTipeProduk() << ", "
          << "Origin: " << p2.getOrigin() << ", "
          << "Added Weight: " << p2.getAddedWeight() << ", "
          << "Harga: " << p2.getHargaBarang() << endl;

     // ifstream inFile("../File Config/product.txt");
     // vector<ProdukHewan> produkHewan;

     // if (!inFile)
     // {
     //     cerr << "Unable to open file" << endl;
     //     return 1;
     // }

     // while (inFile.peek() != EOF)
     // {
     //     ProdukHewan p = ProdukHewan::tambahProdukHewan(inFile);
     //     produkHewan.push_back(p);

     //     cout << "ID: " << p.getIdProduk() << ", "
     //          << "Kode: " << p.getKodeHuruf() << ", "
     //          << "Nama: " << p.getNamaBarang() << ", "
     //          << "Tipe: " << p.getTipeProduk() << ", "
     //          << "Origin: " << p.getOrigin() << ", "
     //          << "Added Weight: " << p.getAddedWeight() << ", "
     //          << "Harga: " << p.getHargaBarang() << endl;
     // }

     // inFile.close();

     return 0;
}
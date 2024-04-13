#ifndef PETANI_HPP
#define PETANI_HPP

#include "../Pemain.hpp"
#include "../../Toko/Sellable/Tanaman/Tanaman.hpp"

class Petani : public Pemain
{
private:
    static int ladang_m;
    static int ladang_n;
    Storage<Tanaman> ladang;

public:
    Petani(string name, int gulden, int berat);
    ~Petani();
    void tanam();
    void panen();
    void cetakLadang();
    void addPlantAge();
    int countTanamanInventory();
    int getKekayaan();
    int getKKP();
    string getRole() const;

    void setLadang(const Storage<Tanaman> &storage);

    static int getUkuranLadangN();
    static int getUkuranLadangM();
    static void setUkuranLadangN(int n);
    static void setUkuranLadangM(int m);

    // Konversi tanaman menjadi produk (buah) kalau weight sudah mencapai weight_to_harvest
    Sellable *tambahProdukTanamanBuah(Tanaman &tanaman);
    // Konversi tanaman menjadi produk (material) kalau weight sudah mencapai weight_to_harvest
    Sellable *tambahProdukTanamanMaterial(Tanaman &tanaman);
};

#endif
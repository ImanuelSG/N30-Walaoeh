#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include <iostream>
#include "Storage/Storage.hpp"
#include "../Sellable/Sellable.hpp"
#include "../Exception/Exception.hpp"


using namespace std;
class Pemain
{
protected:
    const static int inventory_n;
    const static int inventory_m;
    string name;
    int gulden;
    int berat;
    Storage<Sellable*> inventory;
public:
    Pemain(string name, int gulden, int berat);
    ~Pemain();
    /**
     * @brief Getter nama pemain
     * 
     * @return string 
     */
    string getName() const;
    /**
     * @brief Getter gulden pemain
     * 
     * @return int 
     */
    int getGulden() const;
    /**
     * @brief Getter berat pemain
     * 
     * @return int 
     */
    int getBerat() const;
    /**
     * @brief Setter untuk nama pemain
     *
     */
    void setName(string name);
    /**
     * @brief Setter untuk Gulden pemain
     *
     */
    void setGulden(int gulden);
    /**
     * @brief Setter untuk berat pemain
     *
     */
    void setBerat(int berat);
    /**
     * @brief Makan untuk menambah berat pemain
     *
     */
    void makan();
    /**
     * @brief Menyelesaikan turn pemain saat ini, memberikan turn kepada pemain selanjutnya
     *
     */
    void next();
    /**
     * @brief Mencetak Inventory pemain saat ini
     *
     */
    void cetakPenyimpanan();
    /**
     * @brief Melakukan Pemungutan Pajak, Khusus untuk walikota
     *
     */
    virtual void pungutPajak();
    virtual void cetakLadang();
    virtual void cetakPeternakan();
    virtual void tanam();
    virtual void ternak();
    /**
     * @brief Membangun Bangunan, Khusus untuk walikota
     * 
     */
    virtual void bangun();
    virtual void kasihMakan();
    virtual void beli() = 0;
    virtual void jual() = 0;
    virtual void panen();
    /**
     * @brief Menambah Pemain baru, Khusus untuk walikota
     * 
     */
    virtual void tambahPemain();
};

#endif
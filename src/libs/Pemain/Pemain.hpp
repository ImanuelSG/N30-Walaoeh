#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include <vector>
#include "../Exception/Exception.hpp"
#include "../Sellable/Sellable.hpp"
#include "iostream"
using namespace std;
class Pemain
{
protected:
    static int inventory_n;
    static int inventory_m;
    vector<Sellable *> inventory;

    string name;
    int gulden;
    int berat;
    // storage
public:
    Pemain(string name, int gulden, int berat);
    ~Pemain();
    /**
     * @brief Getter nama pema
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
    void setName();
    /**
     * @brief Setter untuk Gulden pemain
     *
     */
    void setGulden(int num);
    /**
     * @brief Setter untuk berat pemain
     *
     */
    void setBerat(int num);
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
     * @brief Menghitung Kekayaan pemain
     */
    int getKekayaan() const;
    /**
     * @brief Pungut Pajak, Khusus untuk walikota
     *
     * @param pemain vector pemain yang akan dikenakan pajak
     */
    virtual void pungutPajak(const vector<Pemain *> &pemain);
    virtual void cetakLadang();
    virtual void cetakPeternakan();
    virtual void tanam();
    virtual void ternak();
    /**
     * @brief Membangun Bangunan, Khusus untuk walikota
     *
     */
    virtual void bangunBangunan();
    virtual void kasihMakan();
    virtual void beli();
    virtual void jual();
    virtual void panen();
    /**
     * @brief Menambah pemain atau peternak, Khusus untuk walikota
     *
     * @param pemain vector pemain yang akan dimanipulasi
     * @return index pemain baru (untuk menentukan urutan main nantinya)
     */
    virtual int tambahPemain(vector<Pemain *> &pemain);

    virtual int getKKP();
    virtual string getRole() const = 0;
};

#endif
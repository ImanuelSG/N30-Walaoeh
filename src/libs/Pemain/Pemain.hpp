#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include <iostream>

using namespace std;
class Pemain
{
protected:
    static int inventory_n;
    static int inventory_m;
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
    void setGulden();
    /**
     * @brief Setter untuk berat pemain
     *
     */
    void setBerat();
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
    virtual void pungutPajak() = 0;
    virtual void cetakLadang() = 0;
    virtual void cetakPeternakan() = 0;
    virtual void tanam() = 0;
    virtual void ternak() = 0;
    /**
     * @brief Membangun Bangunan, Khusus untuk walikota
     * 
     */
    virtual void bangun() = 0;
    virtual void makan() = 0;
    virtual void kasihMakan() = 0;
    virtual void beli() = 0;
    virtual void jual() = 0;
    virtual void panen() = 0;
    /**
     * @brief Menambah Pemain baru, Khusus untuk walikota
     * 
     */
    virtual void tambahPemain() = 0;
};

#endif
#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "../Pemain.hpp"
#include "../Petani/Petani.hpp"
#include "../Peternak/Peternak.hpp"
#include "../../Toko/Sellable/Bangunan/Bangunan.hpp"
#include "../../Utils/Utils.hpp"

#include <vector>
#include <cmath>
using namespace std;

class Walikota : public Pemain
{
public:
    /**
     * @brief User Defined Constructor
     *
     * @param name
     * @param gulden
     * @param berat
     */
    Walikota(string name, int gulden, int berat);
    /**
     * @brief Destroy the Walikota object
     *
     */
    ~Walikota();
    /**
     * @brief tagihPajak, helper function to get the tax for a certain player
     *
     * @param pemain
     * @return int
     */
    int tagihPajak(Pemain *pemain);
    /**
     * @brief pungutPajak, function to collect tax from all players
     *
     * @param pemain
     */
    void pungutPajak(const vector<Pemain *> &pemain) override;
    /**
     * @brief bangunBangunan, method to build a building
     *
     */
    void bangunBangunan() override;
    /**
     * @brief tambahPemain, method to add a player
     *
     * @param pemain
     * @return int, the new player index (needed to adjust whos gonna be playing next)
     */
    int tambahPemain(vector<Pemain *> &pemain) override;
    /**
     * @brief Get the material and its quantity from walikota inventory
     *
     * @return map<string, int>
     */
    map<string, int> getMaterialProduct();
    /**
     * @brief Get the Role of this walikota (walikota)
     *
     * @return string
     */

    string getRole() const;

    int getKKP() ;

    void azab();
};

#endif
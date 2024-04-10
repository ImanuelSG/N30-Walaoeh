#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "../Pemain.hpp"
#include "../Petani/Petani.hpp"
#include "../Peternak/Peternak.hpp"
#include "../../Utils/Utils.hpp"


#include <vector>
#include <cmath>
using namespace std;
class Walikota : public Pemain
{
public:
    Walikota(string name, int gulden, int berat);
    ~Walikota();
    string getRole() const;
    int tagihPajak(Pemain *pemain);
    void pungutPajak(const vector<Pemain *> &pemain) override;
    void bangunBangunan() override;
    int tambahPemain(vector<Pemain *> &pemain) override;
};

#endif
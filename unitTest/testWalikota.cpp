#include "../src/libs/Pemain/Walikota/Walikota.hpp"
using namespace std;

int main()
{
    Walikota w("Walikota", 1000, 1000);
    vector<Pemain *> pemain;

    pemain.push_back(pemain1);
    pemain.push_back(pemain2);
    w.pungutPajak(pemain);
    return 0;
}
#include "Walikota.hpp"

Walikota::Walikota(string name, int gulden, int berat) : Pemain(name, gulden, berat)
{
}

Walikota::~Walikota()
{
}

void Walikota::pungutPajak(const vector<Pemain *> &pemain)
{
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl;
    cout << endl;
    cout << "Berikut adalah detil dari pemungutan pajak: " << endl;
    int counter = 1;
    int totalpajak = 0;
    int currentpajak;
    for (auto pemain : pemain)
    {
        if (pemain->getName() != this->name)
        {

            currentpajak = tagihPajak(pemain);
            cout << "   " << counter << ". " << pemain->getName() << " - " << pemain->getRole() << ": " << currentpajak << " gulden" << endl;
            counter++;
            totalpajak += currentpajak;
        }
    }
    cout << endl;
    cout << "Negara mendapatkan pemasukan sebesar " << totalpajak << " gulden" << endl;
    cout << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl;

    setGulden(getGulden() + totalpajak);
}

int Walikota::tagihPajak(Pemain *pemain)
{
    // Get kekayaan kena pajak
    int KKP = pemain->getKKP();

    // if less than 0 early exit
    if (KKP <= 0)
        return 0;
    float multiplier;
    // else search for category
    if (KKP <= 6)
        multiplier = 0.05;
    else if (KKP <= 25)
    {
        multiplier = 0.15;
    }
    else if (KKP <= 50)
    {
        multiplier = 0.25;
    }
    else if (KKP <= 500)
    {
        multiplier = 0.3;
    }
    else
    {
        multiplier = 0.35;
    }

    // round to the nearest int
    int totalPajak = round(KKP * multiplier);

    // Cek apakah ada uang yang dapat dibayarkan
    int pajakDibayarkan = min(pemain->getGulden(), totalPajak);

    // Setelah itu, kurangi uang pemain
    pemain->setGulden(pemain->getGulden() - pajakDibayarkan);

    return pajakDibayarkan;
}

int Walikota::tambahPemain(vector<Pemain *> &pemain)
{
    // Check if the Walikota has enough money
    if (this->getGulden() < 50)
    {
        throw NotEnoughMoneyException();
    }
    else
    {

        string jenisPemain = "";
        string namaPemain = "";
        do
        {
            cout << "Masukkan jenis pemain: ";
            cin >> jenisPemain;
            if (jenisPemain != "Peternak" && jenisPemain != "peternak" && jenisPemain != "Petani" && jenisPemain != "petani")
            {
                cout << "Jenis pemain tidak valid!" << endl;
            }

        } while (jenisPemain != "Peternak" && jenisPemain != "peternak" && jenisPemain != "Petani" && jenisPemain != "petani");

        do
        {
            cout << "Masukkan nama pemain: ";
            cin >> namaPemain;
            if (namaPemain == "")
            {
                cout << "Nama pemain tidak boleh kosong!" << endl;
            }
            for (auto pemain : pemain)
            {
                if (toLowercase(pemain->getName()) == toLowercase(namaPemain))
                {
                    cout << "Nama pemain sudah ada, silahkan coba nama yang lain!" << endl;
                    namaPemain = "";
                }
            }

        } while (namaPemain == "");

        Pemain *newPemain;
        if (jenisPemain == "Peternak" || jenisPemain == "peternak")
        {
            newPemain = new Peternak(namaPemain, 50, 40);
        }
        else
        {
            newPemain = new Petani(namaPemain, 50, 40);
        }

        // Search for the right position to input the new Player
        bool found = false;
        int index = 0;
        while (!found && index < pemain.size())
        {

            if ((toLowercase(pemain[index]->getName()) > toLowercase(namaPemain)))

            {
                found = true;
                pemain.insert(pemain.begin() + index, newPemain);
            }
            else
            {
                index++;
            }
        }
        if (!found)
        {
            pemain.push_back(newPemain);
        }

        cout << endl;
        cout << "Pemain baru ditambahkan!" << endl;
        cout << "Selamat datang \"" << namaPemain << "\" di kota ini!" << endl;

        // Kurangi uang Walikota
        this->setGulden(this->getGulden() - 50);
        // Return the new Player index
        return index;
    }
}

void Walikota::bangunBangunan()
{

    if (this->inventory.isFull())
    {
        throw InventoryFullException();
    }
    Bangunan bangunan;

    bangunan.displayAllRecipe();

    string namaBangunan;
    do
    {
        cout << "Bangunan yang ingin dibangun: ";
        cin >> namaBangunan;
        if (namaBangunan.empty())
        {
            cout << "Nama bangunan tidak boleh kosong!" << endl;
        }
        else if (!bangunan.isValidRecipe(namaBangunan))
        {
            cout << "Kamu tidak punya resep bangunan tersebut!" << endl;
        }

    } while (namaBangunan.empty() || !bangunan.isValidRecipe(namaBangunan));

    // Get the recipe to check
    tuple<string, int, vector<tuple<string, int>>> recipe = bangunan.getSpecificRecipe(namaBangunan);

    int neededGulden = get<1>(recipe);
    vector<tuple<string, int>> neededMaterials = get<2>(recipe);

    // Get all materialProduct from walikota

    map<string, int> materialProduct = this->getMaterialProduct();

    //Display needed materials
    
}

string Walikota::getRole() const
{
    return "Walikota";
}

int Walikota::getKKP() const
{
    return 0;
}

map<string, int> Walikota::getMaterialProduct()
{
    map<string, int> materialProduct;

    // Iterate through all inventory items
    for (int i = 0; i < inventory.getRow(); i++)
    {
        for (int j = 0; j < inventory.getCol(); j++)
        {
            // Check if the item is a product material
            if ((inventory.getElementAddress(i, j)->getJenis())== "PRODUK_TANAMAN_MATERIAL")
            {
                // Get the name of the item
                string itemName = inventory.getElementAddress(i, j)->getNamaBarang();

                // Check if the item already exists in materialProduct
                if (materialProduct.find(itemName) != materialProduct.end())
                {
                    // Increment the count if the item exists
                    materialProduct[itemName]++;
                }
                else
                {
                    // Initialize the count to 1 if the item doesn't exist
                    materialProduct[itemName] = 1;
                }
            }
        }
    }
    return materialProduct;
}
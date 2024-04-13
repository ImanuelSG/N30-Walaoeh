#include "Walikota.hpp"

Walikota::Walikota(string name, int gulden, int berat) : Pemain(name, gulden, berat)
{
}

Walikota::~Walikota()
{
}

void Walikota::pungutPajak(const vector<Pemain *> &listpemain)
{
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl;
    cout << endl;
    cout << "Berikut adalah detil dari pemungutan pajak: " << endl;
    int counter = 1;
    int totalpajak = 0;
    int currentpajak;
    vector<Pemain *> temp(listpemain);
    temp.erase(remove_if(temp.begin(), temp.end(), [this](Pemain *pemain)
                         { return pemain->getName() == this->name; }),
               temp.end());
    stable_sort(temp.begin(), temp.end(), [](Pemain *a, Pemain *b)
                { return a->getPajak() > b->getPajak(); });

    for (auto pemain : temp)
    {
        // If the player is not himself
        if (pemain->getName() != this->name)
        {

            currentpajak = pemain->getPajak();
            cout << "   " << counter << ". " << pemain->getName() << " - " << pemain->getRole() << ": " << currentpajak << " gulden" << endl;
            counter++;
            pemain->setGulden(pemain->getGulden() - currentpajak);
            totalpajak += currentpajak;
        }
    }
    cout << endl;
    cout << "Negara mendapatkan pemasukan sebesar " << totalpajak << " gulden" << endl;
    cout << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl;
    setGulden(getGulden() + totalpajak);
}

int Walikota::tambahPemain(vector<Pemain *> &pemain)
{
    // Check if the Walikota has enough money
    if (this->getGulden() < 50)
    {
        throw NotEnoughMoneyException(50 - this->getGulden());
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
            newPemain = new Peternak(namaPemain, 50, 0);
        }
        else
        {
            newPemain = new Petani(namaPemain, 50, 0);
        }

        // Search for the right position to input the new Player
        bool found = false;
        int index = 0;
        while (!found && index < pemain.size())
        {

            if (pemain[index]->getName() > namaPemain)

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

    // if (this->inventory.isFull())
    // {
    //     throw InventoryFullException();
    // }

    Bangunan::displayAllRecipe();
    cout << endl;

    string namaBangunan;
    do
    {

        cout << "Bangunan yang ingin dibangun: ";
        cin >> namaBangunan;
        if (namaBangunan.empty())
        {
            cout << "Nama bangunan tidak boleh kosong!" << endl;
        }
        else if (!Bangunan::isValidRecipe(namaBangunan))
        {
            cout << "Kamu tidak punya resep bangunan tersebut!" << endl;
        }

    } while (namaBangunan.empty() || !Bangunan::isValidRecipe(namaBangunan));

    // Get the recipe to check
    // tuple<string, int, map<string, int>> recipe = bangunan.getSpecificRecipe(namaBangunan);

    // int neededGulden = get<1>(recipe);
    // vector<tuple<string, int>> neededMaterials = get<2>(recipe);

    // Get all materialProduct from walikota
    map<string, int> materialProduct = this->getMaterialProduct();

    // Build the desired building
    tuple<Sellable *, int, map<string, int>> result = Bangunan::build(namaBangunan, materialProduct, this->getGulden());

    // If it ever reaches this point, the building is successfully built, because else it will throw exception

    // Add the building to inventory
    Sellable *actualBuilding = get<0>(result);
    int usedGulden = get<1>(result);
    map<string, int> usedMaterial = get<2>(result);

    // change gulden

    this->setGulden(this->getGulden() - usedGulden);

    // remove material from inventory
    int i = 0;
    while (i < inventory.getRow() && !usedMaterial.empty())
    {
        int j = 0;
        while (j < inventory.getCol() && !usedMaterial.empty())
        {
            string name = inventory.getElementAddress(i, j)->getNamaBarang();
            if (usedMaterial.find(name) != usedMaterial.end())
            {
                usedMaterial[name]--;
                if (usedMaterial[name] == 0)
                {
                    usedMaterial.erase(name);
                }
                Sellable &item = inventory.deleteAt(i, j);
                delete &item;
            }
            j++;
        }
        i++;
    }

    // Add actual building to inventory
    inventory.insert(*actualBuilding);
    cout << namaBangunan << " berhasil dibangun dan telah menjadi hak miliki walikota!" << endl;
}

string Walikota::getRole() const
{
    return "Walikota";
}

int Walikota::getKKP()
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
            if (inventory.getElementAddress(i, j) != nullptr && (inventory.getElementAddress(i, j)->getJenis()) == "PRODUK_TANAMAN_MATERIAL")
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

void Walikota::azab()
{
    if (gulden != 0)
    {  
        this->gulden = (int) (gulden * 0.67);
        cout << "Wakwaw dewa siwa marah!!! Kamu terciduk KPK" << endl;
        cout << "Karena koneksimu sebagai walikota banyak, guldenmu hanya berkurang 1/3 dari total keseluruhan" << endl;
    }
    else
    {
        cout << "Tadinya kamu membuat dewa siwa marah!!, namun karena kamu tidak memiliki gulden lagi dewa siwa kasian\nKamu tidak terkena apa apa" << endl;
    }
}
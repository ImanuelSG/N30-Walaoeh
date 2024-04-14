#include "Pemain.hpp"

int Pemain::inventory_n = 5;
int Pemain::inventory_m = 5;

// Constructor , destructor
Pemain::Pemain(string name, int gulden, int berat) : name(name), gulden(gulden), berat(berat), inventory(inventory_n, inventory_m)
{
}
Pemain::~Pemain() {}

// Getter Setter
int Pemain::getGulden() const
{
    return this->gulden;
}

int Pemain::getBerat() const
{
    return this->berat;
}

string Pemain::getName() const
{
    return this->name;
}

int Pemain::getKekayaan()
{
    int count = gulden;
    for (int i = 0; i < inventory.getRow(); i++)
    {
        for (int j = 0; j < inventory.getCol(); j++)
        {
            Sellable *item = inventory.getElementAddress(i, j);
            if (item != nullptr)
            {
                count += item->getHargaBarang();
            }
        }
    }
    return count;
}

int Pemain::getPajak()
{
    if (getRole() == "Walikota")
    {
        return 0;
    }
    else
    {
        // Get kekayaan kena pajak
        int KKP = getKKP();
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
        int pajakDibayarkan = min(getGulden(), totalPajak);

        // // Setelah itu, kurangi uang pemain
        // pemain->setGulden(pemain->getGulden() - pajakDibayarkan);

        return pajakDibayarkan;
    }
}

void Pemain::setName(string name)
{
    this->name = name;
}

void Pemain::setGulden(int gulden)
{
    this->gulden = gulden;
}

void Pemain::setBerat(int berat)
{
    this->berat = berat;
}

// Command
void Pemain::makan()
{
    // Jika inventory kosong
    if (inventory.isEmpty())
    {
        throw InventoryEmptyException();
    }

    // Jika tidak ada makanan
    if (!isFoodAvailable())
    {
        throw NotEnoughFoodException();
    }
    // blom di implement

    cetakPenyimpanan();
    bool valid = false;
    string slot;

    do
    {

        bool acc = false;
        int col = 0;
        int row = 0;
        do
        {
            slot = getValidInputStorage("Slot");

            col = getColStorage(slot[0]);
            row = getRowStorage(slot);

            if (col < 0 || col > inventory.getCol() || row < 0 || row > inventory.getRow())
            {
                cout << RED << "Masukkan lokasi petak yang sesuai!" << RESET << endl;
            }
            else
            {
                acc = true;
            }

        } while (!acc);

        Sellable *item = inventory.getElementAddress(row, col);

        if (item == nullptr)
        {
            cout << RED << "Kamu mengambil harapan kosong dari penyimpanan." << endl;
            cout << "Silahkan masukan slot yang berisi makanan." << endl
                 << RESET << endl;
        }
        else if (item->isEdible())
        {
            inventory.deleteAt(row, col);
            int addedWeight = item->getAddedWeight();

            setBerat(getBerat() + addedWeight);
            valid = true;
            cout << GREEN << "Dengan lahapnya, kamu memakanan hidangan itu" << endl;
            cout << "Alhasil, berat badan kamu naik menjadi " << RESET << YELLOW << berat
                 << RESET << endl;
        }
        else if (!item->isEdible())
        {
            cout << RED << "Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!" << endl;
            cout << "Silahkan masukan slot yang berisi makanan." << endl
                 << RESET << endl;
        }
    } while (!valid);
}

void Pemain::next() {}

void Pemain::cetakPenyimpanan()
{
    display(inventory);
    cout << endl;
    cout << "Total Slot Kosong: " << CYAN << inventory.countEmptySlot() << RESET << endl;
}

void Pemain::pungutPajak(const vector<Pemain *> &pemain)
{
    throw WalikotaInputException();
}

void Pemain::cetakLadang()
{
    throw PetaniInputException();
}

void Pemain::cetakPeternakan()
{
    throw PeternakInputException();
}

void Pemain::tanam()
{
    throw PetaniInputException();
}

void Pemain::ternak()
{
    throw PeternakInputException();
}

void Pemain::bangunBangunan()
{
    throw WalikotaInputException();
}

void Pemain::kasihMakan()
{
    throw PeternakInputException();
}

void Pemain::panen()
{
    throw PanenInputException();
}

void Pemain::beli(Toko &toko)
{
    // Display all buyable for a certain role
    toko.displayAllBuyableItem(getRole());
    cout << endl;

    cout << "Uang Anda : " << CYAN << getGulden() << RESET << " gulden" << endl;
    cout << "Slot penyimpanan tersedia : " << CYAN << inventory.countEmptySlot() << RESET << endl;

    // Get the input
    int num;
    do
    {
        cout << "Masukkan nomor barang yang ingin dibeli: ";
        cin >> num;

        if (cin.fail())
        {

            cout << RED << "Input tidak valid, silahkan coba lagi" << RESET << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (!toko.isValidItem(num, getRole()))
        {
            cout << RED << "Input tidak valid, silahkan coba lagi" << RESET << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (!toko.isValidItem(num, getRole()));
    // Get the quantity
    int quantity;

    cout << "Kuantitas : ";
    cin >> quantity;
    // Case not a number

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw NumericException();
    }
    // Case item less than 0

    if (quantity <= 0)
    {
        throw MoreThanZeroException();
    }

    // Case quantity too much

    if (inventory.countEmptySlot() < quantity)
    {
        throw InventoryNotEnoughException();
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // All things validated so we can buy the item
    tuple<Sellable *, int> item = toko.Beli(num, getRole(), getGulden(), quantity);

    cout << "Selamat Anda berhasil membeli " << CYAN << quantity << " " << get<0>(item)->getNamaBarang() << RESET << endl
         << " dengan total harga " << CYAN << get<1>(item) << RESET << " gulden" << endl;

    setGulden(getGulden() - get<1>(item));
    cout << "Sisa uang Anda : " << CYAN << getGulden() << RESET << " gulden" << endl;

    cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;

    cetakPenyimpanan();

    // Get the slot
    bool valid = false;
    do
    {

        // Parse input
        vector<string> slot = getManyInputStorage("Petak Slot");

        // check if all input is not empty
        if (slot.empty())
        {
            cout << RED << "Input tidak valid, silahkan coba lagi" << RESET << endl;
            continue;
        }

        if (slot.size() != quantity)
        {
            cout << RED << "Jumlah slot yang dimasukkan tidak sesuai dengan jumlah barang yang dibeli" << RESET << endl;
            continue;
        }

        for (auto pos : slot)
        {
            int row = getRowStorage(pos);
            int col = getColStorage(pos[0]);
            cout << row << " " << col << endl;
            if (inventory.getElementAddress(row, col) != nullptr)
            {
                cout << RED << "Slot " << pos << " sudah terisi, silahkan pilih slot lain" << RESET << endl;
                break;
            }
            if (
                row < 0 || row >= inventory.getRow() || col < 0 || col >= inventory.getCol())
            {
                cout << RED << "Slot " << pos << " tidak valid, silahkan pilih slot lain" << RESET << endl;
                break;
            }

            // if all slot is valid
            if (pos == slot.back())
            {
                for (auto pos : slot)
                {
                    Sellable *copy = get<0>(item)->Clone();
                    int row = getRowStorage(pos);
                    int col = getColStorage(pos[0]);
                    inventory.insert(row, col, *copy);
                }
                valid = true;
                // Put the item to the inventory
            }
        }
    } while (!valid);

    cout << GREEN << get<0>(item)->getNamaBarang() << " berhasil disimpan di penyimpanan" << RESET << endl;
}

void Pemain::jual(Toko &toko)
{
    if (inventory.isEmpty())
    {
        throw InventoryEmptyException();
    }
    // Display slots
    cout << "Berikut merupakan penyimpanan Anda";
    display(inventory);
    cout << endl;

    // Get the item to be sold

    // Get the slot
    bool valid = false;
    vector<string> slot;
    vector<Sellable *> items;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    do
    {
        slot = getManyInputStorage("Petak Slot");
        for (auto pos : slot)
        {
            int row = getRowStorage(pos);
            int col = getColStorage(pos[0]);

            if (
                row < 0 || row >= inventory.getRow() || col < 0 || col >= inventory.getCol())
            {
                cout << RED << "Slot " << pos << " tidak valid, silahkan pilih slot lain" << RESET << endl;
                break;
            }
            if (inventory.getElementAddress(row, col) == nullptr)
            {
                cout << RED << "Slot " << pos << " tidak berisi barang, silahkan pilih slot yang valid" << RESET << endl;
                break;
            }

            // if all slot is valid (we reached the end interation, sell the selected item)
            if (pos == slot.back())
            {
                // Put the item want to be sold into the vector array of items
                for (auto pos : slot)
                {
                    int row = getRowStorage(pos);
                    int col = getColStorage(pos[0]);
                    Sellable *item = inventory.getElementAddress(row, col);
                    items.push_back(item);
                }
                valid = true;
            }
        }
    } while (!valid);

    // Sell the item to the shop
    int hasilJual = toko.Jual(items, this->getRole());
    setGulden(getGulden() + hasilJual);

    // Delete from inventory

    for (auto pos : slot)
    {
        int row = getRowStorage(pos);
        int col = getColStorage(pos[0]);
        Sellable &res = inventory.deleteAt(row, col);
        delete &res;
    }

    cout << GREEN << "Barang Anda berhasil dijual!" << endl
         << "Uang Anda bertambah " << RESET << YELLOW << hasilJual << RESET << GREEN << " gulden" << RESET << endl;
}

void Pemain::addPlantAge()
{
    return;
}

int Pemain::tambahPemain(vector<Pemain *> &pemain)
{
    throw WalikotaInputException();
}

bool Pemain::isFoodAvailable()
{
    for (int i = 0; i < inventory.getRow(); i++)
    {
        for (int j = 0; j < inventory.getCol(); j++)
        {
            Sellable *item = inventory.getElementAddress(i, j);
            if (item != nullptr)
            {
                if (item->isEdible())
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void Pemain::setUkuranInventoryM(int m)
{
    inventory_m = m;
}

void Pemain::setUkuranInventoryN(int n)
{
    inventory_n = n;
}

int Pemain::getUkuranInventoryM()
{
    return inventory_m;
}

int Pemain::getUkuranInventoryN()
{
    return inventory_n;
}

void Pemain::displayInfo()
{
    cout << "(❁´◡`❁) Informasi Pemain: (❁´◡`❁) " << endl;

    cout << "Nama: " << name << endl;
    cout << "Role: " << getRole() << endl;
    cout << "Gulden: " << CYAN << gulden << RESET << endl;
    cout << "Berat: " << CYAN << berat << RESET << endl;
    cout << "Kekayaan: " << getKekayaan() << endl;
}

template <>
void display<Sellable>(const Storage<Sellable> &storage)
{
    cout << endl;
    // ================[ Penyimpanan ]==================
    cout << "     ";
    int numOfEq = (1 + 6 * storage.col - 15) / 2; // 15 is len([ Penyimpanan ])
    for (int i = 0; i < numOfEq; i++)
    {
        cout << "=";
    }
    cout << "[ Penyimpanan ]";
    for (int i = 0; i < numOfEq; i++)
    {
        cout << "=";
    }
    cout << endl;

    // Print the letters for each column
    cout << "     ";
    for (char c = 'A'; c < 'A' + storage.col; ++c)
    {
        cout << "   " << c << "  ";
    }
    cout << " " << endl;

    for (int i = 0; i < storage.col; ++i)
    {
        if (i == 0)
        {
            cout << "     +";
        }
        cout << "-----+";
    }
    cout << endl;
    for (int i = 0; i < storage.row; ++i)
    {
        cout << "  " << intToStringWithLeadingZero(i + 1) << " |";
        for (int j = 0; j < storage.col; ++j)
        {
            string keluaran = "";
            if (storage.buffer[i][j] != nullptr)
            {
                keluaran = (*storage.buffer[i][j]).getKodeHuruf();
            }
            if (keluaran == "")
            {
                keluaran = "   ";
            }
            cout << " " << keluaran << " |";
        }
        cout << endl;
        cout << "     +";
        for (int j = 0; j < storage.col; ++j)
        {
            cout << "-----+";
        }
        cout << endl;
    }
}

void Pemain::setInventory(const Storage<Sellable> &storage)
{
    inventory = storage;
}

void Pemain::setPeternakan(const Storage<Hewan> &storage)
{
    return;
}

void Pemain::setLadang(const Storage<Tanaman> &storage)
{
    return;
}

void Pemain::rezeki()
{
    cout << CYAN << "Wah, kamu berhasil lari dari amarah dewa siwa!!" << endl
         << "Dewa siwa sedang baik hati nich (～￣▽￣)～(～￣▽￣)～" << RESET << endl;
    int tambahan = (int)(0.1 * gulden);
    cout << name << " mendapatkan tambahan uang sebanyak " << CYAN << tambahan << RESET << " gulden $$$" << endl;
    gulden += tambahan;
}
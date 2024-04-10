#include "Pemain.hpp"
#include "../Utils/utils.hpp"

const int Pemain::inventory_n = 5;
const int Pemain::inventory_m = 5;

// Constructor , destructor
Pemain::Pemain(string name, int gulden, int berat) : name(name), gulden(gulden), berat(berat), inventory(inventory_n, inventory_m) {}
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

int Pemain::getKekayaan() const
{
    return 0;
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
    if (inventory.isEmpty()){
        throw InventoryEmptyException();
    }

    // Jika tidak ada makanan
    if (!isFoodAvailable()){
        throw NotEnoughFoodException();
    }
    //blom di implement

    cetakPenyimpanan();
    bool valid = false;
    string slot;

    do
    {
        slot = getValidInputStorage("Slot");

        int col = getColStorage(slot[0]);
        int row = getRowStorage(slot);
        
        Sellable* item = inventory.getElementAddress(row,col);
        if (item->isEdible()){
            inventory.deleteAt(row,col);
            int addedWeight = item->getAddedWeight();

            setBerat(getBerat()-addedWeight);
            valid = true;

        } else if (!item->isEdible()) {
            cout << "Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!" << endl;
            cout << "Silahkan masukan slot yang berisi makanan." << endl << endl;

        } else if (item == nullptr ){
            cout << "Kamu mengambil harapan kosong dari penyimpanan." << endl;
            cout << "Silahkan masukan slot yang berisi makanan." << endl << endl;
        }
    } while (!valid);
    
}

void Pemain::next(){}

void Pemain::cetakPenyimpanan(){
    display(inventory);
    cout << endl;
    cout << "Total Slot Kosong: " << inventory.countEmptySlot() << endl;
}


// JGN LUPA GANTI EXEPTION
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

void Pemain::beli()
{
}

void Pemain::jual()
{
}

int Pemain::tambahPemain(vector<Pemain *> &pemain)
{
    throw WalikotaInputException();
}


bool Pemain::isFoodAvailable(){
    for (int i = 0; i < inventory_n; i++) {
        for (int j = 0; j < inventory_m; j++) {
            Sellable* item = inventory.getElementAddress(i,j);
            if (item->isEdible()){
                return true;
            }
        }
    }
    return false;
}

template <>
void display<Sellable>(const Storage<Sellable> &storage)
{
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
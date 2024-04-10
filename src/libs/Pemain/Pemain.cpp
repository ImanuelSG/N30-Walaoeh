#include "Pemain.hpp"

Pemain::Pemain(string name, int gulden, int berat): name(name), gulden(gulden), berat(berat), inventory(inventory_n, inventory_m) {}

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

void Pemain::setName(string name) 
{
    this->name = name;
}

void Pemain::setGulden(int gulden)
{
    this->gulden = gulden;
}

void Pemain::setBerat(int berat){
    this->berat = berat;
}

void Pemain::makan()
{
    cetakPenyimpanan();
    bool valid= false;
    string slot;

    do
    {

    } while ()
    
    


}

void Pemain::next(){}

void Pemain::cetakPenyimpanan(){
    display(inventory);
}

void Pemain::pungutPajak()
{
    throw InvalidCommandException();
}

void Pemain::cetakLadang()
{
    throw InvalidCommandException();
}

void Pemain::tanam()
{
    throw InvalidCommandException();
}

void Pemain::ternak()
{
    throw InvalidCommandException();
}

void Pemain::bangun()
{
    throw InvalidCommandException();
}

void Pemain::kasihMakan()
{
    throw InvalidCommandException();
}

void Pemain::panen()
{
    throw InvalidCommandException();
}

void Pemain::tambahPemain()
{
    throw InvalidCommandException();
}

template<>
void display<Sellable>(const Storage<Sellable>& storage)
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
#include "Peternak.hpp"
#include "../../Utils/Utils.hpp"
#include "../../pcolor/pcolor.h"


int Peternak::ternak_m = 0; int Peternak::ternak_n = 0;
Peternak::Peternak(string name,int gulden, int berat) : Pemain(name,gulden,berat), peternakan(ternak_n,ternak_m) {}

Peternak::~Peternak(){}

void Peternak::ternak(){
    // Kalau peternakan full
    if (peternakan.isFull()){
        throw TernakFullException();
    }
    // Kalau di inventory gak punya hewan
    if (countHewanInventory()==0){
        throw NotEnoughHewanException();
    }

    cout << "Pilih hewan dari penyimpanan" << endl;
    cetakPenyimpananHewan();
    bool valid= false;
    string slot;
    int col = 0;
    int row = 0;
    Sellable* item = nullptr;

    // Slot inventory
    do
    {
        slot = getValidInputStorage("Slot");

        col = getColStorage(slot[0]);
        row = getRowStorage(slot);
         
        item = inventory.getElementAddress(row,col);
        if (item->getJenis() == "HEWAN"){
            valid = true;
        }
        else
        {
            cout << "Barang pada slot tersebut bukanlah Hewan.\n Silakan pilih Slot lain!\n";
        }
    } while (!valid); 

    cout << "Pilih petak tanah yang akan ditinggali" << endl;

    cetakPeternakan();

    bool isEmpty = false;
    string petak;
    int colP = 0;
    int rowP = 0;
    Hewan *cekPetak = nullptr; 

    // validasi kosong ato gak
    do 
    {
        petak = getValidInputStorage("Petak tanah");

        colP = getColStorage(petak[0]);
        rowP = getRowStorage(petak);

        cekPetak = peternakan.getElementAddress(rowP,colP);
        if (cekPetak == nullptr){
            isEmpty = true;

        } else {
            cout << "Petak yang anda pilih tidak kosong.\n Silakan pilih petak kosong." << endl;
        }

    } while (!isEmpty);
    

    // Petak dipilih sudah kosong

    Hewan *hewan = dynamic_cast<Hewan*>(item);
    peternakan.insert(rowP,colP,*hewan);
    inventory.deleteAt(row,col);

    cout << "Dengan hati-hati, kamu meletakkan seekor " << item->getNamaBarang() << " di kandang." << endl << endl;
    cout << item->getNamaBarang() << "telah menjadi peliharaanmu sekarang!";


}

void Peternak::kasihMakan()
{
    if (peternakan.isEmpty()){
        throw TernakEmptyException();
    }


    // klo gak ada makanannya beri pesan aja
    cout << "Pilih petak kandang yang akan ditinggali" << endl;
    cetakPeternakan();
    bool isEmpty = true;
    string petak;
    int colP = 0;
    int rowP = 0;
    Hewan *hewan = nullptr; 

    // validasi kosong ato gak
    do 
    {
        petak = getValidInputStorage("Petak kandang");

        colP = getColStorage(petak[0]);
        rowP = getRowStorage(petak);

        hewan = peternakan.getElementAddress(rowP,colP);
        if (hewan == nullptr){
            cout << "Petak yang anda pilih kosong.\n Silakan pilih petak tidak kosong." << endl;

        } else {
            isEmpty = false;
        }

    } while (isEmpty);

    cout << "Kamu memilih " << hewan->getKodeHuruf() << "untuk diberi makan.\n" << endl;
    cout << "Pilih pangan yang akan diberikan: " << endl;

    

    string tipeHewan = hewan->getTipeHewan();
    // cek ada makanan tipe itu atau gak
    if (isMakananAvailable(tipeHewan)){
        cetakPenyimpanan();
        string slot = getValidInputStorage("Slot");
        int col = getColStorage(slot[0]);
        int row = getRowStorage(slot);
        Sellable* item = inventory.getElementAddress(row,col);

        if(!(item->getJenis() == "PRODUK_TANAMAN_BUAH") || !(item->getJenis() == "PRODUK_HEWAN")){
            throw InvalidProdukException(); 
        }
        else
        {
            if ((hewan->isCarnivore() && (item->getJenis() == "PRODUK_HEWAN")) || (hewan->isHerbivore() && (item->getJenis() == "PRODUK_TANAMAN_BUAH")) || (hewan->isOmnivore() && ((item->getJenis() == "PRODUK_TANAMAN_BUAH") || (item->getJenis() == "PRODUK_HEWAN"))))
            {
                // tambah berat
                hewan->setWeight(hewan->getWeight() + 1);
                cout << hewan->getKodeHuruf() << "sudah diberi makan dan beratnya menjadi " << hewan->getWeight() << endl;
                // hapus barang dri inventory
                inventory.deleteAt(col,row);
            }
            else
            {
                throw InvalidJenisMakananException();
            }
        }

    } else 
    {
        cout << "Anda tidak memiliki jenis makanan yang sesuai untuk tipe hewan Anda\n" << endl;
    }
}

void Peternak::panen() 
{
    cetakPeternakan();

    

}

void Peternak::cetakPeternakan() 
{
    display(peternakan);
}

void Peternak::beli(){}

void Peternak::jual(){}

void Peternak::cetakPenyimpananHewan(){}

int Peternak::countHewanInventory(){return 0;}

bool Peternak::isMakananAvailable(string tipeHewan){
    for (int i = 0; i < inventory_n; i++) {
        for (int j = 0; j < inventory_m; j++) {
            Sellable* item = inventory.getElementAddress(i,j);
            
            if (tipeHewan == "CARNIVORE")
            {
                if ((item->getJenis() == "PRODUK_HEWAN")){
                    return true;
                }
            }
            else if (tipeHewan == "HERBIVORE")
            {
                if ((item->getJenis() == "PRODUK_TANAMAN_BUAH")){
                    return true;
                }
            }
            else if (tipeHewan == "OMNIVORE")
            {
                if ((item->getJenis() == "PRODUK_HEWAN") || (item->getJenis() == "PRODUK_TANAMAN_BUAH")){
                    return true;
                }
            }
        }
    }
    return false;
}

int Peternak::getKKP() const
{
    return this->getKekayaan() - 11;
}
string Peternak::getRole() const
{
    return "Peternak";
}

template<>
void display<Hewan>(const Storage<Hewan> &storage){
    // ================[ Penyimpanan ]==================
    cout << "     ";
    int numOfEq = (1 + 6 * storage.col - 10) / 2; // 10 is len([ Ladang ])
    for (int i = 0; i < numOfEq; i++)
    {
        cout << "=";
    }
    cout << "[ Ladang ]";
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
            cout << " ";
            string keluaran = "";
            if (storage.buffer[i][j] != nullptr)
            {
                keluaran = (*storage.buffer[i][j]).getKodeHuruf();
                if ((*storage.buffer[i][j]).isHarvestValid())
                {
                    print_green(keluaran[0]); print_green(keluaran[1]); print_green(keluaran[2]);
                }
                else{
                    print_red(keluaran[0]); print_red(keluaran[1]); print_red(keluaran[2]);
                }
            }
            if (keluaran == "")
            {
                cout << "   ";
            }
            cout << " |";
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

template<>
map<string, tuple<list<string>,int>> readyPanen<Hewan>(const Storage<Hewan> &storage){

}

template<>
void displayItems<Hewan>(const Storage<Hewan> &storage)
{
    set<map<string,string>> Items;
    for (const auto& innerVector : storage.buffer)
    {
        for (Hewan* value : innerVector)
        {
            map<string, string> itemMap;
            itemMap[value->getKodeHuruf()] = value->getNamaBarang();
            Items.insert(itemMap);
        }
    }
    for (const auto& item : Items)
    {
        for (const auto& pair : item)
        {
            std::cout << " - " << pair.first << ": " << pair.second << endl;
        }
    }
}


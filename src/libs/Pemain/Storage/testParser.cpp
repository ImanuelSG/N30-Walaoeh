#include <iostream>
#include <string>

using namespace std;

bool isValidInput(string input) {
    bool valid = false;
    bool has00 = false;
    if (isalpha(input[0])){
        
        int id = 1;
        bool flag = true;
        while (flag && id < input.length()){
            if (isdigit(input[id])){
                // case X00
                if (input[id] == '0' && input[id-1] == '0' && id != 1){
                    has00 = true;
                    break;
                    
                }
                id++;
            } else 
            {
                flag = false;
            }
        }
        if (!has00 && id == input.length()) {
            valid = true;
        }
    }

    return valid;
}

int getCol(char firstChar){
    return firstChar - 'A';
}

int getRow(string input){
    return stoi(input.substr(1))-1;
}


string getValidInputStorage(string order){
    string input;
    bool valid = false;
    do
    {
        cout << order <<" : ";
        cin >> input;
        valid = isValidInput(input);
        if (!valid){
            cout << "Masukkan dengan format yang benar\n";
        } else {
        }
        
    } while (!valid);

    return input;
}

int main() {


    bool valid = false;
    std::string input = getValidInputStorage("Stok");

    
    int col = getCol(input[0]);
    int row = getRow(input);
   
    std::cout << "Parsed column: " << col << ", Parsed row: " << row << std::endl;

    return 0;
}
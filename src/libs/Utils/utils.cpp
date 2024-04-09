#include "utils.hpp"

bool isValidInputStorage(string input) {
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

int getColStorage(char firstChar){
    return firstChar - 'A';
}

int getRowStorage(string input){
    return stoi(input.substr(1))-1;
}


string getValidInputStorage(string order){
    string input;
    bool valid = false;
    do
    {
        cout << order <<" : ";
        cin >> input;
        valid = isValidInputStorage(input);
        if (!valid){
            cout << "Masukkan dengan format yang benar\n";
        } else {
        }
        
    } while (!valid);

    return input;
}


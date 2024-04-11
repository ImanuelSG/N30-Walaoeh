#include <iostream>
#include <string>
#include "../src/libs/Utils/Utils.hpp"
using namespace std;

int main()
{

    bool valid = false;
    std::string input = getValidInputStorage("Stok");

    int col = getCol(input[0]);
    int row = getRow(input);

    std::cout << "Parsed column: " << col << ", Parsed row: " << row << std::endl;

    return 0;
}

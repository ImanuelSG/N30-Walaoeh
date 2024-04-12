#include <iostream>
#include <string>
#include "../src/libs/Utils/Utils.hpp"
#include <vector>
using namespace std;

int main()
{

    bool valid = false;
    vector<string> input = getManyInputStorage("Stok");
    for (auto i : input)
    {
        cout << i << endl;
        int row = getRowStorage(i);
        int col = getColStorage(i[0]);
        std::cout << "Parsed column: " << col << ", Parsed row: " << row << std::endl;
    }

    return 0;
}

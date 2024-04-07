#include <iostream>
#include <sstream>
#include <filesystem>
#include <fstream>
#include "./libs/Exception/Exception.hpp"
#include "./libs/compile/h.hpp"

#include "Coba-Coba/GameWorld.hpp"

using namespace std;

namespace fs = std::filesystem;

bool isNumber(const string &s)
{
    return !s.empty() && s.find_first_not_of("0123456789") == string::npos;
}

int main()
{
    try
    {
        string path;
        cout << "Mohon masukkan path file: ";
        cin >> path;
        GameWorld g;

        while (!(fs::exists(path) && (path.length() >= 4) && (path.substr(path.length() - 4) == ".txt"))) {
            cout << "Path yang diberikan tidak ditemukan atau bukan file txt. Mohon masukkan ulang path: ";
            cin >> path;
        }

        g.Muat(path);


    }
    catch (const NumericException &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}

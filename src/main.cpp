#include <iostream>
#include "./libs/Exception/Exception.hpp"
#include "./libs/compile/h.hpp"
#include <sstream>

using namespace std;

bool isNumber(const string &s)
{
    return !s.empty() && s.find_first_not_of("0123456789") == string::npos;
}

int main()
{
    try
    {
        string input;
        cout << "Masukkan angka: ";
        cin >> input;

        if (!isNumber(input))
        {
            throw NumericException();
        }

        print2();
    }
    catch (const NumericException &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}

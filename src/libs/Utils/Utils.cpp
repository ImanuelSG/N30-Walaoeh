#include "Utils.hpp"

string toLowercase(const std::string &str)
{
    string result;
    for (char c : str)
    {
        result += std::tolower(c);
    }
    return result;
}

void countdown(int seconds)
{
    for (int i = seconds; i > 0; --i)
    {
        cout << i << "..\n";
        this_thread::sleep_for(chrono::seconds(1)); // Sleep for 1 second
    }
}
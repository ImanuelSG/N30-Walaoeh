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
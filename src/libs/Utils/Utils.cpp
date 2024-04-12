#include "Utils.hpp"

bool isValidInput(string input)
{
    bool valid = false;
    bool has00 = false;
    if (isalpha(input[0]))
    {

        int id = 1;
        bool flag = true;
        while (flag && id < input.length())
        {
            if (isdigit(input[id]))
            {
                // case X00
                if (input[id] == '0' && input[id - 1] == '0' && id != 1)
                {
                    has00 = true;
                    break;
                }
                id++;
            }
            else
            {
                flag = false;
            }
        }
        if (!has00 && id == input.length())
        {
            valid = true;
        }
    }

    return valid;
}

int getColStorage(char firstChar)
{
    return firstChar - 'A';
}

int getRowStorage(string input)
{
    return stoi(input.substr(1)) - 1;
}

string getValidInputStorage(string order)
{
    string input;
    bool valid = false;
    do
    {
        cout << order << " : ";
        cin >> input;
        valid = isValidInput(input);
        if (!valid)
        {
            cout << "Masukkan dengan format yang benar\n";
        }
        else
        {
        }

    } while (!valid);

    return input;
}

string intToStringWithLeadingZero(int num)
{
    if (num < 10)
    {
        return "0" + std::to_string(num);
    }
    else
    {
        return std::to_string(num);
    }
}

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

string intToAlphabet(int n)
{
    if (n < 0 || n >= 26)
    {
        return "Invalid";
    }

    char alphabet = 'A' + n;

    return std::string(1, alphabet);
}

void displayReadyPanen(map<string, tuple<vector<string>, int>> &readyItems)
{
    int count = 1;
    for (const auto &pair : readyItems)
    {
        cout << count << ". " << pair.first << " (" << get<1>(pair.second) << " petak siap panen)" << endl;
        count++;
    }
}
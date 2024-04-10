#include <iostream>
#include <string>
#include <cctype>
#include <thread>
#include <chrono>
using namespace std;

bool isValidInput(string input);

int getCol(char firstChar);
int getRow(string input);

string getValidInputStorage(string order);
string intToStringWithLeadingZero(int num);
string toLowercase(const string &str);

void countdown(int seconds);

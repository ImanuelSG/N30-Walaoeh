#include <iostream>
#include <string>
#include <cctype>
#include <thread>
#include <chrono>
using namespace std;

bool isValidInput(string input);

int getColStorage(char firstChar);
int getRowStorage(string input);

string getValidInputStorage(string order);
string intToStringWithLeadingZero(int num);
string toLowercase(const string &str);

void countdown(int seconds);

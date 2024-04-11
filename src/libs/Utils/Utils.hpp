#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <list>
#include <cctype>
#include <thread>
#include <chrono>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

bool isValidInput(string input);

int getColStorage(char firstChar);
int getRowStorage(string input);

string getValidInputStorage(string order);
string intToStringWithLeadingZero(int num);
string toLowercase(const string &str);

void displayReadyPanen(map<string, tuple<list<string>,int>>& readyItems);
void countdown(int seconds);
string intToAlphabet(int n);
void displayReadyPanen(map<string, tuple<vector<string>,int>>& readyItems);
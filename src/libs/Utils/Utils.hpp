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
#include <sstream>
#include <algorithm>
using namespace std;

bool isValidInput(string input);

int getColStorage(char firstChar);
int getRowStorage(string input);

string getValidInputStorage(string order);
string intToStringWithLeadingZero(int num);
string toLowercase(const string &str);
vector<string> getManyInputStorage(const string &order);
void countdown(int seconds);
string intToAlphabet(int n);
void displayReadyPanen(map<string, tuple<vector<string>, int>> &readyItems);

// https://stackoverflow.com/questions/36499064/how-to-detect-empty-lines-while-reading-from-ifstream-in-c
bool isEmpty(string buffer);
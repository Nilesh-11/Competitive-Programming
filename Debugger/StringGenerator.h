#ifndef STRINGGENERATOR_H
#define STRINGGENERATOR_H
#include<bits/stdc++.h>
#include "Random.h"
using namespace std;

string SimpleRandomizedString(int len, char a, char b);
string SimpleRandomizedString(int length, vector<char> charsList);
string SimpleRandomizedString(int length, bool lowercaseAlpha, bool uppercaseAlpha, bool numeric , vector<char> extraChar);

#endif
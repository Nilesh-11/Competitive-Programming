#include<bits/stdc++.h>
#include "Random.h"
#include "StringGenerator.h"
using namespace std;

string SimpleRandomizedString(int length, char minChar, char maxChar){
    /*
        input parameters:
            length - length of the resulting string
            minChar - minimum character to include
            maxChar - maximum character to include
        output:
            string - randomised string of length "length"
    */
    string res;
    int len = maxChar - minChar + 1;
    for(int i = 0; i < length; i++){
        int x = RandomNum(0, len - 1);
        res += (x + minChar);
    }
    return res;
}

string SimpleRandomizedString(int length, bool lowercaseAlpha = 0, bool uppercaseAlpha = 0, bool numeric = 0, vector<char> extraChar = {}){
    /*
        Input Parameters:
            length - length of the resulting string
            lowercaseAlpha - true to include lowercase alphabets else false
            uppercaseAlpha - true to include uppercase alphabets else false
            numeric - true to include numericals else false
            extraChar - vector of characters to include any extra characters as well

        Output:
            string - resulting string of length "length"
        
    */
    string res;

    vector<char> Chars;
    if(lowercaseAlpha) {
        for(char i = 'a'; i <= 'z'; i++){
            Chars.push_back(i);
        }
    }
    if(uppercaseAlpha) {
        for(char i = 'A'; i <= 'Z'; i++){
            Chars.push_back(i);
        }
    }
    if(numeric) {
        for(char i = '0'; i <= '9'; i++){
            Chars.push_back(i);
        }
    }
    for(auto &c : extraChar){
        Chars.push_back(c);
    }

    for(int i = 0; i < length; i++){
        int index = RandomNum(0, (int)Chars.size() - 1);
        res += Chars[index];
    }
    return res;
}

string SimpleRandomizedString(int length, vector<char> charsList){
    /*
        Input parameters:
            length - length of the resulting string
            charsList - array of characters
        
        Output:
            string - resulting string of length "length"

    */
    string res;

    for(int i = 0; i < length; i++){
        int x = RandomNum(0, (int)charsList.size() - 1);
        res += charsList[x];
    }
    return res;
}
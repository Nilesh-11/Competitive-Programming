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

char getChar(int code){
    switch(code){
        case 1:
            return RandomNum(0, 25) + 'a';
            break;
        case 2:
            return RandomNum(0, 25) + 'A';
            break;
        case 3:
            return RandomNum(0, 9) + '0';
            break;
        default:
            cerr << "Line: " << __LINE__ <<  " = Error : No code found" << endl;
            break;
    }
    return 0;
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

    vector<int> need;
    if(lowercaseAlpha) need.push_back(1);
    if(uppercaseAlpha) need.push_back(2);
    if(numeric) need.push_back(3);
    if(!extraChar.empty()) need.push_back(4);

    for(int i = 0; i < length; i++){
        int index = RandomNum(0, (int)need.size() - 1);
        char c;
        if(need[index] == 4){
            c = extraChar[RandomNum(0, (int)extraChar.size() - 1)];
        }
        else{
            c = getChar(need[index]);
        }
        res += c;
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
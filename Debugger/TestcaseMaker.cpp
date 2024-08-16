#include<bits/stdc++.h>
#include "TreeGenerator.h"
#include "ArrayGenerator.h"
#include "StringGenerator.h"
#include "Random.h"
using namespace std;

#define ll long long;

int main(){

    ofstream outfile("testcase.txt");

    if (!outfile){
        cerr << "File could not be opened!" << endl;
        return 1;
    }

    srand(time(0));

    // write everything below this line

    cout << "10\n";
    for(int i = 0; i < 10; i++){
        string nodes = SimpleRandomizedString(3, 1, 1, 1, {});
        cout << nodes << '\n';
    }
    return 0;
}
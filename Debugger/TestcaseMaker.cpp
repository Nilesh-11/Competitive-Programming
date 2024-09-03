#include<bits/stdc++.h>
#include "TreeGenerator.h"
#include "ArrayGenerator.h"
#include "StringGenerator.h"
#include "GraphGenerator.h"
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

    // write everything below this line and use "outfile" instead of "cout"
    outfile << "1\n";
    int n = RandomNum(1, 8);
    outfile << n << "\n";
    vector<int> a = STLRandomPermutation(n, 1);
    vector<int> b = a;
    random_shuffle(b.begin(), b.end());
    for(auto x : a){
        outfile << x << ' ';
    }
    outfile << '\n';
    for(auto x : b){
        outfile << x << ' ';
    }
    return 0;
}
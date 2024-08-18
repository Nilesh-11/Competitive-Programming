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
    outfile << "10 20\n";
    vector<pair<int,int>> edges = simpleRandomGraph(10, 20, 1);
    for(auto [x, y] : edges){
        outfile << x << ' ' << y << '\n';
    }
    return 0;
}
#include<bits/stdc++.h>
#include "TreeGenerator.h"
#include "ArrayGenerator.h"
using namespace std;

#define ll long long

int RandomNum(int min, int max){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

int main(){

    ofstream outfile("testcase.txt");

    if (!outfile){
        cerr << "File could not be opened!" << endl;
        return 1;
    }

    int max_n = 50;
    srand(time(0));
    int nodes = RandomNum(3, max_n);
    outfile << 1 << '\n';
    outfile << nodes << '\n';
    vector<int> a = STLRandomArray(nodes);
    vector<int> v = {a[0], a[1], a[2]};
    for(int i = 0; i < v.size(); i++){
        if(i == (int)v.size() - 1){
            outfile << v[i] << '\n';
        }
        else outfile << v[i] << ' ';
    }
    vector<pair<int, int>> edges =  SimpleRandomTreeGenerator(nodes);
    for(int i = 0; i < edges.size(); i++){
        outfile << edges[i].first << ' ' << edges[i].second << '\n';
    }

    return 0;
}
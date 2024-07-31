#include<bits/stdc++.h>
using namespace std;

vector<int> STLRandomArray(int n){
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    random_shuffle(v.begin(), v.end());
    return v;
}
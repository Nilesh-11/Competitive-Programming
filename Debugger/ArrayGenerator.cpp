#include<bits/stdc++.h>
using namespace std;

vector<int> STLRandomPermutation(int length, int start = 0){
    vector<int> res(length);
    iota(res.begin(), res.end(), start);
    random_shuffle(res.begin(), res.end());
    return res;
}
#ifndef TREEGENERATOR_H
#define TREEGENERATOR_H

#include<bits/stdc++.h>
#include <fstream>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

vector<pair<int, int>> SimpleRandomTreeGenerator(int n);
vector<pair<int, int>> PruferRandomTreeGenerator(int n);
vector<pair<int, int>> CentroidRandomTreeGenerator(long long nodes);

#endif
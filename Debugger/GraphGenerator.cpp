#include <bits/stdc++.h>
#include "ArrayGenerator.h"
#include "Random.h"
using namespace std;

vector<pair<int,int>> generateGraph(vector<int> &nodes, int edges){
    int n = nodes.size();
    vector<pair<int,int>> res;
    map<int, int> len;
    multiset<pair<int, int>> tracker;

    for(auto node : nodes){
        len[node] = 0;
        tracker.insert({0, node});
    }

    random_shuffle(nodes.begin(), nodes.end());

    for(int i = 1; i < nodes.size(); i++){
        res.push_back({nodes[i], nodes[i - 1]});

        tracker.erase({len[nodes[i]], nodes[i]});
        len[nodes[i]]++;
        tracker.insert({len[nodes[i]], nodes[i]});
        tracker.erase({len[nodes[i - 1]], nodes[i - 1]});
        len[nodes[i - 1]]++;
        tracker.insert({len[nodes[i - 1]], nodes[i - 1]});

        edges--;
    }

    map<int, bool> bad;

    for(int k = 0; k < edges; k++){
        while(!tracker.empty() && len[tracker.rbegin()->second] == n - 1){
            bad[tracker.rbegin()->second] = true;
            tracker.erase(--tracker.end());
        }
        if(nodes.size() <= 1 || tracker.empty()){
            break;
        }

        int i = RandomNum(0, (int)nodes.size() - 1);
        int node1 = nodes[i];
        while(nodes.size() > 1 && bad[nodes[i]] == true){
            swap(nodes[i], nodes[(int)nodes.size() - 1]);
            nodes.pop_back();
            i = RandomNum(0, (int)nodes.size() - 1);
            node1 = nodes[i];
        }
        if(nodes.size() <= 1) break;
        swap(nodes[i], nodes[nodes.size() - 1]);
        int j = RandomNum(0, (int)nodes.size() - 2);
        while(nodes.size() > 2 && bad[nodes[j]] == true){
            swap(nodes[j], nodes[(int)nodes.size() - 2]);
            swap(nodes[(int)nodes.size() - 2], nodes[(int)nodes.size() - 1]);
            nodes.pop_back();
            j = RandomNum(0, (int)nodes.size() - 2);
        }
        if(nodes.size() <= 1) break;
        int node2 = nodes[j];
        swap(nodes[i], nodes[nodes.size() - 1]);

        res.push_back({node1, node2});

        tracker.erase({len[node1], node1});
        len[node1]++;
        tracker.insert({len[node1], node1});
        tracker.erase({len[node2], node2});
        len[node2]++;
        tracker.insert({len[node2], node2});
    }

    return res;
}

vector<pair<int,int>> simpleRandomGraph(int nodes, int edges, int connectedComponents = 1){
    vector<pair<int,int>> res;

    int minEdges = nodes - connectedComponents;
    int maxEdges = ((minEdges + 1) * minEdges) / 2;

    assert(minEdges <= edges && edges <= maxEdges);

    vector<int> have = STLRandomPermutation(nodes, 0);

    vector<vector<int>> componentNodes(connectedComponents);
    vector<int> componentSize(connectedComponents, 0);
    vector<int> nonEmptyComponent;
    map<int, bool> bad;

    for(int i = 0; i < connectedComponents; i++){
        componentNodes[i].push_back(have.back());
        nonEmptyComponent.push_back(i);
        have.pop_back();
    }
    while(!have.empty()){
        int comp = RandomNum(0, connectedComponents - 1);
        componentNodes[comp].push_back(have.back());
        have.pop_back();
    }
    while(edges > 0){
        int j = RandomNum(0, (int)nonEmptyComponent.size() - 1);
        while(bad[nonEmptyComponent[j]] == true){
            swap(nonEmptyComponent[j], nonEmptyComponent[(int)nonEmptyComponent.size() - 1]);
            nonEmptyComponent.pop_back();
            j = RandomNum(0, (int)nonEmptyComponent.size() - 1);
        }
        j = nonEmptyComponent[j];
        int mnEdges = componentNodes[j].size() - 1;
        int mxEdges = (componentNodes[j].size() * ((int)componentNodes[j].size() - 1)) / 2;

        mnEdges -= componentSize[j];
        mnEdges = max(1, mnEdges);
        mxEdges -= componentSize[j];
        mxEdges = min(edges, mxEdges);
        if(mxEdges < mnEdges){
            bad[j] = true;
            continue;
        }
        int sz = RandomNum(mnEdges, mxEdges);
        componentSize[j] += sz;
        edges -= sz;
    }


    // int remaining = edges - connectedComponents;
    // vector<int> partitions;
    // for(int i = 0; i < connectedComponents - 1; i++){
    //     partitions.push_back(RandomNum(0, remaining));
    // }

    // partitions.push_back(remaining);
    // sort(partitions.begin(), partitions.end());

    // for(int i = 0; i < connectedComponents; i++){
    //     if(i == 0){
    //         componentSize[i] = partitions[i];
    //     }
    //     else {
    //         componentSize[i] = partitions[i] - partitions[i - 1];
    //     }

    //     for(int j = 0; j < componentSize[i]; j++){
    //         componentNodes[i].push_back(have.back());
    //         have.pop_back();
    //     }
    // }
    for(int i = 0; i < connectedComponents; i++){
        vector<pair<int,int>> componentEdges = generateGraph(componentNodes[i], componentSize[i]);
        for(auto e : componentEdges){
            res.push_back(e);
        }
    }

    return res;
}
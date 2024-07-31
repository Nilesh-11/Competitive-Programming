#include "TreeGenerator.h"
#define ll long long
#define pbds tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

// has error of vector larger than max_size
vector<pair<int, int>> CentroidRandomTreeGenerator(ll nodes)
{
    ll numberOfNodes = nodes;
    vector<pair<int, int>> res;

    srand(time(0));

    pbds includedInTree;
    pbds notIncludedInTree;

    ll root = 1; // almost centroid

    // uncomment the below line to create random root
    root = ((ll)rand() * rand()) % nodes + 1;
    cout << root << endl;
    includedInTree.insert(root);

    for (ll i = 1; i <= numberOfNodes; i++)
    {
        if (i != root)
        {
            notIncludedInTree.insert(i);
        }
    }

    for (ll i = 0; i < numberOfNodes - 1; i++)
    {
        ll r = rand();
        ll incSize = includedInTree.size();

        r %= incSize;

        auto itU = includedInTree.find_by_order(r);
        ll u = *itU;

        r = rand();

        ll notIncSize = notIncludedInTree.size();

        r %= notIncSize;

        auto itV = notIncludedInTree.find_by_order(r);
        ll v = *itV;

        notIncludedInTree.erase(itV);
        includedInTree.insert(v);
        res.push_back({u, v});
    }
    return res;
}

// O(n * n)
vector<pair<int, int>> PruferRandomTreeGenerator(int n){
    vector<pair<int, int>> edges;
    auto printTreeEdges = [&](vector<int> prufer, int m){
        int vertices = m + 2;
        vector<int> vertex_set(vertices);

        // Initialize the array of vertices
        for (int i = 0; i < vertices; i++)
            vertex_set[i] = 0;

        // Number of occurrences of vertex in code
        for (int i = 0; i < vertices - 2; i++)
            vertex_set[prufer[i] - 1] += 1;
        int j = 0;

        // Find the smallest label not present in
        // prufer[].
        for (int i = 0; i < vertices - 2; i++)
        {
            for (j = 0; j < vertices; j++)
            {

                // If j+1 is not present in prufer set
                if (vertex_set[j] == 0)
                {

                    // Remove from Prufer set and print
                    // pair.
                    vertex_set[j] = -1;
                    edges.push_back({j + 1, prufer[i]});
                    // outfile << (j + 1) << ' ' << prufer[i] << '\n';

                    vertex_set[prufer[i] - 1]--;

                    break;
                }
            }
        }
        j = 0;

        // For the last element
        int u = -1;
        for (int i = 0; i < vertices; i++){
            if (vertex_set[i] == 0 && j == 0){
                u = i + 1;
                // outfile << (i + 1) << ' ';
                j++;
            }
            else if (vertex_set[i] == 0 && j == 1)
                edges.push_back({u, i + 1});
                // outfile << (i + 1) << '\n';
        }
    };
    // generate random numbers in between l an r
    auto ran = [](int l, int r)
    {
        return l + (rand() % (r - l + 1));
    };

    int length = n - 2;
    vector<int> arr(length);

    // Loop to Generate Random Array
    for (int i = 0; i < length; i++)
    {
        arr[i] = ran(0, length + 1) + 1;
    }
    printTreeEdges(arr, length);
    return edges;
}

// O(n * logn)
vector<pair<int, int>> SimpleRandomTreeGenerator(int n){
    // if indexing of nodes, does not matter this is ok
    // cause 1 - 2 will always be there
    vector<pair<int,int>> edges;
    for(int i = 2; i <= n; i++){
        int u = (rand() % (i - 1) + 1);
        edges.push_back({u, i});
    }
    return edges;
}

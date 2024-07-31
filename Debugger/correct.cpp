#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define NUM1 1000000007LL
#define all(a) a.begin(), a.end()
#define beg(a) a.begin(), a.begin()
#define sq(a) ((a)*(a))
#define NUM2 998244353LL
#define MOD NUM2
#define fi first
#define se second
typedef long double ld;
const ll MAX = 2'000'010;
const ll INF = (LLONG_MAX/10);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void dfs(vector<int> adj[], int st, int par, vector<int>& prt, vector<int>& dep)
{
    prt[st] = par;
    for(auto& x: adj[st]){
        if(x != par){
            dep[x] = 1 + dep[st];
            dfs(adj, x, st, prt, dep);
        }
    }
}
const int M = 20;

void solve()
{
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    a -= 1; b -= 1; c -= 1;
    vector<int> adj[n];
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u -= 1; v -= 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> prt(n);
    vector<int> dep(n);
    dfs(adj, 0, 0, prt, dep);
    vector<vector<int>> up(n, vector<int>(M));
    for(int i = 0; i < n; i++) up[i][0] = prt[i];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < n; i++) up[i][j] = up[up[i][j - 1]][j - 1];
    }
    auto jump = [&](int v, int dep)
    {
        for(int j = M - 1; j >= 0; j--) if(dep >= (1ll << j)){
            dep -= (1ll << j);
            v = up[v][j];
        }
        return v;
    };
    auto lca = [&](int u, int v)
    {
        if(dep[v] > dep[u]) swap(u, v);
        u = jump(u, dep[u] - dep[v]);
        if(u == v) return u;
        for(int j = M - 1; j >= 0; j--){
            if(up[u][j] != up[v][j]){
                u = up[u][j];
                v = up[v][j];
            }
        }
        return prt[u];
    };
    auto dist = [&](int a, int b)
    {
        int l = lca(a, b);
        return dep[a] + dep[b] - 2*dep[l];
    };
    int dab = dist(a, b), dbc = dist(b, c), dac = dist(a, c);
    if(dab + dbc == dac){
        cout << "B\n";
        return;
    }
    else if(dac + dbc == dab){
        if(dac == 1){
            cout << "A\n";
        }
        else{
            cout << "C\n";
        }
        return;
    }
    else if(dab + dac == dbc){
        cout << "A\n";
        return;
    }
    int lab = lca(a, b), lbc = lca(b, c), lac = lca(a, c);
    int jn = lab;
    if(dep[lbc] > dep[jn]) jn = lbc;
    if(dep[lac] > dep[jn]) jn = lac;
    int da = dist(a, jn), db = dist(b, jn), dc = dist(c, jn);
    if(da < db && da <= dc + 1){
        cout << "A\n";
        return;
    }
    if(db < dc && db <= da){
        cout << "B\n";
        return;
    }
    if(dc + 1 < da && dc <= db){
        cout << "C\n";
        return;
    }
    cout << "DRAW\n";
}


signed main(){
    #ifndef ONLINE_JUDGE
        freopen("testcase.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}

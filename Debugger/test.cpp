#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#define debug(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define debug(...)
#endif

#define  IOS 	      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  ll  	      long long
#define  rep(i,a,b)   for(ll i = a ; i < b ; i ++)
#define  Rep(i,a,b)   for(ll i = a ; i >= b ; i --)
#define  fi  	      first
#define  se  	      second
#define  pb  	      push_back
#define  pf  	      push_front
#define  mk  	      make_pair
#define  vi  	      vector<ll>
#define  pi  	      pair<ll,ll>
#define  vp  	      vector<pi>
#define  vvp  	      vector<vp>
#define  vv  	      vector<vi>
#define  all(v)  	  v.begin(),v.end()
const ll MOD = 1000000007;
const ll INF = 3e18 + 5;
const ll N = 2e5 + 5;
ll n;
ll a,b,c;
vv g(N);

void dfs(ll u, ll par, vi &dis, vi &Par){
    for(auto &v : g[u]){
        if(v == par) continue;
        Par[v] = u;
        dis[v] = dis[u] + 1;
        dfs(v, u, dis, Par);
    }
}

ll LCA(ll a, ll b, vi &dis, vi &par){
    ll cnt = 0;
    while(dis[a] < dis[b] && cnt < n){
        b = par[b];
        cnt++;
        assert(b >= 0);
    }
    while(dis[a] > dis[b] && cnt < n){
        a = par[a];
        cnt++;
        assert(a >= 0);
    }
    while(a != b && cnt < n){
        cnt++;
        a = par[a];
        b = par[b];
        assert(a >= 0);
        assert(b >= 0);
    }
    return a;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("testcase.txt", "r", stdin);
    #endif

    IOS;
    ll tc; cin>>tc;
    while(tc--){
        cin >> n;
        cin >> a >> b >> c;
        a--, b--, c--;
        rep(i, 0, n - 1){
            ll u,v;
            cin >> u >> v;
            u--, v--;
            g[u].pb(v);
            g[v].pb(u);
        }

        vi dis(n + 1, 0);
        vi par(n + 1, 0);

        dfs(a, -1, dis, par);
        par[a] = a;
        ll mid = LCA(b, c, dis, par);
        dis[mid] = 0;
        dfs(mid, -1, dis, par);

        set<ll> s;
        s.insert(dis[a]);
        s.insert(dis[b]);
        s.insert(dis[c]);

        if(s.size() == 1){
            cout << "DRAW\n";
            continue;
        }

        ll ans = -1;
        ll mn = min(dis[a], min(dis[b], dis[c]));
        if (s.size() == 2){
            if(dis[a] == mn && dis[b] == mn) ans = 1;
            else if(dis[b] == mn && dis[c] == mn) ans = (dis[a] > mn + 1 ? 2 : -1);
            else if(dis[a] == mn && dis[c] == mn) ans = 0;
            else if(dis[a] == mn) ans = 0;
            else if(dis[b] == mn) ans = 1;
            else if(dis[c] == mn) ans = (dis[a] == mn + 1 ? (dis[a] == 1 ? 0 : -1) : 2);
        }
        else if(s.size() == 3){
            if(dis[a] == mn) ans = 0;
            if(dis[b] == mn) ans = 1;
            if(dis[c] == mn) ans = (dis[a] == mn + 1 ? 0 : 2);
        }

        if(ans == -1){
            cout << "DRAW\n";
        }
        else cout << char(ans + 'A') << '\n';

        rep(i, 0, n) g[i].clear();
    }

}
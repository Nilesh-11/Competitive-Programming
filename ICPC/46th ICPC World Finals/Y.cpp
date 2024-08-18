#include <bits/stdc++.h>
using namespace std;

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

int main(){

    IOS;
    ll tc; cin>>tc;
    while(tc--){
        string s,a;
        cin >> s;
        ll n = s.size();
        rep(i, 0, n){
            if(i > 0 && s[i] == s[i - 1]) continue;
            if(s[i] == '1') a += '1';
            else a += '0';
        }
        ll len = min(3, (int)a.size());
        if(a.size() % 2 == 0) len = 2;
        rep(i, 0, len){
            cout << a[i];
        }
        cout << '\n';
    }

}
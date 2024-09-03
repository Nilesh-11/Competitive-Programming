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


template<class T>
class SegmentTree{
private:
    struct Node{
        T val;
        int cnt;
        T lazy;
    };

    int n;
    vector<Node> tree;
    
    T build(int p, int l, int r, const vector<T> &v){
        if(l == r){
            tree[p].val = v[l];
            tree[p].cnt = 1;
            tree[p].lazy = 0;
        }
        else{
            int m = (l + r) / 2;
            T leftVal = build(2 * p, l, m, v);
            T rightVal = build(2 * p + 1, m + 1, r, v);
            tree[p].val = min(leftVal, rightVal);
            tree[p].cnt = 0;
            if(tree[p].val == leftVal){
                tree[p].cnt += tree[2 * p].cnt;
            }
            if(tree[p].val == rightVal){
                tree[p].cnt += tree[2 * p + 1].cnt;
            }
            tree[p].lazy = 0;
        }
        return tree[p].val;
    }

    T find_val_at(int p, int l, int r, int pos){
        if(l == r) {
            return tree[p].val + tree[p].lazy;
        }
        else{
            int m = (l + r) / 2;
            if(pos <= m){
                return tree[p].lazy + find_val_at(2 * p, l, m, pos);
            }
            else{
                return tree[p].lazy + find_val_at(2 * p + 1, m + 1, r, pos);
            }
        }
    }

    pair<T, int> find_min(int p, int l, int r, int x, int y){
        pair<T, int> res = pair<T, int>(numeric_limits<T>::max(), 0);
        if(y < l || x > r);
        else if(l >= x && y >= r){
            res = {tree[p].lazy + tree[p].val, tree[p].cnt};
        }
        else if(l == r);
        else{
            int m = (l + r) / 2;
            pair<T, int> leftNode = find_min(2 * p, l, m, x, y);
            pair<T, int> rightNode = find_min(2 * p + 1, m + 1, r, x, y);
            res = {min(leftNode.first, rightNode.first), 0};
            if(res.first == leftNode.first){
                res.second += leftNode.second;
            }
            if(res.first == rightNode.first){
                res.second += rightNode.second;
            }
            res.first += tree[p].lazy;
        }
        return res;
    }

    T update(int p, int l, int r, int x, int y, T val){
        if(y < l || x > r){
            return tree[p].lazy + tree[p].val;
        }
        else if(l >= x && y >= r){
            tree[p].lazy += val;
            return tree[p].lazy + tree[p].val;
        }
        else if(l == r) return tree[p].lazy + tree[p].val;
        else{
            int m = (l + r) / 2;
            T leftVal = update(2 * p, l, m, x, y, val);
            T rightVal = update(2 * p + 1, m + 1, r, x, y, val);
            tree[p].val = min(leftVal, rightVal);
            tree[p].cnt = 0;
            if(tree[p].val == leftVal){
                tree[p].cnt += tree[2 * p].cnt;
            }
            if(tree[p].val == rightVal){
                tree[p].cnt += tree[2 * p + 1].cnt;
            }
        }
        return tree[p].lazy + tree[p].val;
    }

public:

    SegmentTree() : n(0){}
    SegmentTree(int sz){
        this->n = sz;
        tree.resize(4 * n);
        vector<T> v(n, 0);
        build(1, 0, n - 1, v);
    }
    SegmentTree(const vector<T> &v){
        this->n = v.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, v);
    }

    pair<T, int> find_min(int l, int r){
        return find_min(1, 0, n - 1, l, r);
    }

    T find_minVal(int l, int r){
        return find_min(1, 0, n - 1, l, r).first;
    }

    int find_minCnt(int l, int r){
        return find_min(1, 0, n - 1, l, r).second;
    }

    T find_val_at(int pos){
        return find_val_at(1, 0, n - 1, pos);
    }

    T update(int l, int r, T val){
        return update(1, 0, n - 1, l, r, val);
    }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("testcase.txt", "r", stdin);
    #endif
    IOS;
    ll tc; cin>>tc;
    while(tc--){
        ll n;
        cin >> n;
        vi a(n), b(n);
        map<ll, ll> ma, mb;
        rep(i, 0, n){
            cin >> a[i];
            ma[a[i]] = i;
        }
        bool f = 1;
        rep(i, 0, n){
            cin >> b[i];
            mb[b[i]] = i;
            if(ma.find(b[i]) == ma.end()) f = 0;
        }

        if(!f){
            cout << "NO\n";
            continue;
        }

        // SegmentTree<ll> t(n);
        ll ans = 0;
        rep(i, 0, n){
            ll j = mb[a[i]];
            if(i < j){
                ans += 1;
                mb[b[i]] = j;
                swap(b[i], b[j]);
            }
        }
        cout << (ans % 2 == 0 ? "YES\n" : "NO\n");


    }

}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<double,double> pd;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<bool> vbool;
 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int i = 1; i <= n; i++)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define F first
#define S second

void prefix_prom(vll& v){
    for(int i = 1; i < v.size(); i++){
        v[i] = v[i-1] + v[i];
    }
    for(int i = 1; i < v.size(); i++){
        if(v[0] < v[i]/(i+1)){
            v[i] = v[0];
        } else{
            v[i] = v[i]/(i+1);
        }
    }
}

bool check(vll v, ll n){
    for(int i = 1; i < v.size(); i++){
        if(v[i-1] < n) return false;
        v[i] = v[i] + v[i-1] - n;
    }
    if(v[v.size() - 1] >= n) return true;
    else return false;
}

long long nivel(vll v){
    ll l = 0;
    ll r = v[0];
    if(check(v,r)) return r;
    while(l+1 < r){
        ll m = l + (r-l)/2;
        if(check(v,m)) l = m;
        else r = m;
    }
    return l;
}

vll prefix(vll v, int n){
    vll res;
    for(int i = 0; i <= n; i++){
        res.pb(v[i]);
    }
    return res;
}


int main() {
    int t;
    cin >> t;
    F0(i,t){
        int n;
        vll v;
        cin >> n;
        F0(i,n){
            int a;
            cin >> a;
            v.pb(a);
        }
        /* 
        prefix_prom(v);
        */
        F0(i,n){
            cout << nivel(prefix(v,i)) << " ";
        }
        cout << "\n";
    }
}
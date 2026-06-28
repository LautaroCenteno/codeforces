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

int main() {
    int n, d;
    cin >> n >> d;
    vi v;
    map<int, int> map;
    ll res = 0;
    F0(i,n){
        int x;
        cin >> x;
        v.pb(x);
    }
    F0(i,n){
        //cout << "v[i] actual: " << v[i] << "\n";
        if(map.count(v[i]/d)){
            //cout << "entra en if" << "\n";
            map[v[i]/d]++;
            //cout << "map[v[i]/d] actual: " << map[v[i]/d] << "\n";
        } else{
            //cout << "entra en else" << "\n";
            map[v[i]/d] = 1;
            //cout << "map[v[i]/d] actual: " << map[v[i]/d] << "\n";
        }
    }

    for(const auto& [k,v] : map){
        if(v > 1) res+=1LL*v*(v-1)/2;
    }

    cout << res;

    return 0;
}
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

const int mINF = -1e9;
unordered_map<int, int> orden;

int viaje(int v, int t, vector<vpi>& g, vi& dp){
    if(t < 0){
        return mINF;
    }
    if(dp[v] != mINF) return dp[v];
    int opt = mINF;
    for(auto [u,p] : g[v]){
        opt = max(opt, 1 + viaje(u,t-p,g,dp));
    }
    dp[v] = opt;
    return dp[v];
}

int main() {
    
    int n, m, t; cin >> n >> m >> t;
    vector<vpi> g(n+1);
    F0(i,m){
        int u, v, c; cin >> u >> v >> c;
        g[u].pb(make_pair(v,c));
    }

    vi dp(n+1, vi(n+1, -1));
    dp[1][1] = t;

    int res = viaje(1,t,g,dp);
    cout << res << "\n";
    vi recorrido;
    recorrido.pb(1);
    int actual = 1;
    while(recorrido.size() != res){
        for(auto [u,p] : g[actual]){
            if(dp[u] == dp[actual]-1){
                recorrido.pb(u);
                actual = u;
                break;
            }
        }
    }
    F0(i,recorrido.size()) cout << recorrido[i] << " ";
    cout << "\n";

    return 0;
}
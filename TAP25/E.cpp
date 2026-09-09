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

vi bfs(int n, vvi g, vbool visited, vi t){
    queue<pi> q;
    int turno = 0;
    vi res;
    q.push({n, turno});

    while(!q.empty()){
        pi actual = q.front();
        int nodo = actual.F;
        int turno = actual.S;

        while(res.size() < turno + 1) res.pb(0);
        res[turno] += t[nodo];
        for(const auto& i : g[nodo]){
            if(!visited[i]){
                q.push({i, turno+1});
                visited[i] = true;
            }
        }

        q.pop();
    }



    return res;

}

int main() {
    int n; cin >> n;
    vi t(n);
    for(int i = 1; i < n; i++){
        cin >> t[i];
    }
    vvi g(n);
    F0(i,n-1){
        int u, v; cin >> u >> v;
        g[u-1].pb(v-1);
        g[v-1].pb(u-1);
    }

    vbool visited(n);
    visited[0] = true;

    pi res = {0,0};

    for(const auto& i : g[0]){
        vi cant = bfs(i, g, visited, t);
        
        F0(i, cant.size()){
            if(cant[i] > res.F){
                res.F = cant[i];
                res.S = i+1;
            }
        }
        
    }

    cout << res.F << " " << res.S << "\n";

    return 0;
}
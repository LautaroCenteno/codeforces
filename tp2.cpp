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

vvi bfs(int a, vvi& g, vbool visited){
    queue<int> q;
    queue<int> q2;
    q.push(a);
    q2.push(0);
    
    vvi res;
    while(!q.empty()){
        int num = q2.front();
        int actual = q.front();
        visited[actual] = true;
        if(num < res.size()){
            res[num].pb(actual+1);
        } else{
            res.pb({actual+1});
        }

        F0(i,g[actual].size()){
            if(!visited[g[actual][i]]){
                q.push(g[actual][i]);
                q2.push(num+1);
            }
        }
        q.pop();
        q2.pop();
    }
    return res;
}

int cant_elem(vvi c){
    int res = 0;
    F0(i,c.size()){
        F0(j,c[i].size()) res++;
    }
    return res;
}

bool es_permutacion(vi v1, vi v2){
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    return true;
}

int main() {
    int n; cin >> n;
    vector<unordered_set<int>> g(n);
    vector<int> camino;
    F0(i,n-1){
        int x; int y; cin >> x >> y;
        g[x-1].insert(y-1);
        g[y-1].insert(x-1);
    }
    F0(i,n){
        int a; cin >> a;
        camino.pb(a-1);
    }
    vbool visited(n);
    bool res = true;
    int puntero = 1;
    if(camino[0] != 0) res = false;
    queue<int> q; q.push(camino[0]);
    while(!q.empty()){
        if(!res) break;
        int actual = q.front();
        int vecinos = g[actual].size();
        q.pop();
        F0(i,vecinos){
            if(!g[actual].count(camino[puntero])){
                res = false;
                break;
            }
            g[camino[puntero]].erase(actual);
            q.push(camino[puntero]);
            puntero++;
        }
    }


    if(res) cout << "Yes";
    else cout << "No";
    
    return 0;
}
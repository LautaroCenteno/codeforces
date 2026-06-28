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

void bfs(int n, int k, vvi& g, vi& tipos, vbool& visited){
    queue<int> q;
    //cout << "pushea 0" << "\n";
    q.push(0);
    visited[0] = true;
    vi distancia(n);
    //cout << "distancia[0] = 0" << "\n";
    distancia[0] = 0;
    vi res(k, -1);
    //cout << "res[tipos[0]-1] = distancia[0];" << "\n";
    res[tipos[0]] = distancia[0];
    /*
    F0(i,res.size()){
        cout << res[i] << " ";
    }
    */
    //cout << "\n";

    while(!q.empty()){
        int actual = q.front();
        //cout << "actual = "  << actual << "\n";
        //cout << actual << " ";
        //cout << "\n";
        q.pop();
        F0(i,g[actual].size()){
            //cout << "proceso vecino = "  << g[actual][i] << "\n";
            if(visited[g[actual][i]]) continue;
            //cout << "vecino todavia no visitado :)" << "\n";
            distancia[g[actual][i]] = distancia[actual] + 1;
            //cout << "distancia de vecino = "  << distancia[g[actual][i]] << "\n";
            visited[g[actual][i]] = true;
            //cout << "actualizo estado de visita de vecino a = "  << visited[g[actual][i]] << "\n";
            //cout << "g[actual][i] = "  << g[actual][i] << "\n";
            //cout << "tipos[g[actual][i]] = "  << tipos[g[actual][i]] << "\n";
            // cout << "res[tipos[g[actual][i]]] = "  << res[tipos[g[actual][i]]] << "\n";
            if(res[tipos[g[actual][i]]] < distancia[g[actual][i]]){
                //cout << "ENTRA al bucle res" << "\n";
                res[tipos[g[actual][i]]] = distancia[g[actual][i]];
                //cout << "res[tipos[g[actual][i]]] AHORA es igual a: "  << distancia[g[actual][i]] << "\n";
            }
            //cout << "pusheo vecino: " << g[actual][i] << "\n";
            q.push(g[actual][i]);
        }
    }
    /*
    F0(i, distancia.size()){
        cout << distancia[i] << " ";
    }
    cout << "\n";
    */
    
    F0(i, res.size()){
        cout << res[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vi tipos = {};
    vvi g(n);
    F0(i,n) g[i] = {};
    F0(i, n){
        int t;
        cin >> t;
        tipos.pb(t-1);
    }
    F0(i, m){
        int a, b;
        cin >> a >> b;
        g[a-1].pb(b-1);
        g[b-1].pb(a-1);
    }

    vbool visited(n);

    /*
    F0(i,g.size()){
        F0(j,g[i].size()){
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
    */
    
    /*
    F0(i,tipos.size()){
        cout << tipos[i] << " ";
    }
    cout << "\n";
    */

    bfs(n,k,g,tipos,visited);

    /*
    F0(i, visited.size()){
        cout << visited[i] << " ";
    }
    */

    return 0;
}
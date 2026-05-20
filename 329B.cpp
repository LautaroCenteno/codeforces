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


void dfs_caminos(int i, int j, vector<string>& g, vector<vbool>& visited, vector<pi> camino, vector<vector<pi>>& caminos){
    if(visited[i][j]) return; // aca return false si estoy buscando ciclos
    if(g[i][j] == 'E'){
        camino.pb({i,j});
        caminos.pb(camino);
        return;
    }
    camino.pb({i,j});
    visited[i][j] = true;
    if((i+1) < g.size() && g[i+1][j] != 'T') dfs_caminos((i+1), (j), g, visited, camino, caminos);
    if((i-1) >= 0 && g[i-1][j] != 'T') dfs_caminos((i-1), (j), g, visited, camino, caminos);
    if((j+1) < g[i].size() && g[i][j+1] != 'T') dfs_caminos((i), (j+1), g, visited, camino, caminos);
    if((j-1) >= 0 && g[i][j-1] != 'T') dfs_caminos((i), (j-1), g, visited, camino, caminos);
}

pi pos_start(vector<string> g){
    pi res;
    F0(i,g.size()){
        F0(j,g[i].size()){
            if(g[i][j] == 'S') res = {i,j};
        }
    }
    return res;
}

bool llega_en_n_pasos(int i, int j, int n, pi meta, vector<string>& g, vector<vbool>& visited){
    if(i == meta.first && j == meta.second) return true;
    if(n==0) return false;
    bool res = false;
    n--;
    visited[i][j] = true;
    if((i+1) < g.size() && g[i+1][j] != 'T') res = res && llega_en_n_pasos((i+1), (j), n, meta, g, visited);
    if((i-1) >= 0 && g[i-1][j] != 'T') res = res && llega_en_n_pasos((i-1), (j), n, meta, g, visited);
    if((j+1) < g[i].size() && g[i][j+1] != 'T') res = res && llega_en_n_pasos((i), (j+1), n, meta, g, visited);
    if((j-1) >= 0 && g[i][j-1] != 'T') res = res && llega_en_n_pasos((i), (j-1), n, meta, g, visited);
    return res;
}

int min_peleas(vi v){
    int res = v[0];
    for(int i = 1; i < v.size(); i++){
        if(v[i] < res) res = v[i];
    }
    return res;
}

int main() {
    int r;
    int c;
    cin >> r >> c;
    int temp = r;
    vector<string> g;
    while(temp--){
        string s;
        cin >> s;
        g.pb(s);
    }
    int res;
    pi pos_s = pos_start(g);
    vector<vbool> visited(r, vbool(c));
    vector<pi> camino;
    vector<vector<pi>> caminos;
    vector<pi> breeders;

    dfs_caminos(pos_s.first,pos_s.second,g,visited,camino,caminos);

    vi peleas_por_camino(caminos.size());

    F0(i,g.size()){
        F0(j,g[i].size()){
            if( g[i][j] == '1' || g[i][j] == '2' || g[i][j] == '3' || g[i][j] == '4' || g[i][j] == '5' || g[i][j] == '6' || g[i][j] == '7' || g[i][j] == '8' || g[i][j] == '9') breeders.pb({i,j});
        }
    }

    vector<vbool> visited2(r, vbool(c));

    F0(i,caminos.size()){
        F0(k,breeders.size()){
            F0(j,caminos[i].size()){
                if(llega_en_n_pasos(breeders[k].first, breeders[k].second, j, caminos[i][j], g, visited2)) peleas_por_camino[i] += g[breeders[k].first][breeders[k].second] - '0';
            }
        }
    }

    res = min_peleas(peleas_por_camino);

    /* FUNCIONA
    cout << pos_s.first << " " << pos_s.second << "\n";
    */

    /*FUNCIONA
    F0(i, visited.size()){
        F0(j, visited[i].size()){
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    */

    /*FUNCIONA
    F0(i, caminos.size()){
        F0(j, caminos[i].size()){
            cout << caminos[i][j].first << " " << caminos[i][j].second << ", ";
        }
        cout << "\n";
    }
    */

    /*FUNCIONA
    F0(i, breeders.size()){
        cout << breeders[i].first << " " << breeders[i].second << ", ";
    }
    */

    F0(i,peleas_por_camino.size()){
        cout << peleas_por_camino[i] << ", ";
    }

    //cout << res;
    
    return 0;
}
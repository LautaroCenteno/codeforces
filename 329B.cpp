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


void caminos(int i, int j, vector<string>& g, vector<vbool>& visited, vector<pi> camino, vector<vector<pi>>& caminos){
    if(visited[i][j]) return; // aca return false si estoy buscando ciclos
    if(g[i][j] == 'E'){
        caminos.pb(camino);
        return;
    }
    camino.pb({i,j});
    vistied[i][j] = true;
    for(int i = 0; i < g[s].size(); i++){
        if((i+1) < g.size() ) dfs((i+1), (j), g, visited, camino, caminos);
        if((i-1) < g.size()) dfs((i-1), (j), g, visited, camino, caminos);
        if((j+1) < g.size()) dfs((i), (j+1), g, visited, camino, caminos);
        if((j-1) < g.size()) dfs((i), (j-1), g, visited, camino, caminos);
    }
}

pi pos_s(vector<string> g){
    pi res;
    F0(i,g.size()){
        F0(j,g[i].size()){
            if(g[i][j] == 'S') res = {i,j};
        }
    }
}

bool llega_en_n_pasos(int i, int j, vector<string>& g, vector<vbool>& visited){
    return true;
}

int main() {
    int r;
    int c;
    cin >> r >> c;
    int temp = r;
    vector<string> g;
    F0(i,r){
        string s;
        cin >> s;
        g[i] = s;
    }
    int res;
    pi pos_s = pos_s(g);
    vector<vbool> visited(r, vbool(c));
    vector<pi> camino;
    vector<vector<pi>> caminos;
    vector<pi> breeders;

    caminos(pos_s.first,pos_s.second,g,visited,camino,caminos);

    vi peleas_por_camino(caminos.size());

    F0(i,r){
        F0(j,c){
            if( g[i][j] == '1', g[i][j] == '2', g[i][j] == '3', g[i][j] == '4', g[i][j] == '5', g[i][j] == '6', g[i][j] == '7', g[i][j] == '8', g[i][j] == '9') breeders.pb({i,j})
        }
    }
    F0(i,caminos.size()){
        F0(j,caminos[i].size()){
            F0(k,breeders.size()){
                if(llega_en_n_pasos()) peleas_por_camino[i] += g[breeders[k].first][breeders[k].second] - '0'
            }
        }
    }

    
    res = combates_min(...)

    cout >> res;
    
    return 0;
}
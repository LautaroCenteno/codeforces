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

void bfs_dist(pi s, vector<string>& g, vvi& g_dist, vector<vbool>& visited){
    queue<pi> q;
    visited[s.first][s.second] = true;
    g_dist[s.first][s.second] = 0;
    q.push(s);
    while(!q.empty()){
        if((q.front().first + 1) < g.size() && g[q.front().first + 1][q.front().second] != 'T' && !visited[q.front().first + 1][q.front().second]) {
            g_dist[q.front().first + 1][q.front().second] = g_dist[q.front().first][q.front().second] + 1;
            visited[q.front().first + 1][q.front().second] = true;
            q.push({q.front().first + 1, q.front().second});
        }
        if((q.front().first - 1) >= 0 && g[q.front().first - 1][q.front().second] != 'T' && !visited[q.front().first - 1][q.front().second]){
            g_dist[q.front().first - 1][q.front().second] = g_dist[q.front().first][q.front().second] + 1;
            visited[q.front().first - 1][q.front().second] = true;
            q.push({q.front().first - 1, q.front().second});
        } 
        if((q.front().second + 1) < g[q.front().first].size() && g[q.front().first][q.front().second + 1] != 'T' && !visited[q.front().first][q.front().second + 1]){
            g_dist[q.front().first][q.front().second + 1] = g_dist[q.front().first][q.front().second] + 1;
            visited[q.front().first][q.front().second + 1] = true;
            q.push({q.front().first, q.front().second + 1});
        } 
        if((q.front().second - 1) >= 0 && g[q.front().first][q.front().second - 1] != 'T' && !visited[q.front().first][q.front().second - 1]){
            g_dist[q.front().first][q.front().second - 1] = g_dist[q.front().first][q.front().second] + 1;
            visited[q.front().first][q.front().second - 1] = true;
            q.push({q.front().first, q.front().second - 1});
        }
        q.pop();
    }
}

void dfs_dist(int i, int j, int pasos, vector<string>& g, vvi& g_dist, vector<vbool>& visited){
    if(visited[i][j]) return; // aca return false si estoy buscando ciclos
    if(g[i][j] != 'T'){
        g_dist[i][j] = pasos;
        return;
    }
    visited[i][j] = true;
    pasos++;
    if((i+1) < g.size() && g[i+1][j] != 'T') dfs_dist((i+1), (j), pasos, g, g_dist, visited);
    if((i-1) >= 0 && g[i-1][j] != 'T') dfs_dist((i-1), (j), pasos, g, g_dist, visited);
    if((j+1) < g[i].size() && g[i][j+1] != 'T') dfs_dist((i), (j+1), pasos, g, g_dist, visited);
    if((j-1) >= 0 && g[i][j-1] != 'T') dfs_dist((i), (j-1), pasos, g, g_dist, visited);
}

void dfs_caminos(int i, int j, int pasos, int& menor_pasos, vector<string>& g, vector<vbool>& visited, vvi& g_dist){
    if(visited[i][j]) return; // aca return false si estoy buscando ciclos
    if(g[i][j] == 'E'){
        if(pasos < menor_pasos) menor_pasos = pasos;
        return;
    }
    visited[i][j] = true;
    if((i+1) < g.size() && g[i+1][j] != 'T' && g_dist[i+1][j] < g_dist[i][j]) dfs_caminos((i+1), (j), (pasos+1), menor_pasos, g, visited, g_dist);
    if((i-1) >= 0 && g[i-1][j] != 'T' && g_dist[i-1][j] < g_dist[i][j]) dfs_caminos((i-1), (j), (pasos+1), menor_pasos, g, visited, g_dist);
    if((j+1) < g[i].size() && g[i][j+1] != 'T' && g_dist[i][j+1] < g_dist[i][j]) dfs_caminos((i), (j+1), (pasos+1), menor_pasos, g, visited, g_dist);
    if((j-1) >= 0 && g[i][j-1] != 'T' && g_dist[i][j-1] < g_dist[i][j]) dfs_caminos((i), (j-1), (pasos+1), menor_pasos, g, visited, g_dist);
}

pi pos_start(vector<string>& g){
    pi res;
    F0(i,g.size()){
        F0(j,g[i].size()){
            if(g[i][j] == 'S') res = {i,j};
        }
    }
    return res;
}

pi pos_end(vector<string>& g){
    pi res;
    F0(i,g.size()){
        F0(j,g[i].size()){
            if(g[i][j] == 'E') res = {i,j};
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
    if((i+1) < g.size() && g[i+1][j] != 'T') res = res || llega_en_n_pasos((i+1), (j), n, meta, g, visited);
    if((i-1) >= 0 && g[i-1][j] != 'T') res = res || llega_en_n_pasos((i-1), (j), n, meta, g, visited);
    if((j+1) < g[i].size() && g[i][j+1] != 'T') res = res || llega_en_n_pasos((i), (j+1), n, meta, g, visited);
    if((j-1) >= 0 && g[i][j-1] != 'T') res = res || llega_en_n_pasos((i), (j-1), n, meta, g, visited);
    return res;
}

int min_peleas(vi& v){
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
    pi pos_e = pos_end(g);
    vector<vbool> visited(r, vbool(c));
    vector<pi> camino;
    vector<pi> breeders;
    int menor_peleas = 0;
    int menor_pasos = r*c + 1;
    vvi g_dist(r, vi(c, (-1)));

    F0(i,g.size()){
        F0(j,g[i].size()){
            if( g[i][j] == '1' || g[i][j] == '2' || g[i][j] == '3' || g[i][j] == '4' || g[i][j] == '5' || g[i][j] == '6' || g[i][j] == '7' || g[i][j] == '8' || g[i][j] == '9') breeders.pb({i,j});
        }
    }

    vector<vbool> visited2(r, vbool(c));
    bfs_dist(pos_e,g,g_dist,visited2);
   
    dfs_caminos(pos_s.first,pos_s.second,0,menor_pasos,g,visited,g_dist);
    
    F0(i,g.size()){
        F0(j,g[i].size()){
            if(g[i][j] != 'T' && g[i][j] != 'S' && g[i][j] != 'E' && g[i][j] != '0' && g_dist[i][j] != (-1) && g_dist[i][j] <= menor_pasos){
                menor_peleas += g[i][j] - '0';
            }
        }
    }
    

    /* SE VA DE COMPLEJIDAD (CREO)
    F0(k,breeders.size()){
        vector<vbool> visited2(r, vbool(c));
        if(llega_en_n_pasos(breeders[k].first, breeders[k].second, menor_pasos, pos_e, g, visited2)){
            menor_peleas += g[breeders[k].first][breeders[k].second] - '0';
        } 
    }
    */
    

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
    F0(i, visited2.size()){
        F0(j, visited2[i].size()){
            cout << visited2[i][j] << " ";
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
    

    /*FUNCIONA
    F0(i, breeders.size()){
        cout << breeders[i].first << " " << breeders[i].second << ", ";
    }

    cout << "\n";

    F0(i,peleas_por_camino.size()){
        cout << peleas_por_camino[i] << ", ";
    }
    */

    /* FUNCIONA
    F0(i,g_dist.size()){
        F0(j,g_dist[i].size()){
            cout << g_dist[i][j] << " ";
        }
        cout << "\n";
    }
    */
    
    cout << menor_peleas;
    
    return 0;
}
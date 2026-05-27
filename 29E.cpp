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

void dfs(int b, int a, int pasos,)

int main() {
    int n, m;
    cin >> n >> m;
    vvi g(n);
    int mtemp = m;
    while(m--){
        int i, f;
        cin >> i >> f;
        g[i].pb(f);
    }

    dfs()
    
    return 0;
}
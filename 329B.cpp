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


void dfs(int i, int j, vector<string>& g, vector<vbool>& visited, vector<pi>& camino){
    if(visited[s]) return; // aca return false si estoy buscando ciclos
    vistied[s] = true;
    if(c){
        painted[s] = true;
    }
    c = !c;
    for(int i = 0; i < g[s].size(); i++){
        dfs(g[s][i], g, visited, painted);
    }
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
    //caminos(...)
    
    return 0;
}
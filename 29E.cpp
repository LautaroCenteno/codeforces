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

vvi estados;

int bfs(int n, vvi& g, unordered_set& visited){
    int pasos = 0;
    queue<vvi> q1;
    vvi estado = {{0,n-1,0},{1},{n}}; //{{posB,posA,paso},{caminoB},{caminoA}}
    visited.insert(estado);
    q.push(estado);
    while(!q.empty){
        vvi actual = q.front();
        q.pop();
        if(actual[0][2] == 0){
            for(int i = 0; i < g[actual[0][0]].size; i++){
                
            }
        }
        else{
            for(int i = 0; i < g[actual[0][1]].size; i++){
                
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vvi g(n);
    int mtemp = m;
    F0(i,m)
        int a1, a2;
        cin >> a1 >> a2;
        g[a1].pb(a2);
        g[a2].pb(a1);
    }

    vbool visited1(n);
    vbool visited2(n);

    int k = bfs(n, g, visited1, visited2);

    cout << k << "\n";
    for(int i = 0; i < estados.size(); i += 2){
        cout << estados;
    }
    for(int i = 0; i < estados.size(); i += 2){
        
    }

    return 0;
}
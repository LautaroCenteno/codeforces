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

void bfs(int n, vvi& g, set<pi>& visited){
    int pasos = 0;
    queue<vvi> q;
    vvi estado = {{0,n-1,0},{0},{n-1}};
    visited.insert({estado[0][0],estado[0][1]});
    q.push(estado);
    vvi actual = q.front();
    int b = actual[0][0];
    int a = actual[0][1];
    int t = actual[0][2];
    vi cb = actual[1];
    vi ca = actual[2];

    while(!q.empty()){
        actual = q.front();
        b = actual[0][0];
        a = actual[0][1];
        t = actual[0][2];
        cb = actual[1];
        ca = actual[2];
        q.pop();

        if(b == n-1 && a == 0 && cb.size() == ca.size()){
            cout << actual[1].size()-1 << "\n";
            F0(i,actual[1].size()){
                cout << actual[1][i] + 1 << " ";
            }
            cout << "\n";
            F0(i,actual[2].size()){
                cout << actual[2][i] + 1 << " ";
            }
            cout << "\n";
            return;
        }
        
        if(t == 0){
            for(int i = 0; i < g[b].size(); i++){
                if(visited.count({g[b][i],a}) == 1) continue;
                visited.insert({g[b][i],a});
                cb.pb(g[b][i]);
                q.push({{g[b][i],a,1},cb,ca});
            }
        }
        if(t == 1){
            for(int i = 0; i < g[a].size(); i++){
                if(visited.count({b,g[a][i]}) == 1 || g[a][i] == b) continue;
                visited.insert({b,g[a][i]});
                ca.pb(g[a][i]);
                q.push({{b,g[a][i],0},cb,ca});
            }
        }
    }
    cout << -1 << "\n";
}

int main() {
    int n, m;
    cin >> n >> m;
    vvi g;
    F0(i,n){
        g.pb({});
    }
    F0(i,m){
        int a1, a2;
        cin >> a1 >> a2;
        g[a1-1].pb(a2-1);
        g[a2-1].pb(a1-1);
    }

    set<pi> visited;

    bfs(n, g, visited);

    /*
    F0(i,g.size()){
        F0(j, g[i].size()){
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
    */
    
    
    return 0;
}
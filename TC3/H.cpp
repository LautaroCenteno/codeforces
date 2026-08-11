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

bool visited[200000] = {false};
int caminos[200000];
vi camino = {};
vector<string> abc = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m","n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

void bfs(int n, vector<vector<pair<int,string>>>& g){
    queue<int> q;
    q.push(0);
    int actual = q.front();
    visited[actual] = true;

    while(!q.empty()){
        //cout << "ENTRA en while" << "\n";
        actual = q.front();
        q.pop();
        //cout << "q.pop" << "\n";

        if(actual == n-1){
            //cout << "ENTRA al if RETURN" << "\n";
            int p = actual;
            //cout << "v = " << v[0] << " " << v[1] << " " << v[2] << "\n";
            camino.pb(p+1);

            while(p != 0){
                //cout << "ENTRA al while" << "\n";
                p=caminos[p];
                //cout << "v = " << v[0] << " " << v[1] << " " << v[2] << "\n";
                camino.pb(p+1);
            }
            reverse(camino.begin(), camino.end());
            
            return;
        }
        for(int i = 0; i < g[actual].size(); i++){
            //cout << "g[b][i] = " << g[b][i] << "\n";
            if(visited[g[actual][i].F]) continue;
            //cout << "Estado NO visitado" << "\n";
            visited[g[actual][i].F] = true;
            caminos[g[actual][i].F] = actual;
            q.push(g[actual][i].F);
        }
        
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,string>>> g;
    F0(i,n){
        g.pb({});
    }
    F0(i,m){
        int a1, a2;
        string s;
        cin >> a1 >> a2 >> s;
        g[a1-1].pb({a2-1,s});
        g[a2-1].pb({a1-1,s});
    }

    bfs(n, g);

    /*
    F0(i,g.size()){
        F0(j, g[i].size()){
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
    */

    cout << camino.size()-1 << "\n";
    F0(i,camino.size()) cout << camino[i] << " ";
    cout << "\n";
    
    string res = "";
    F1(i,camino.size()-1){
        string s;
        F0(j,g[camino[i-1]-1].size()){
            if(g[camino[i-1]-1][j].F == camino[i]-1) res+=g[camino[i-1]-1][j].S;
        }
    }
    cout << res << "\n";
    
    
    return 0;
}
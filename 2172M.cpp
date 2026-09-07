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

void bfs(int n, vvi& g, set<vi>& visited){
    int pasos = 0;
    queue<vvi> q;
    vvi estado = {{0,n-1,0},{0},{n-1}};
    visited.insert(estado[0]);
    q.push(estado);
    vvi actual = q.front();
    int b = actual[0][0];
    int a = actual[0][1];
    int t = actual[0][2];
    vi cb = actual[1];
    vi ca = actual[2];

    while(!q.empty()){
        //cout << "ENTRA en while" << "\n";
        actual = q.front();
        b = actual[0][0];
        //cout << "b = " << b << "\n";
        a = actual[0][1];
        //cout << "a = " << a << "\n";
        t = actual[0][2];
        //cout << "t = " << t << "\n";
        cb = actual[1];
        //F0(i,cb.size()) cout << "cb = " << cb[i] << " ";
        //cout << "\n";
        ca = actual[2];
        //F0(i,ca.size()) cout << "ca = " << ca[i] << " ";
        //cout << "\n";
        q.pop();
        //cout << "q.pop" << "\n";

        if(b == n-1 && a == 0 && t == 0){
            //cout << "ENTRA al if RETURN" << "\n";
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
            //cout << "ENTRA al if (t==0)" << "\n";
            for(int i = 0; i < g[b].size(); i++){
                //cout << "g[b][i] = " << g[b][i] << "\n";
                if(visited.count({g[b][i],a,1}) == 1) continue;
                //cout << "Estado NO visitado" << "\n";
                visited.insert({g[b][i],a,1});
                vi cb_copy = cb;
                cb_copy.pb(g[b][i]);
                q.push({{g[b][i],a,1},cb_copy,ca});
            }
        }
        if(t == 1){
            //cout << "ENTRA al if (t==1)" << "\n";
            for(int i = 0; i < g[a].size(); i++){
                //cout << "g[a][i] = " << g[a][i] << "\n";
                if(visited.count({b,g[a][i],0}) == 1 || g[a][i] == b) continue;
                //cout << "Estado NO visitado" << "\n";
                visited.insert({b,g[a][i],0});
                vi ca_copy = ca;
                ca_copy.pb(g[a][i]);
                q.push({{b,g[a][i],0},cb,ca_copy});
            }
        }
    }
    //cout << "SALE del while" << "\n";
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

    set<vi> visited;

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
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

bool visited[500][500][2] = {false};
vi caminos[500][500][2];

void bfs(int n, vvi& g){
    int pasos = 0;
    queue<vi> q;
    vi estado = {0,n-1,0};
    q.push(estado);
    vi actual = q.front();
    int b = actual[0];
    int a = actual[1];
    int t = actual[2];
    visited[b][a][t] = true;

    while(!q.empty()){
        //cout << "ENTRA en while" << "\n";
        actual = q.front();
        b = actual[0];
        //cout << "b = " << b << "\n";
        a = actual[1];
        //cout << "a = " << a << "\n";
        t = actual[2];
        //cout << "t = " << t << "\n";
        //cout << "\n";
        q.pop();
        //cout << "q.pop" << "\n";

        if(b == n-1 && a == 0 && t == 0){
            //cout << "ENTRA al if RETURN" << "\n";
            vi v = {b,a,t};
            //cout << "v = " << v[0] << " " << v[1] << " " << v[2] << "\n";
            vi cb = {};
            vi ca= {a+1};
            while(v != estado){
                //cout << "ENTRA al while" << "\n";
                v=caminos[v[0]][v[1]][v[2]];
                //cout << "v = " << v[0] << " " << v[1] << " " << v[2] << "\n";
                if(v[2] == 1) cb.pb(v[0]+1);
                if(v[2] == 0) ca.pb(v[1]+1);
            }
            cb.pb(v[0]+1);
            reverse(cb.begin(), cb.end());
            reverse(ca.begin(), ca.end());
            cout << cb.size()-1 << "\n";
            F0(i,cb.size()) cout << cb[i] << " ";
            cout << "\n";
            F0(i,ca.size()) cout << ca[i] << " ";
            cout << "\n";
            return;
        }
        
        if(t == 0){
            //cout << "ENTRA al if (t==0)" << "\n";
            for(int i = 0; i < g[b].size(); i++){
                //cout << "g[b][i] = " << g[b][i] << "\n";
                if(visited[g[b][i]][a][1]) continue;
                //cout << "Estado NO visitado" << "\n";
                visited[g[b][i]][a][1] = true;
                caminos[g[b][i]][a][1] = {b,a,t};
                q.push({g[b][i],a,1});
            }
        }
        if(t == 1){
            //cout << "ENTRA al if (t==1)" << "\n";
            for(int i = 0; i < g[a].size(); i++){
                //cout << "g[a][i] = " << g[a][i] << "\n";
                if(visited[b][g[a][i]][0] || g[a][i] == b) continue;
                //cout << "Estado NO visitado" << "\n";
                visited[b][g[a][i]][0] = true;
                caminos[b][g[a][i]][0] = {b,a,t};
                q.push({b,g[a][i],0});
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

    bool visited[500][500][2] = {false};

    bfs(n, g);

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
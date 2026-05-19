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


void dfs(int i, int j, vvi& g, vector<vbool>& visited, vector<pi>& camino, bool c){
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

int cant_true(vbool v){
    int res = 0;
    for(bool b:v){
        if(b){
            res++;
        }
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    int temp = t;
    while(temp--) {
        int n, m;
        cin >> n >> m;
        int mtemp = m;
        vvi g(n);
        //vpi rank(n);
        vbool visited1(n);
        vbool painted1(n);
        vbool visited2(n);
        vbool painted2(n);
        /*
        F0(i,n){
            rank[i] = {0,i+1};
        }
        */
        while(mtemp--){
            int x, y;
            cin >> x >> y;
            g[x-1].pb(y);
            g[y-1].pb(x);
            //rank[x-1].first++;
            //rank[y-1].first++;
        }

        /*
        sort(rank.begin(),rank.end());
        reverse(rank.begin(),rank.end());
        */

        /*
        F0(i,n){
            cout << rank[i].first << " " << rank[i].second << "\n";
        }
        */

        dfs_paint(0,g,visited1,painted1,true);
        dfs_paint(0,g,visited1,painted1,false);

        if(cant_true(painted1) < cant_true(painted2)){
            cout << cant_true(painted1) << "\n";
            for(i = 0; i < painted1.size(); i++){
                if(painted1[i]){
                    cout << (i+1) << " ";
                } 
            }
        }
        
    }
    return 0;
}
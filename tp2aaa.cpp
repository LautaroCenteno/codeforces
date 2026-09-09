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

unordered_map<int,int> bfs(int a, vvi& g, vbool visited){
    unordered_map<int,int> res;
    queue<int> q;
    queue<int> q2;
    q.push(a);
    q2.push(1);
    
    while(!q.empty()){
        int num = q2.front();
        int actual = q.front();
        res[actual] = num;
        //cout << actual << "\n";
        //cout << num << "\n";
        visited[actual] = true;
        F0(i,g[actual].size()){
            //cout << g[actual][i] << "\n";
            if(!visited[g[actual][i]]){
                q.push(g[actual][i]);
                q2.push(num+1);
            }
        }
        q.pop();
        q2.pop();
    }
    //cout << "fin" << "\n";
    return res;
}

int main() {
    int n; cin >> n;
    vvi g(n);
    vi camino(n);
    F0(i,n-1){
        int x; int y; cin >> x >> y;
        g[x-1].pb(y-1);
        g[y-1].pb(x-1);
    }
    F0(i,n){
        int a; cin >> a;
        camino[i] = a-1;
    }
    vbool visited(n);
    bool res = true;

    unordered_map<int,int> map = bfs(0, g, visited);

    if(camino[0] == 0) res = res && true;

    F1(i,n-1){
        if(map[camino[i]] >= map[camino[i-1]]) res = res && true;
        else res = res && false;
    }

    if(res) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    
    return 0;
}
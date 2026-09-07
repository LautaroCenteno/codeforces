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

int bfs(int a, vvi& g, vbool visited){
    queue<int> q;
    queue<int> q2;
    q.push(a);
    q2.push(1);
    
    int res = 0;
    while(!q.empty()){
        int num = q2.front();
        if(num > res) res = num;
        int actual = q.front();
        visited[actual] = true;
        F0(i,g[actual].size()){
            if(!visited[g[actual][i]]){
                q.push(g[actual][i]);
                q2.push(num+1);
            }
        }
        q.pop();
        q2.pop();
    }
    return res;
}

int main() {
    int n; cin >> n;
    vvi g(n);
    F0(i,n){
        int p; cin >> p;
        if(p != -1){
            g[p-1].pb(i);
        }
    }
    vbool visited(n);
    int res = 0;
    F0(i,n){
        if(!visited[i]){
            int j = bfs(0, g, visited);
            if (j > res) res = j;
        }
    }
    cout << res << "\n";
    
    return 0;
}
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

int main() {
    int n; cin >> n;
    bool val = true;
    vector<string> v; 
    F0(i,n){
        string stemp; cin >> stemp;
        v.pb(stemp);
    } 
    vvi g(26);
    vi din(26);
    F0(i,n-1){
        int k = min(v[i].size(),v[i+1].size());
        bool b = false;
        F0(j,k){
            if(v[i][j] != v[i+1][j]){
                b = true;
                g[v[i][j] - 'a'].pb(v[i+1][j] - 'a');
                din[v[i+1][j] - 'a']++;
                break;
            }
        }
        if(v[i].size() > v[i+1].size() && !b) val = false;
    }
    if(!val){cout << "Impossible\n"; return 0;}
    queue<int> q;
    F0(i,26){
        if(din[i] == 0) q.push(i);
    }
    string res = "";
    while(!q.empty()){
        int u = q.front();
        q.pop();
        res.pb(u + 'a');
        F0(i,g[u].size()){
            din[g[u][i]]--;
            if(din[g[u][i]] == 0) q.push(g[u][i]);
        }
    }
    if(res.size() < 26){cout << "Impossible\n"; return 0;}
    cout << res << "\n";

    return 0;
}
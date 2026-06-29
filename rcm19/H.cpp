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
    int n;
    cin >> n;
    vvi g1(n);
    vvi g2(n);
    F0(i,n){
        int u, d, t, c;
        cin >> u >> d >> t >> c;
        g1[i].pb(u);
        g1[i].pb(d);
        g1[i].pb(t);
        g1[i].pb(c);
    }
    F0(i,n){
        int u, d, t, c;
        cin >> u >> d >> t >> c;
        g2[i].pb(u);
        g2[i].pb(d);
        g2[i].pb(t);
        g2[i].pb(c);
    }
    /*
    F0(i,n){
        cout << g1[i][0] << g1[i][1] << g1[i][2] << g1[i][3] << "\n";
    }
    */


    return 0;
}
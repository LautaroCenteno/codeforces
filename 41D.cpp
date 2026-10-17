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

int n,m,k;
int mINF = -1e9;

void f(int x, int y, int r, vector<string>& g){
    if(x = 0){
        if
    }


    if(y == m-1) res = f(x-1,y-1)
}

int main() {
    cin >> n >> m >> k;
    vector<string> g(n);
    for(int i = n-1; i > -1; i--) cin >> g[i];
    vector<vvi> dp(n, vvi(m, vi(k)));
    int maximo = mINF;
    F0(i,m) maximo = max(maximo, f(n-1,i,0));
    cout << maximo << "\n";
    return 0;
}
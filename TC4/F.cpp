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
    int t;cin>>t;
    while(t--){
        int r,g,b;cin>>r>>g>>b;
        int minimo = min(r, min(g, b));
        int maximo = max(r, max(g, b));
        int mid = r+g+b-minimo-maximo;
        int res = minimo;
        if(maximo - mid <= minimo){
            minimo -= (maximo-mid);
            maximo -= (maximo-mid);
        } else{
            minimo = 0;
            maximo -= minimo;
        }
        if(minimo > 0){
            maximo -= (minimo+1)/2;
            res += maximo;
            cout << res << "\n";
        } else{
            cout << res + mid << "\n";
        }
    }
    return 0;
}
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
    int n; cin>> n;
    vector<string> g(n);

    int res = (n*n+1)/2;
    F0(i,n){
        F0(j,n){
            if(i%2==0 && j%2==0)g[i] += 'C';
            else if(i%2==1 && j%2==1)g[i] +='C';   
            else g[i] +='.';                 
        }
    }
    cout << res << "\n";
    F0(i,n){
            cout << g[i] << "\n";
    }
    return 0;
}
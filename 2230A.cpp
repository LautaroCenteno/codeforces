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
    int t;
    cin >> t;
    while(t--){
        ll res = 0;
        int n, a, b;
        cin >> n >> a >> b;

        if(b/3 < a && n >= 3){
            res += (ll) b * (ll) (n/3);
            n = n%3;
        }
        if(b/2 < a && n >= 2){
                res += (ll) b * (ll) (n/2);
                n = n%2;
        }
        if(b < a && n >= 1){
            res += (ll) b * (ll) n;
            n = n%1;
        }
        if(a <= b && n >= 1){
                res += (ll) a * (ll) n;
                n = n%1;
        }
        cout << res << "\n";
    }
    
    return 0;
}
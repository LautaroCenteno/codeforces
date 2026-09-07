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

int main(){
    ll n; cin >> n;
    ll res = 0;
    vpll pregs;

    for(int i = 1; i <= n/2; i++ ){
        if (n%i == 0) {
            res++;
            if (i == 1) pregs.pb(mp(1,n));
            else pregs.pb(mp(1,i));
        }
    }
    if (pregs.size() > 1) {
        res--;
        F0(i,pregs.size()){
        cout << pregs[i].F << " " << pregs[i].S << "\n";

    }
    
    }
    cout << res << "\n";
    F0(i,pregs.size()){
        cout << pregs[i].F << " " << pregs[i].S << "\n";

    }

    return 0;
}
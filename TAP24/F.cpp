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
    vi v(n); F0(i,n) cin >> v[i];
    int res = 0;
    if(n > 2){
        if(v[0] == 1){
            res++;
        } else{
            res--;
        }
        if(v[1] == 1){
            res++;
        } else{
            res--;
        }
        for(int i = 2; i < n; i++){
            if(v[i-2] == 1 && v[i-1] == 1 && v[i] == 1){
                res++;
            }
            if(v[i] == 1){
                res++;
            } else{
                res--;
            }
            
        }
    } else{
        F0(i,n){
            if(v[i] == 1) res++;
            else res--;
        }
    }

    cout << res;

    return 0;
}
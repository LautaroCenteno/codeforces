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
    int m; cin >> m;
    vpi hash(m+1, {-1,-1});
    int cant = 0;
    vi v(n); 
    F0(i,n){
        cin >> v[i]; 
        if(hash[v[i]] == mp(-1,-1)) hash[v[i]] = mp(i,i);
        if (i > hash[v[i]].S) hash[v[i]].S = i;
    } 
    vi orden;
    F0(i,m+1) if(hash[i] != mp(-1,-1)){cant++;orden.pb(i)}
    if(n < 3){
        cout << 1 << "\n";
        return 0;
    }
    int res = 1;
    int ord;
    for(int i = 1; i < n; i++){
        if(hash[orden[i]].S < hash[orden[i-1]].F && hash[orden[i]].F <= hash[orden[i-1]].S){
            ord = 1;
        }
        if(hash[orden[i]].S < hash[orden[i-1]].F && hash[orden[i]].F <= hash[orden[i-1]].S){
            ord = 0;
        }

    }
    for(int i = 2; i < n; i++){
        if(ord == 0){
            if(hash[orden[i]].S < hash[orden[i-1]].F){
                res++;
                ord = 1;
            }
        } else{
            if(hash[orden[i]].F > hash[orden[i-1]].S){
                res++;
                ord = 0;
            }
        }
    }
    cout << cant << " " << res << "\n";
    return 0;
}
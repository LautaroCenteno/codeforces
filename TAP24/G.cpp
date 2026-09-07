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
    string s; cin >> s;
    int t = 0; 
    int p = 0;
    int a = 0; 
    int u = 0;
    int res = 0;
    F0(i, s.size()){
        if(s[i] == 'T') t++;
        if(s[i] == 'U') u++;
        if(s[i] == 'P') p++;
        if(s[i] == 'A') a++;
    }
    int base = min(t,p);
    /*
    if(a > u){
        if(a >= base){
            res += base;
            base = 0;
            cout << res;
            return 0;
        } else(
            res += base;
            base = 0;
            cout << res;
            return 0;
        )
    }else{
    }    
    */
    
    cout << min(base, a + u);

    return 0;
}
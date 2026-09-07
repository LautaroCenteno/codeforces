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
    int n, m; cin >> n >> m;
    vector<string> v(n);
    F0(i,n) cin >> v[i];
    int res = 0;
    F0(a,n*m){
        F0(b,n*m){
            F0(c,n*m){
                if(a != b && b!=c && a!=c){
                    if(v[a%n][a%m] != '1' && v[b%n][b%m] != '1' && v[c%n][c%m] != '1'){
                        pi pa = {a%m, a%n};
                        pi pb = {b%m, b%n};
                        pi pc = {c%m, c%n};
                        int dxab = abs(pb.F - pa.F);
                        int dyab = abs(pb.S - pa.S);
                        int dxac = abs(pc.F - pa.F);
                        int dyac = abs(pc.S - pa.S);
                        int dxbc = abs(pc.F - pb.F);
                        int dybc = abs(pc.S - pb.S);
                        bool b1 = (dxab == dyab || (dxab == 0 && dyab != 0) || (dxab != 0 && dyab == 0));
                        bool b2 = (dxac == dyac || (dxac == 0 && dyac != 0) || (dxac != 0 && dyac == 0));
                        bool b3 = (dxbc == dybc || (dxbc == 0 && dybc != 0) || (dxbc != 0 && dybc == 0));
                        if(b1 && b2 && b3) res++;
                    }
                }
            }
        }
    }
    cout << res;
    
    return 0;
}
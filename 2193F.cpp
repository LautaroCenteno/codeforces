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
        int n,ax,ay,bx,by;
        cin >> n >> ax >> ay >> bx >> by;
        vpi v(n, {0,0});
        F0(i,n){
            int x;
            cin >> x;
            v[i].F = x;
        }
        F0(i,n){
            int y;
            cin >> y;
            v[i].S = y;
        }
        sort(v.begin(),v.end());
        //F0(i,n){cout << v[i].F << " " << v[i].S << "\n";}
        vector<vpi> g;
        pi prev = v[0];
        g.pb({prev});
        int num = 0;

        F1(i,n-1){
            if(v[i].F == prev.F){
                g[num].pb(v[i]);
                prev = v[i];
            } else{
                g.pb({v[i]});
                prev = v[i];
                num++;
            }
        }
        vvi dp(g.size() {0,0})
        /*
        F0(i,g.size()){
            F0(j,g[i].size())
            cout << v[i].F << " " << v[i].S << "\n";
        }
        */
        
    }
    return 0;
}
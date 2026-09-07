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
    int t; cin >> t;
    while(t--){
        vvi v; 
        vi g1 = {0,0};
        vi g2 = {0,0};
        int n; cin >> n;
        vi res(n);
        F0(i,n){
            int l,r; cin >> l >> r;
            v.pb({l,r,i});
        }
        sort(v.begin(),v.end());
        /*
        F0(i,v.size()){
            cout << v[i].F << v[i].S << " ";
        } 
        */
        //cout << "\n";
        g1={v[0][0],v[0][1]};
        res[v[0][2]] = 1;
        F1(i,n-1){
            //cout << "for: " << i << "\n";
            //cout << g1[0] << " " << g1[1] << "\n";
            //cout << g2[0] << " " << g2[1] << "\n";
            //cout << v[i][0] << " " << v[i][1] << v[i][2] << "\n";
            if(v[i][0] >= g1[0] && v[i][0] <= g1[1]){
                //cout << "entra a if" << "\n";
                res[v[i][2]] = 1;
                if(v[i][1] >= g1[1]) g1[1] = v[i][1];
            } else if(g2[0] == 0 && g2[1] == 0) {
                g2 = {v[i][0],v[i][1]};
                res[v[i][2]] = 2;
                //cout << "entra a 0" << "\n";
            }
            else{
                //cout << "entra a else" << "\n";
                if(v[i][0] >= g2[0] && v[i][0] <= g2[1]) {
                    res[v[i][2]] = 2;
                    if(v[i][1] >= g2[1]) g2[1] = v[i][1];
                } else{
                    res[v[i][2]] = 1;
                    g1={v[0][0],v[0][1]};
                    g2 = {0,0};
                }
            }
        }
        bool b = false;
        F0(i,n){
            if(res[i] == 2) b = true;
        }
        if(b){
            F0(i,n){
                cout << res[i] << " ";
            }
            cout << "\n";
        } else cout << -1 << "\n";
    }

    return 0;
}
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
        cout << "t: " << t << "\n";
        int n;
        cin >> n;
        vbool p(n);
        int cant;
        int hija;
        bool optimo = true;
        F0(i,n){
            cout << "n: " << i << "\n";
            int k;
            bool valor = false;
            cin >> k;
            while(k--){
                cout << "k: " << k << "\n";
                int g; cin >> g;
                if(!p[g] && !valor){
                    cant++;
                    valor = true;
                }
            }
            if(!valor){
                hija = i+1;
                optimo = false;
            }
        }
        if(!optimo){
            cout << "IMPROVE" << "\n";
            F0(i, p.size()){
                if(!p[i]){
                    cout << hija << " " << i+1 << "\n";
                    break;
                } 
            }
        } else{
            cout << "OPTIMAL" << "\n";
        }
    }
    return 0;
}
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

bool check(vi& v, int i, int j, int n){
    if (j >= n) return false;
    F0
}

int main() {
    int t;
    cin >> t;
    vi v;
    F0(i,t){
        int n;
        cin >> n;
        bool par = false;
        bool res = false;
        F0(i,n){
            int a;
            cin >> a;
            v.pb(c);
        }
        for(int j = n-1; j>1; j--){
            if(v[j-1] == 1 || v[j-1] == 2){
                int l = 0;
                int r = j-1;
                if(check(v,r,j,n)){
                    cout << "YES" << "\n";
                    break;
                }
                

            }
        }
    }

    return 0;
}
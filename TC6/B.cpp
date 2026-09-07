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
    int t; cin>>t;
    while(t--){
        int n; cin >> n;
        vi a(n);
        vi b(n);
        ll res = 0;
        F0(i,n) cin >> a[i];
        F0(i,n) cin >> b[i];
        int pa = a[0];
        int pb = b[0];
        //cout << pa << " " << pb << "\n";
        F0(i,n){
            if(a[i] < pa) pa = a[i];
            if(b[i] < pb) pb = b[i];
        }
        F0(i,n) res += (ll) max(a[i] - pa, b[i] - pb);
        cout << res << "\n";
    }
    
    return 0;
}
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
    F0(i,t){
        ll a,b,c,m;
        cin >> a >> b >> c >> m;
        ll mcm = lcm(lcm(a,b),c);
        ll a_b_c = m/mcm;
        ll a_b = m/lcm(a,b) - a_b_c;
        ll a_c = m/lcm(a,c) - a_b_c;
        ll b_c = m/lcm(b,c) - a_b_c;
        ll n_a = m/a - a_b - a_c - a_b_c;
        ll n_b = m/b - a_b - b_c - a_b_c;
        ll n_c = m/c - a_c - b_c - a_b_c;
        ll res_a = a_b_c*2 + a_b*3 + a_c*3 + n_a*6;
        ll res_b = a_b_c*2 + a_b*3 + b_c*3 + n_b*6;
        ll res_c = a_b_c*2 + a_c*3 + b_c*3 + n_c*6;
        cout << res_a << " " << res_b << " " << res_c << "\n";
    }
}
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
        vi v(3);
        F0(i,3) cin >> v[i];
        
        sort(v.begin(), v.end());

        int res = v[2] - v[0];
        
        vi v1 = {v[1] + v[2], v[1], v[2]};
        vi v2 = {v[0], v[1], v[0] + v[1]};

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        int res1 = v1[2] - v1[0];
        int res2 = v2[2] - v2[0];

        cout << min(res, min(res1, res2)) << "\n";
    }

    return 0;
}
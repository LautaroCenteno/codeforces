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
        int n; cin >> n;
        vi a(n);
        F0(i,n) cin >> a[i];

        vi dp(n); dp[n-1] = 1;

        for(int i = n-2; i >= 0; i--){
            if(i + a[i] < n){
                if(i + a[i] + 1 < n){
                    dp[i] = min (dp[i+1] + 1, dp[i + a[i] + 1]);
                } else{
                    dp[i] = 0;
                }
            } else{
                dp[i] = dp[i+1] + 1;
            }
        }

        cout << dp[0] << "\n";
    }
}
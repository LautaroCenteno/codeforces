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
    int n;cin >> n;
    vll v(n);
    vll cant(100005);;
    ll maxV = 0;
    F0(i,n){
        cin >> v[i];
        cant[v[i]]++;
        if(v[i] > maxV) maxV = v[i];
    }
    vll dp(maxV+1);
    dp[0] = 0;
    dp[1] = cant[1];
    for(ll i = 2; i <= maxV; i++){
        dp[i] = max(cant[i]*i + dp[i-2], dp[i-1]);
    }
    cout << dp[maxV];

    return 0;
}
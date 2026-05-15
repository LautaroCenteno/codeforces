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

void buildPrefixSum (const vll& a, vll& prefixSum, int n){
    prefixSum[0] = a[0];
    for(int i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }
}

ll casoSum0(ll n){
    ll res = 0;
    for(int i = 1; i <= n-2; i++){
        res += i;
    }
    return res;
}

int main() {
    int n;
    vll a;
    ll cant = 0;
    cin >> n;
    int ntemp = n;
    vll prefixSum(n);
    while (ntemp--){
        ll x;
        cin >> x;
        a.push_back(x);
    }
    buildPrefixSum(a, prefixSum, n);
    int s1 = 0;
    if(prefixSum[n-1] == 0) {
        for(int x:prefixSum) {
            if(x == 0){
                s1++;
            }
        }
        cout << casoSum0((ll) s1);

    }
    else if(prefixSum[n-1]%3 == 0){
        for(int i = 1; i < n; i++) {
            if(prefixSum[i-1] == prefixSum[n-1]/3){
                s1++;
            } else if(prefixSum[i-1] == (prefixSum[n-1]/3)*2){
                cant += (ll) s1;
            }
        }
        cout << cant;
    } else {
        cout << 0;
    }
    
    /*
    for (int x : prefixSum) {
        cout << x << " ";
    }
    */
    return 0;
}
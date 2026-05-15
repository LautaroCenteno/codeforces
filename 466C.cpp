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

void buildPrefixSum (const vi& a, vi& prefixSum, int n){
    prefixSum[0] = a[0];
    for(int i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }
}

int main() {
    int n;
    vi a;
    int cant = 0;
    cin >> n;
    int ntemp = n;
    vi prefixSum(n);
    while (ntemp--){
        int x;
        cin >> x;
        a.push_back(x);
    }
    buildPrefixSum(a, prefixSum, n);
    for(int i = 1; i < n - 1; i++) {
        for(int j = i + 1; j <= n - 1; j++){
            int sum1 = prefixSum[i-1];
            int sum2 = prefixSum[j-1] - prefixSum[i-1];
            int sum3 = prefixSum[n-1] - prefixSum[j-1];
            if((sum1 == sum2) && (sum2 == sum3)) cant++;
            else continue;
        }
    }
    /*
    for (int x : prefixSum) {
        cout << x << " ";
    }
    */
    cout << cant;
    return 0;
}
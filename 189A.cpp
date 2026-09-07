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
    int n,a,b,c; cin >> n >> a >> b >> c;
    
    vi dp(n+5);

    F0(i,n+1){
        //cout << "i: " << i << "\n";
        if(i-a == 0 || (i-a >= 0 && dp[i-a] != 0)){
            
            if(dp[i] < dp[i-a]+1){
                //cout << "se puede con a: " << dp[i-a]+1 << "\n";
                dp[i] = dp[i-a]+1;
            }
        }
        if(i-b == 0 || (i-b >= 0 && dp[i-b] != 0)){
            
            if(dp[i] < dp[i-b]+1){
                //cout << "se puede con b: " << dp[i-b]+1 << "\n";
                dp[i] = dp[i-b]+1;
            }
        }
        if(i-c == 0 || (i-c >= 0 && dp[i-c] != 0)){
            
            if(dp[i] < dp[i-c]+1){
                //cout << "se puede con c: " << dp[i-c]+1 << "\n";
                dp[i] = dp[i-c]+1;
            }
        }
    }
    //F0(i,n) cout << dp[i] << " ";
    //cout << "\n";

    cout << dp[n];

    return 0;
}
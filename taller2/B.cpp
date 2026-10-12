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
    const ll INF = 1e14;
    int t; cin >> t;
    while(t--){
        int n; ll a,b; cin >> n >> a >> b;
        string s; cin >> s;

        vll anterior(2);
        anterior[0] = b;
        anterior[1] = INF;

        vll actual(2);

        for(int i = 1; i < (int) n; i++){
            if(s[i] == '1' || s[i-1] == '1') actual[0] = INF;
            else actual[0] = min(anterior[0]+a+b, anterior[1]+2*a+b);
            actual[1] = min(anterior[0]+2*a+2*b, anterior[1]+a+2*b);
            anterior = actual;
        }
        
        actual[0] = min(anterior[0]+a+b, anterior[1]+2*a+b);
        actual[1] = min(anterior[0]+2*a+2*b, anterior[1]+a+2*b);

        cout << actual[0] << "\n";
    }
    

    return 0;
}
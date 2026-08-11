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
    int n; cin >> n;
    string s; cin >> s;
    vbool v(10);
    F0(i,n){
        if(s[i] == 'L'){
            F0(j,10) if(!v[j]){v[j] = true; break;}
        }
        else if(s[i] == 'R'){
            for(int j = 9; j >= 0; j--) if(!v[j]){v[j] = true; break;}
        }
        else{
            int val = s[i] - '0';
            v[val] = false;
        }
    }
    F0(i,10) cout << v[i];
    cout << "\n";
    
    return 0;
}
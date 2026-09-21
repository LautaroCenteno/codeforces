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
        string s; cin >> s;
        int uno = 0;
        int res1 = 0;
        int res2 = 0;
        F0(i,n){
            if(s[i] == '1'){
                uno = i;
                break;
            }
        }
        if(uno == (n-1)){
            cout << 0 << "\n";
            continue;
        }
        int cant0 = 0;
        int cant1 = 0;
        for(int i = uno; i < n; i++){
            if(s[i] == '1') cant1++;
            else cant0++;
        }
        if(uno == 0){
            cout << cant0 << "\n";
        }else{
            cout << min(cant0, cant1) << "\n";
        }
        /*
        for(int i = uno+1; i < n; i++){
            if(s[i] == '0') res1++;
        }
        for(int i = uno; i >= 0; i--){
            if(s[i] == '1') res2++;
        }
        */
        //cout << min(res1,res2) << "\n";
    }
    return 0;
}
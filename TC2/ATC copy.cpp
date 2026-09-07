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
    string s; cin >> s;
    int n = s.size();
    vector<string> v1(n); //con 8
    vector<string> v2(n);
    v1[0] = s[0] ;
    if(s[0] == 'a') v2[0] = "";
    else v2[0] = s[0];
    F1(i,n-1){
        v1[i] = v1[i-1] + s[i];
    }
    F1(i,n-1){
        if(s[i] != 'a') v2[i] = v2[i-1] + s[i];
        else v2[i] = v2[i-1];
    }
    bool b = false;
    string res;
    //F0(i,n) cout << v1[i] << "\n";
    //F0(i,n) cout << v2[i] << "\n";
    F0(i,n){
        //cout << "i: " << i << "\n";
        if(v1[i]+v2[i] == s){
            //cout << "entro" << "\n";
            b = true;
            res = v1[i];
        }
    }
    if(b) cout << res;
    else cout << ":(";

    return 0;
}
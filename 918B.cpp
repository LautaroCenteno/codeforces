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
    int n;
    int m;
    map<string, string> ips;
    cin >> n;
    cin >> m;
    while(n--){
        string name;
        string ip;
        cin >> name;
        cin >> ip;
        ips[ip] = name;
    }
    
    while(m--){
        string a;
        string b;
        string ip = "";
        cin >> a;
        cin >> b;
        for(char c:b){
            if(c != ';') ip += c;
        }
        cout << a << " " << b << " #" << ips[ip] << "\n";
    }

    return 0;
}
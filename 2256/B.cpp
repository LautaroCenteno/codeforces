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

int solve(int& n; string& s, int& i){
    for(; i < n-1; i++){
        if(s[i+1] == '?'){
            
            break;
        } else{
            if(s[i-1] == s[i+1]){
                return 0;
            }
        }
    }
}

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int res = 0;
        if(n == 2){
            F0(i,n){
                if(s[i]  == '?') res += 2;
            }
        } else {
            vector<string> v;
            if(s[0] == '?' && s[1] == '?' && s[2] == '?'){
                F0(a,2){
                    F0(b,2){
                        F0(c,2){
                            char a1 = a + '0';
                            char b1 = b + '0';
                            char c1 = c + '0';
                            string s1 = s;
                            s1[0] = a;
                            s1[1] = b;
                            s1[2] = c;
                            if(s1[0] != s1[2]) v.pb(s1);
                        }
                    }
                }
            } else if(s[0] == '?' && s[1] == '?'){
                F0(a,2){
                    F0(b,2){
                        char a1 = a + '0';
                        char b1 = b + '0';
                        char c1 = c + '0';
                        string s1 = s;
                        s1[0] = a1;
                        s1[1] = b1;
                        s1[2] = c1;
                        if(s1[0] != s1[2]) v.pb(s1);
                    }
                }
            } else if(s[1] == '?' && s[2] == '?'){
                F0(a,2){
                    F0(b,2){
                        char a1 = a + '0';
                        char b1 = b + '0';
                        string s1 = s;
                        s1[1] = a1;
                        s1[2] = b1;
                        if(s1[0] != s1[2]) v.pb(s1);
                    }
                }
            } else if(s[0] == '?' && s[2] == '?'){
                F0(a,2){
                    F0(b,2){
                        char a1 = a + '0';
                        char b1 = b + '0';
                        string s1 = s;
                        s1[0] = a1;
                        s1[2] = b1;
                        if(s1[0] != s1[2]) v.pb(s1);
                    }
                }
            } else if(s[0] == '?'){
                F0(a,2){
                    char a1 = a + '0';
                    string s1 = s;
                    s1[0] = a1;
                    if(s1[0] != s1[2]) v.pb(s1);
                }
            } else if(s[1] == '?'){
                F0(a,2){
                    char a1 = a + '0';
                    string s1 = s;
                    s1[0] = a;
                    if(s1[0] != s1[2]) v.pb(s1);
                }
            } else if(s[2] == '?'){
                F0(a,2){
                    char a1 = a + '0';
                    string s1 = s;
                    s1[0] = a;
                    if(s1[0] != s1[2]) v.pb(s1);
                }
            }

            for(const string& z : v){
                res += solve(n, z, 2)
            }
        }

    }

    return 0;
}
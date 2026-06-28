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
    int t;
    cin >> t;
    F0(i,t){
        int n; cin >> n;
        vi a(n); 
        F0(i,n){
            cin >> f;
            if(!a.empty){
                pi pf
            } else{
                pi pf = {f, -1}
            }
            a.pb(pf)
        } 

        /*
        int res = 1;
        int actual = -1;
        int pp = -1;
        int contador = 0;
        F0(i,n-1){
            if(a[i] == a[i+1]){
                if(pp == -1){
                    pp = i;
                    actual = i+1;
                    res++;
                    contador = 0;
                } else if(a[i] == a[actual] && contador > 0){
                    actual = i+1;
                    res += 2;
                    contador = 0;
                } else{
                    actual = i+1;
                    res++; 
                    contador = 0;
                }
            } else contador++;
        }
        if(pp+1 != actual){
            if(a[actual] != a[pp]){
                res--;
            }
        }
        */
        cout << res << "\n";
        //cout << pp << " " << actual << "\n";
    }
}
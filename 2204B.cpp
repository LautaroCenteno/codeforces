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
        int n;
        cin >> n;
        vi v;
        F0(j,n){
            int a;
            cin >> a;
            v.pb(a);
        }
        int res = 1;
        int max = v[0];
        for(int j = 1; j < v.size(); j++){
            if(v[j] >= v[j-1] && v[j] >= max){
                res+=1;
                max = v[j];
            }
        }
        /*
        while(v.size() > 0){
            int maxI = 0;
            for(int j = 1; j < v.size(); j++){
                if(v[j] >= v[maxI]) maxI = j;
            }
            vi v2;
            for(int j = 0; j < maxI; j++){
                v2.pb(v[j]);
            }
            v = v2;
            res += 1;
        }
        */
        /*
        cout << maxI << "\n";
        for(int l : v){
            cout << l << " ";
        }
        cout << "\n";
        */
        cout << res << "\n";
    }
}
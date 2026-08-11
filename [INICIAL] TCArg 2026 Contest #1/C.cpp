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
    int n, k;
    cin >> n >> k;
    unordered_set<int> set;
    vi res;
    F0(i,n){
        if(res.size() == k){
            cout << "YES" << "\n";
            F0(j,k){
                cout << res[j] << " ";
            }
            cout << "\n";
            return 0;
        }
        int a; cin >> a;
        if(set.count(a) == 0){
            set.insert(a);
            res.pb(i+1);
        }
        
    }
    if(res.size() == k){
        cout << "YES" << "\n";
        F0(j,k){
            cout << res[j] << " ";
        }
        cout << "\n";
        return 0;
    }
    cout << "NO";
    return 0;
}
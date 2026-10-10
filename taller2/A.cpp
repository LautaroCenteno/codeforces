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
    const int INF = 1e9;
    int n; cin >> n;
    vi gym(n+1, 1); vbool comp(n+1, 1);
    F1(i,n){
        int a; cin >> a;
        if(a == 1) comp[i] = 0;
        if(a == 2) gym[i] = 0;
        if(a == 3){gym[i] = 0; comp[i] = 0;} 
    }
    vi anterior(3);
    anterior[0] = 1;
    anterior[1] = gym[1];
    anterior[2] = comp[1];

    if(n == 1){
        cout << min(anterior[0], min(anterior[1], anterior[2]));
        return 0;
    }

    vi actual(3);

    for(int i = 2; i <= n; i++){
        actual[0] = min(anterior[2] + 1, anterior[1] + 1);
        actual[1] = min(anterior[0] + gym[i], anterior[2] + gym[i]);
        actual[2] = min(anterior[0] + comp[i], anterior[1] + comp[i]);
        anterior = actual;
    }

    cout << min(actual[1],actual[2]) << "\n";

    return 0;
}
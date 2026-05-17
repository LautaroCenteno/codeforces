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
    cin >> n;
    int ntemp = n;

    vll v1;
    vector<pi> v2;
    
    while(ntemp--){
        int x;
        int h;
        cin >> x;
        cin >> h;
        pi p = {x,h};
        v1.pb((ll) x);
        v2.pb(p);
    }

    int res;
    if(n>1) res = 2; //el primero y el ultimo siempre se pueden bajar
    else res = 1;

    //ignoro el primero y el ultimo
    if(n>2){
        for(int i=1; i < n-1; i++){
            if((ll) v2[i].first - (ll) v2[i].second > v1[i-1]){
                res++;
            }else{
                if((ll) v2[i].first + (ll) v2[i].second < v1[i+1]){
                    v1[i] = (ll) v2[i].first + (ll) v2[i].second;
                    res++;
                }
            }
        }
    }

    /*
    for(int i=1; i < n-1; i++){
        if((ll) v2[i].first - (ll) v2[i].second > v1[i-1]){
            res++
        }else{
            if((ll) v2[i].first + (ll) v2[i].second < v1[i+1]){
                v1[i] = (ll) v2[i].first + (ll) v2[i].second;
                res++;
            }
        }
    }
    */
    
    cout << res;

    return 0;
}
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
    int x1,x2,x3,x4; cin>>x1>>x2>>x3>>x4;
    vi v ={x1,x2,x3,x4};
    int index = -1;
    int max = 1;
    F0(i,v.size()){
        if(v[i] > max){
            max = v[i]; index = i;
        }
    }
    F0(i,v.size()){
        if(i!=index) cout << max-v[i] << " ";
    }
    return 0;
}
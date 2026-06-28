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
        int n,x,y,z;
        cin >> n >> x >> y >> z;
        int sum1 = 0; //sin AI
        int h1 = 0;
        int sum2 = 0; //con AI
        int h2 = 0;

        while(sum1 < n){
            sum1+=x;
            sum1+=y;
            h1++;
        }

        while(sum2 < n){
            sum2+=x;
            if(h2 < z){
                sum2+=0;
            } else{
                sum2+=y*10;
            }
            h2++;
        }

        int res = min(h1,h2);

        cout << res << "\n";
    }
}
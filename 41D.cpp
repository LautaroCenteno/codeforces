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

int n,m,k;
int mINF = -1e9;

int f(int x, int y, int r, vector<string>& g, vector<vvi>& dp){
    int c = g[y][x] - '0';
    if(y == 0){
        if(c % (k+1) == r){
            dp[x][y][r] = c;
            return c;
        } 
        else{
            dp[x][y][r] = mINF;
            return mINF;
        }
    }
    if(dp[x][y][r] != -1) return dp[x][y][r];
    int res = mINF;
    int nuevo_r = ((r - c) % (k+1) + (k+1)) % (k+1);
    if(x == 0) res = c + f(x+1,y-1,nuevo_r,g,dp);
    else if(x == m-1) res = c + f(x-1,y-1,nuevo_r,g,dp);
    else res = max(c + f(x+1,y-1,nuevo_r,g,dp), c + f(x-1,y-1,nuevo_r,g,dp));
    dp[x][y][r] = res;
    return res;
}

int main() {
    cin >> n >> m >> k;
    vector<string> g(n);
    for(int i = n-1; i > -1; i--) cin >> g[i];
    vector<vvi> dp(m, vvi(n, vi(k+1, -1)));
    int maximo = mINF;
    F0(i,m) maximo = max(maximo, f(i,n-1,0,g,dp));
    vi camino;
    int va = mINF;
    int pa = -1;
    int ra = 0;
    if(maximo < 0) cout << -1 << "\n";
    else{
        F0(i,m){
            if(dp[i][n-1][0] > va){
                va = dp[i][n-1][0];
                pa = i;
            }
        } 
        int ca = g[n-1][pa] - '0';
        ra = ((ra - ca) % (k+1) + (k+1)) % (k+1);
        camino.pb(pa);
        for(int i = n-2; i > -1; i--){
            if(pa == 0){
                ca = g[i][pa+1] - '0';
                va = dp[pa+1][i][ra];
                pa = pa+1;
            }
            else if(pa == m-1){
                ca = g[i][pa-1] - '0';
                va = dp[pa-1][i][ra];
                pa = pa-1;
            }
            else{
                if(dp[pa-1][i][ra] > dp[pa+1][i][ra]){
                    ca = g[i][pa-1] - '0';
                    va = dp[pa-1][i][ra];
                    pa = pa-1;
                }
                else{
                    ca = g[i][pa+1] - '0';
                    va = dp[pa+1][i][ra];
                    pa = pa+1;
                }
            }
            ra = ((ra - ca) % (k+1) + (k+1)) % (k+1);
            camino.pb(pa);
        }
        reverse(camino.begin(),camino.end());
        string camino_res = "";
        cout << maximo << "\n";
        cout << camino[0]+1 << "\n";
        F1(i,camino.size()-1){
            if(camino[i-1] < camino[i]) camino_res += 'R';
            else camino_res += 'L';
        }
        cout << camino_res;
        cout << "\n";
    }
    
    
    return 0;
}
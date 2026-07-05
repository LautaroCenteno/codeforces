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

bool base;
bool norte;
bool este;
bool sur;
bool oeste;
bool techo;
vbool base = {&norte,&este,&sur,&oeste}; //{N,E,S,O}
vbool norte = {&techo,&oeste,&este,&base};
vbool este = {&techo,&norte,&sur,&base};
vbool sur = {&techo,&este,&oeste,&base};
vbool oeste = {&techo,&sur,&norte,&base};
vbool techo = {&norte,&este,&sur,&oeste};
//*vbase[0] = true;

struct estado {
    int i;
    int j;
    int d; //norte = 0, este = 1, sur = 2, oeste = 3
    vbool pos;
};

void bfs(int i, int j, vector<string>& v, vector<vbool>& visited){
    queue<estado> q;
    q.push({i,j,1,base});
    visited[i][j] = true;
    while(!q.empty()){
        estado actual = q.front();

        q.pop()
    }
}

int main() {
    vector<string> v(6);
    F0(i,n) cin >> v[i];

    vector<vbool> visited(6, vbool(6));
    
    bfs(n, v, visited)

    return 0;
}
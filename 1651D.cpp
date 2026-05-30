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

bool valExists(unordered_map<int, unordered_set<int>> m, int x, int y) {
    if (m[x].count(y)) { //MODIFICADO
        return true;
    }
    else {
        return false;
    }
}

void bfs_V2(long long hash){
    queue<pi> q;
    unordered_set<long long> visited;
    long long resp;
    bool encontrado = false;
    int x = hash / maxI;
    int y = hash % maxI;
    pi p_inicial = {x,y};
    visited.insert(hash);
    q.push(p_inicial);
    while(!q.empty()){
        //VERIFICO PRIMERO SI ALGUNO ES RESPUESTA
        if((q.front().first + 1) <= 200000 && visited.count(1LL * (q.front().first + 1) * maxI + q.front().second) != 1 && RES.count(1LL * (q.front().first + 1) * maxI + q.front().second) == 1) {
            encontrado = true;
            resp = 1LL * (q.front().first + 1) * maxI + q.front().second;
            RESPUESTAS[hash] = resp;
            return;
        }
        if((q.front().first - 1) >= 1 && visited.count(1LL * (q.front().first - 1) * maxI + q.front().second) != 1 && RES.count(1LL * (q.front().first - 1) * maxI + q.front().second) == 1){
            encontrado = true;
            resp = 1LL * (q.front().first - 1) * maxI + q.front().second;
            RESPUESTAS[hash] = resp;
            return;
        } 
        if((q.front().second + 1) <= 200000 && visited.count(1LL * q.front().first * maxI + (q.front().second + 1)) != 1 && RES.count(1LL * q.front().first * maxI + (q.front().second + 1)) == 1){
            encontrado = true;
            resp = 1LL * q.front().first * maxI + (q.front().second + 1);
            RESPUESTAS[hash] = resp;
            return;
        } 
        if((q.front().second - 1) >= 1 && visited.count(1LL * q.front().first * maxI + (q.front().second - 1)) != 1 && RES.count(1LL * q.front().first * maxI + (q.front().second - 1)) == 1){
            encontrado = true;
            resp = 1LL * q.front().first * maxI + (q.front().second - 1);
            RESPUESTAS[hash] = resp;
            return;
        }
        //COMO NO HUBO RESPUESTA, AÑADO A LA COLA LOS ADYACENTES
        if((q.front().first + 1) <= 200000 && visited.count(1LL * (q.front().first + 1) * maxI + q.front().second) != 1) {
            visited.insert(1LL * (q.front().first + 1) * maxI + q.front().second);
            q.push({q.front().first + 1, q.front().second});
        }
        if((q.front().first - 1) >= 1 && visited.count(1LL * (q.front().first - 1) * maxI + q.front().second) != 1){
            visited.insert(1LL * (q.front().first - 1) * maxI + q.front().second);
            q.push({q.front().first - 1, q.front().second});
        } 
        if((q.front().second + 1) <= 200000 && visited.count(1LL * q.front().first * maxI + (q.front().second + 1)) != 1){
            visited.insert(1LL * q.front().first * maxI + (q.front().second + 1));
            q.push({q.front().first, q.front().second + 1});
        } 
        if((q.front().second - 1) >= 1 && visited.count(1LL * q.front().first * maxI + (q.front().second - 1)) != 1){
            visited.insert(1LL * q.front().first * maxI + (q.front().second - 1));
            q.push({q.front().first, q.front().second - 1});
        }

        q.pop();
    }
}

int main() {
    int n;
    cin >> n;
    unordered_map<int, unordered_set<int>> m;
    F0(i,n){
        int x,y;
        cin >> x >> y;
        m[x].insert(y);
    }
    return 0;
}
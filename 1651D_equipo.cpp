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

unordered_set<long long> myArray;
unordered_map<long long, long long> RES;
unordered_map<long long, long long> RESPUESTAS;
vector<long long> sinRespuestas;
int maxI = 200005;
 
bool valExists(int x, int y) {  //O(1)
    if (myArray.count(1LL * x * maxI + y)) {
        return true;
    }
    else {
        return false;
    }
}
 
void bfs(long long hash){
    int dist = 300000;
    long long resp;
    for (const auto& pair : RES) {
        int y1 = hash % maxI;
        int x1 = hash / maxI;
        int y = pair.first % maxI;
        int x = pair.first / maxI;
        if((abs(x-x1) + abs(y - y1)) < dist){
            resp = pair.first;
        }
    }
    RESPUESTAS[hash] = resp;
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

void encontrar_respuesta(long long hash){
    long long resp;
    for (const auto& [k,v] : RES) {
        int x = hash / maxI;
        int y = hash % maxI;
        int x1 = k / maxI;
        int y1 = k % maxI;
        if(abs(x-x1) + abs(y - y1) < abs(x - (resp / maxI)) + abs(y - (resp % maxI))){
            resp = k;
        }
    }
    RESPUESTAS[hash] = resp;
}
 
void find_nearest_V2(int x, int y) {    //O(1)
    long long reshash;
    int count = 0;
    for (int deltaX = 0; deltaX < 2; deltaX++)
    {
        for (int deltaY = 0; deltaY < 2; deltaY++) {
            if (deltaX == 0 && deltaY == 0){
                continue;
            }
            if (deltaX ==1 && deltaY == 1){
                continue;
            }
            if (!valExists(x - deltaX, y - deltaY))
            {
 
                reshash = 1LL * (x - deltaX) * maxI + (y - deltaY);
                count += 1;
            }
            else if (!valExists(x - deltaX, y + deltaY)) {
                reshash = 1LL * (x - deltaX) * maxI + (y + deltaY);
                count += 1;
            }
            else if (!valExists(x + deltaX, y - deltaY)) {
                reshash = 1LL * (x + deltaX) * maxI + (y - deltaY);
                count += 1;
            }
            else if (!valExists(x + deltaX, y + deltaY)) {
                reshash = 1LL * (x + deltaX) * maxI + (y + deltaY);
                count += 1;
            }
        }
    }
    if(count > 0 && count < 4){
        RES[reshash] = 1LL * x * maxI + y;
    }
    if(count > 0){
        RESPUESTAS[1LL * x * maxI + y] = reshash;
    }else{
        sinRespuestas.push_back(1LL * x * maxI + y);
    }
    
}
 
std::string find_nearest(int x, int y) {
    for (int i = 0; true; i++)
    {
        for (int deltaX = 0; deltaX < i + 2; deltaX++)
        {
            for (int deltaY = 0; deltaY < i + 2; deltaY++) {
                if (deltaX == 0 && deltaY == 0){
                    continue;
                }
                if (deltaX < i && deltaY < i){
                    continue;
                }
                if (!valExists(x - deltaX, y - deltaY))
                {
                    return std::to_string(x - deltaX) + " " + std::to_string(y - deltaY);
                }
                else if (!valExists(x - deltaX, y + deltaY)) {
                    return std::to_string(x - deltaX) + " " + std::to_string(y + deltaY);
                }
                else if (!valExists(x + deltaX, y - deltaY)) {
                    return std::to_string(x + deltaX) + " " + std::to_string(y - deltaY);
                }
                else if (!valExists(x + deltaX, y + deltaY)) {
                    return std::to_string(x + deltaX) + " " + std::to_string(y + deltaY);
                }
 
            }
        }
    }
}
 
int main() {
    int amount;
    cin >> amount;
    vector<pair<int, int>> data;
    for (int i = 0; i < amount; i++) {
        int x,y;
        cin >> x >> y;
        data.push_back(make_pair(x, y));
        myArray.insert(1LL * x * maxI + y);
    }
    /*
    for (pair<int, int> p: data) {  //O(2.10^5)
        find_nearest_V2(p.first, p.second);
    }
    for (long long i: sinRespuestas){
        encontrar_respuesta(i);
    }
    */
    for (pair<int, int> p: data) {  //O(2.10^5)
        bfs_V2(1LL * p.first * maxI + p.second);
    }
 
    for (pair<int, int> p: data) {
        long long reshash = RESPUESTAS[1LL * p.first * maxI + p.second];
        cout << reshash / maxI << " " << reshash % maxI << endl;
    }
    return 0;
}
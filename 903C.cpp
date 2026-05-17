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

/*
int main() {
    int n;
    cin >> n;
    unordered_set<int> set;
    vector<unordered_set<int>> cant;
    int pos;
    while(c--) {
        int t = cin >> t;
        if(cant[pos].count(t) == 1) {
            pos++
            
        }
    }
    return 0;
}
Al principio encaré el ejercicio de esta forma, no es que lo haya pensado mucho, despues fui por otro camino
*/

int main() {
    int n;
    cin >> n;
    vector<pair<int,pair<bool,bool>>> v;

    int ntemp = n;

    while(ntemp--){
        int a;
        cin >> a;
        pair<int,pair<bool,bool>> p = {a,{false,false}}; // En .second: .first dice si ya está dentro de una caja, .second si contiene una caja.
        v.pb(p);
    }

    sort(v.begin(), v.end());

    /*
    for(pair<int,pair<bool,bool>> p:v){
        cout << p.first << "\n";
    }
    REVISÉ QUE EFECTIVAMENTE MI SORT ORDENE LOS PAIRS POR SU .FIRST, ES DECIR, EL TAMAÑO DE LA CAJA
    */

    //for(int i = 0; i < n-1; i++)
    F0(i,n-1){
        if(v[i].second.first == false){
            for(int j = i + 1; j < n; j++){
                if(v[j].first > v[i].first && v[j].second.second == false){
                    v[i].second.first = true;
                    v[j].second.second = true;
                    break;
                }
            }
        }
    }

    /*
    for(pair<int,pair<bool,bool>> p:v){
        cout << p.first << " " << p.second.first  << " " << p.second.second << "\n";
    }
    Reviso que se haya modificado los "pairs" correctamente
    */

    
    int res = 0;
    for(pair<int,pair<bool,bool>> p:v){
        if(p.second.first == false) res++;
    }
    
    cout << res;
    
    
    return 0;
}
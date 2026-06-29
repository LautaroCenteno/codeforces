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

int main(){
    int n; int p; int d; cin >> n >> p >> d;
    string s; cin >> s;
    s += s;
    //vi v(2*n);
    /*
    F0(i,n){
        if(s[i] == 'Z'){
            v[i] = 1;
            v[i+n] = 1;
        } else{
            v[i] = 0;
            v[i+n] = 0;
        }
    }
    */
    int res = 0;
    //cout << s << "\n";
    //Caso p == 1 (capaz no era necesario, no lo analicé)
    if(p==1){
        //cout << "entra caso p == 1" << "\n";
        F0(i,n){
            if(s[i] == 'W') res++;
        }
        cout << res;
        return 0;
    }
    //cout << "no entra en caso p == 1" << "\n";

    int i = n - p + 1;
    int j = n;
    int cont = 0;
    //cout << "i = " << i << "\n";
    //cout << "j = " << j << "\n";
    
    for(int k = i; k <= j; k++){
        if(s[k] == 'Z') cont++; 
    }
    //cout << "primer cont = " << cont << "\n";

    if(cont < d) res++;
    //cout << "entonces res = " << res << "\n";

    i++;
    j++;
    //cont = 0;
    /*
    for(int k = i; k <= j; k++){
        if(s[k] == 'Z') cont++; 
    }
    */
    if(s[i-1] == 'Z' && s[j] == 'W') cont--;
    if(s[i-1] == 'W' && s[j] == 'Z') cont++;
    

    while(j<2*n){
        //cout << "entra en el bucle" << "\n";
        //cout << "cont despues de desplazarse = " << cont << "\n";
        if(cont < d) res++; 
        //cout << "entonces res = " << res << "\n";
        i++;
        j++;
        //cont = 0;
        /*
        for(int k = i; k <= j; k++){
            if(s[k] == 'Z') cont++; 
        }
        */
        if(s[i-1] == 'Z' && s[j] == 'W') cont--;
        if(s[i-1] == 'W' && s[j] == 'Z') cont++;
    }
    
    cout << res << "\n";

    return 0;
}
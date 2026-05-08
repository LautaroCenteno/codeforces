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

int cant_0_1(string s){
    int res = 0;
    for (char x : s) {
        if (x == '0' || x=='1') {
            res += 1;
        }
    }
    return res;
}

int cant_2_5(string s){
    int res = 0;
    for (char x : s) {
        if (x == '2' || x=='3' || x=='4' || x=='5') {
            res += 1;
        }
    }
    return res;
}

int cant_6_9(string s){
    int res = 0;
    for (char x : s) {
        if (x=='6'|| x=='7' || x=='8' || x=='9') {
            res += 1;
        }
    }
    return res;
}

bool check(int n, string s){
    int n_1 = cant_0_1(s);
    int n_2 = cant_2_5(s);
    int n_3 = cant_6_9(s);
    int stk = 0;
    
    while(n_1 > 1){
        n_1 -= 2;
        if(n_2 > 0){
            n_2 -= 1;
            if(n_3 > 0) {
                n_3 -= 1;
                stk += 1;
            } else if(n_2 > 0) {
                n_2 -= 1;
                stk += 1;
            } else if(n_1 > 0) {
                n_1 -= 1;
                stk += 1;
            }
        } else if(n_1 > 0){
            n_1 -= 1;
            if(n_3 > 0) {
                n_3 -= 1;
                stk += 1;
            } else if(n_2 > 0) { //se puede borrar este if, lo dejo para que se entienda la idea
                n_2 -= 1;
                stk += 1;
            } else if(n_1 > 0) {
                n_1 -= 1;
                stk += 1;
            }
        }
    }
    return n == stk;
}

int check_copy(int n, string s){
    int n_1 = cant_0_1(s);
    int n_2 = cant_2_5(s);
    int n_3 = cant_6_9(s);
    int stk = 0;
    
    while(n_1 > 0){
        n_1 -= 1;
        
        if(n_2 > 0){
            n_2 -= 1;
            if(n_3 > 0) {
                n_3 -= 1;
                stk += 1;
            } else if(n_2 > 0) {
                n_2 -= 1;
                stk += 1;
            } else if(n_1 > 0) {
                n_1 -= 1;
                stk += 1;
            }
        } else if(n_1 > 0){
            n_1 -= 1;
            if(n_3 > 0) {
                n_3 -= 1;
                stk += 1;
            } else if(n_2 > 0) { //se puede borrar este if, lo dejo para que se entienda la idea
                n_2 -= 1;
                stk += 1;
            } else if(n_1 > 0) {
                n_1 -= 1;
                stk += 1;
            }
        }
    }
    return stk;
}

int display(int t, string n) {
    int l = 0;
    int r = t/4;
    
    if(check(r, n)) return r;
    else{
        while(l+1<r){
        int mid = l + (r-1)/2;
        if(check(mid,n)) l = mid;
        else r = mid;
        }
        return l;
    }
}

int main() {
    int t;
    string s;
    cin >> t;
    cin >> s;
    
    cout << check_copy(t,s);
    /*
    cout << display(t, s);
    cout << cant_0_1(s);
    cout << cant_2_5(s);
    cout << cant_6_9(s);
    */
    
}
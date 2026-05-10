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

int cant_0(string s){
    int res = 0;
    for (char x : s) {
        if (x == '0') {
            res += 1;
        }
    }
    return res;
}

int cant_1(string s){
    int res = 0;
    for (char x : s) {
        if (x == '1') {
            res += 1;
        }
    }
    return res;
}

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
int cant_0_9(string s){
    int res = 0;
    for (char x : s) {
        if (x == '0' || x=='1' || x == '2' || x=='3' || x=='4' || x=='5' || x=='6'|| x=='7' || x=='8' || x=='9') {
            res += 1;
        }
    }
    return res;
}

bool check_unos(int x, string s){
    int xt = x;
    int n_0 = cant_0(s);
    int n_1 = cant_1(s);
    int n_2_5 = cant_2_5(s);
    int n_6_9 = cant_6_9(s);
    int d = 0;
    int max = 0;

    bool p1 = false;
    bool p2 = false;
    bool p3 = false;
    bool p4 = false;
    
    //primera pos
    if(xt >= 0 && n_0 - xt > 0 ) {
        n_0 -= xt;
        p1 = true;
    }

    //segunda pos
    if(xt>0) {
        if(xt > n_6_9){
            xt -= n_6_9;
            n_6_9 = 0;
            if(xt > n_2_5){
                xt -= n_2_5;
                n_2_5 = 0;
                if(xt > n_0){
                    xt -= n_0;
                    n_0 = 0;
                    if(xt > n_1){
                        xt -= n_1;
                        n_1 = 0;
                    } else {
                        n_1 -= xt;
                        p2 = true;
                    }
                } else {
                    n_0 -= xt;
                    p2 = true;
                }
            } else {
                n_2_5 -= xt;
                p2 = true;
            }
        } else {
            n_6_9 -= xt;
            p2 = true;
        }
    }

    //tercera pos
    int xt = x;
    if(xt>0) {
        if(xt > n_2_5){
            xt -= n_2_5;
            n_2_5 = 0;
            if(xt > n_0){
                xt -= n_0;
                n_0 = 0;
                if(xt > n_1){
                    xt -= n_1;
                    n_1 = 0;
                } else {
                    n_1 -= xt;
                    p2 = true;
                }
            } else {
                n_0 -= xt;
                p2 = true;
            }
        } else {
            n_2_5 -= xt;
            p2 = true;
        }
    }

    //cuarta pos
    int xt = x;
    if(xt>0) {
        if(xt > n_6_9){
            xt -= n_6_9;
            n_6_9 = 0;
            if(xt > n_2_5){
                xt -= n_2_5;
                n_2_5 = 0;
                if(xt > n_0){
                    xt -= n_0;
                    n_0 = 0;
                    if(xt > n_1){
                        xt -= n_1;
                        n_1 = 0;
                    } else {
                        n_1 -= xt;
                        p2 = true;
                    }
                } else {
                    n_0 -= xt;
                    p2 = true;
                }
            } else {
                n_2_5 -= xt;
                p2 = true;
            }
        } else {
            n_6_9 -= xt;
            p2 = true;
        }
    }
    
    //...final...
    if(p1 && p2 && p3 && p4) return true;
    else return false;

}

int display(int n, string s) {
    int x = n/4;
    int xt = x;
    int n_0 = cant_0(s);
    int n_1 = cant_1(s);
    int n_2_5 = cant_2_5(s);
    int n_6_9 = cant_6_9(s);
    int d = 0;
    int max = 0;
    
    while (x>=0){
        bool p1 = false;
        bool p2 = false;
        bool p3 = false;
        bool p4 = false;
        int xt = x;
        
        //primera pos
        if(xt >= 0 && n_0 - xt > 0 ) {
            n_0 -= xt;
            p1 = true;
        }

        //segunda pos
        if(xt>0) {
            if(xt > n_6_9){
                xt -= n_6_9;
                n_6_9 = 0;
                if(xt > n_2_5){
                    xt -= n_2_5;
                    n_2_5 = 0;
                    if(xt > n_0){
                        xt -= n_0;
                        n_0 = 0;
                        if(xt > n_1){
                            xt -= n_1;
                            n_1 = 0;
                        } else {
                            n_1 -= xt;
                            p2 = true;
                        }
                    } else {
                        n_0 -= xt;
                        p2 = true;
                    }
                } else {
                    n_2_5 -= xt;
                    p2 = true;
                }
            } else {
                n_6_9 -= xt;
                p2 = true;
            }
        }

        //tercera pos
        int xt = x;
        if(xt>0) {
            if(xt > n_2_5){
                xt -= n_2_5;
                n_2_5 = 0;
                if(xt > n_0){
                    xt -= n_0;
                    n_0 = 0;
                    if(xt > n_1){
                        xt -= n_1;
                        n_1 = 0;
                    } else {
                        n_1 -= xt;
                        p2 = true;
                    }
                } else {
                    n_0 -= xt;
                    p2 = true;
                }
            } else {
                n_2_5 -= xt;
                p2 = true;
            }
        }

        //cuarta pos
        int xt = x;
        if(xt>0) {
            if(xt > n_6_9){
                xt -= n_6_9;
                n_6_9 = 0;
                if(xt > n_2_5){
                    xt -= n_2_5;
                    n_2_5 = 0;
                    if(xt > n_0){
                        xt -= n_0;
                        n_0 = 0;
                        if(xt > n_1){
                            xt -= n_1;
                            n_1 = 0;
                        } else {
                            n_1 -= xt;
                            p2 = true;
                        }
                    } else {
                        n_0 -= xt;
                        p2 = true;
                    }
                } else {
                    n_2_5 -= xt;
                    p2 = true;
                }
            } else {
                n_6_9 -= xt;
                p2 = true;
            }
        }
        
        //...final...
        if(p1 && p2 && p3 && p4 && x > d) d = x;
        x-=1;
    }

    while(d >= 0){
        int l = 0;
        int r = n/4;
        if(check(r, s)) return r;
        else{
            while(l+1<r){
                int mid = l + (r-1)/2;
                if(check(mid,s)) l = mid;
                else r = mid;
            }
        return l;
        }
        d -= 1;
    }

    
}

int display_copy(int n, string s) {
    int x = n/4;
    int xt = x;
    int n_0 = cant_0(s);
    int n_1 = cant_1(s);
    int n_0_1 = cant_0_1(s);
    int n_2_5 = cant_2_5(s);
    int n_6_9 = cant_6_9(s);
    int n_0_9 = cant_0_9(s);
    int d = 0;

    while (x>=0){
        int xt = x;
        if(n_0 >= x) {
            n_0 -= x;
            n_0_1 -= x;
            n_0_9 -= x;
            if(n_6_9 >= x){
                n_6_9 -= x;
                if(n_2_5 >= x){
                    n_2_5 -= x;
                    
                }
            }

        } else continue;
        x-=1;
    }



    int l = 0;
    int r = n/4;
    
    if(check(r, s)) return r;
    else{
        while(l+1<r){
        int mid = l + (r-1)/2;
        if(check(mid,s)) l = mid;
        else r = mid;
        }
        return l;
    }
}

int main() {
    int t;
    cin >> t;

    while (t > 0){
        int n;
        string s;
        cin >> n;
        cin >> s;
        t-=1;
    }
}
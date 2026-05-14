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

bool check_unos(int x, string s, int n_0, int n_1, int n_2_5, int n_6_9){
    int xt = x;

    bool p1 = false;
    bool p2 = false;
    bool p3 = false;
    bool p4 = false;
    
    //primera pos
    if(xt >= 0 && n_1 - xt >= 0 ) {
        n_1 -= xt;
        p1 = true;
    }

    //segunda pos
    if(xt>0) {
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
    }

    //tercera pos
    xt = x;
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
                    p3 = true;
                }
            } else {
                n_0 -= xt;
                p3 = true;
            }
        } else {
            n_2_5 -= xt;
            p3 = true;
        }
    }

    //cuarta pos
    xt = x;
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
                        p4 = true;
                    }
                } else {
                    n_0 -= xt;
                    p4 = true;
                }
            } else {
                n_2_5 -= xt;
                p4 = true;
            }
        } else {
            n_6_9 -= xt;
            p4 = true;
        }
    }
    
    //...final...

    if(p1 && p2 && p3 && p4) return true;
    else if(x == 0) return true;
    else return false;

}

int display(int n, string s) {
    int x = n/4;
    int xt = x;
    /*
    int n_0 = cant_0(s);
    int n_1 = cant_1(s);
    int n_2_5 = cant_2_5(s);
    int n_6_9 = cant_6_9(s);
    int d = 0; //cantidad de displays 0_:__
    int t = 0; //cantidad de displays 1_:__
    */
    int max = 0; //cantidad maxima de displays

    while (x>=0){
        int n_0 = cant_0(s);
        int n_1 = cant_1(s);
        int n_2_5 = cant_2_5(s);
        int n_6_9 = cant_6_9(s);
        int d = 0; //cantidad de displays 0_:__
        int t = 0; //cantidad de displays 1_:__
        bool p1 = false;
        bool p2 = false;
        bool p3 = false;
        bool p4 = false;
        xt = x;
        
        //primera pos
        if(xt >= 0 && n_0 - xt >= 0 ) {
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
        xt = x;
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
                        p3 = true;
                    }
                } else {
                    n_0 -= xt;
                    p3 = true;
                }
            } else {
                n_2_5 -= xt;
                p3 = true;
            }
        }

        //cuarta pos
        xt = x;
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
                            p4 = true;
                        }
                    } else {
                        n_0 -= xt;
                        p4 = true;
                    }
                } else {
                    n_2_5 -= xt;
                    p4 = true;
                }
            } else {
                n_6_9 -= xt;
                p4 = true;
            }
        }
        
        //...final...
        if((p1 && p2 && p3 && p4) || x == 0){
            d = x;
            int l = 0;
            int r = n/4;
            if(check_unos(r, s, n_0, n_1, n_2_5, n_6_9)) {
                t = r;
            }
            else{
                while(l+1<r){
                    int mid = l + (r-l)/2;
                    if(check_unos(mid,s, n_0, n_1, n_2_5, n_6_9)) l = mid;
                    else r = mid;
                }
                t = l;
            }

            if(d+t > max) max = d + t;
        } 
        x-=1;
    }
    /*
    while(d >= 0){
        int l = 0;
        int r = n/4;
        if(check_unos(r, s)) {
            t = r;
        }
        else{
            while(l+1<r){
                int mid = l + (r-1)/2;
                if(check_unos(mid,s)) l = mid;
                else r = mid;
            }
            t = r;
        }

        if(d+t > max) max = d + t;

        d -= 1;

        //como mi d son las cantidades de displays con 0 que armo y en el paso anterior le reste uno, tengo que reconstruir rangos con numeros restantes
        //hay cosas de mas que se pueden borrar pero creo que no afectan, copié y pegué
        xt = d;
        n_0 = cant_0(s);
        n_1 = cant_1(s);
        n_2_5 = cant_2_5(s);
        n_6_9 = cant_6_9(s);
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
        xt = d;
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
        xt = d;
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
    }  
    */

    return max;
}

int main() {
    int t;
    
    cin >> t;
    
    while(t--){
        int n;
        string s;
        cin >> n;
        cin >> s;
        cout << display(n,s) << "\n";
    }
}
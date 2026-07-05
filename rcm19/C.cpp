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

int cant_true(vbool v){
    int res = 0;
    F0(i,v.size()){
        if(v[i]) res++;
    }
    return res;
}

int main() {
    vector<string> m(6);
    F0(i,6){
        cin >> m[i];
    }
    int max = 2;
    vi cordH;
    vi cordV;
    //horizontal
    F0(i,6){
        int actual = 0;
        F0(j,6){
            if(m[i][j] == '#' && j != 5) actual++;
            else if(m[i][j] == '#' && j == 5){
                actual++;
                if(actual > max){
                    max = actual;
                    cordV.clear();
                    cordV.pb(i);
                } else if(actual == max){
                    cordV.pb(i);
                }
            }
            else{
                if(actual > max){
                    max = actual;
                    cordV.clear();
                    cordV.pb(i);
                } else if(actual == max){
                    cordV.pb(i);
                }
                actual = 0;
            }
        }
        
    }

    //vertical
    F0(j,6){
        int actual = 0;
        F0(i,6){
            if(m[i][j] == '#' && i != 5) actual++;
            else if(m[i][j] == '#' && i == 5){
                actual++;
                if(actual > max){
                    max = actual;
                    cordV.clear();
                    cordH.clear();
                    cordH.pb(j);
                } else if(actual == max){
                    cordH.pb(j);
                }
            }
            else{
                if(actual > max){
                    max = actual;
                    cordV.clear();
                    cordH.clear();
                    cordH.pb(j);
                } else if(actual == max){
                    cordH.pb(j);
                }
                actual = 0;
            }
        }
    }
    //cout << max << "\n";
    //F0(i,cordH.size()) cout << cordH[i] << " ";
    //cout << "\n";
    //F0(i,cordV.size()) cout << cordV[i] << " ";
    //cout << "\n";

    vbool h(6);
    vbool v(6);

    //horizontal
    F0(i,6){
        F0(j,6){
            if(h[j]) continue;
            else{
                if(m[i][j] == '#') h[j] = true;
            }
        }
    }
    //F0(i,6) cout << h[i] << " ";
    //cout << "\n";

    //vertical
    F0(i,6){
        if(v[i]) continue;
        F0(j,6){
            if(m[i][j] == '#') v[i] = true;
        }
    }
    //F0(i,6) cout << v[i] << " ";
    //cout << "\n";
    
    if(max==2){
        cout << "can fold";
        return 0;
    } else if(max==3){
        //cout << "entra en max==3" << "\n";
        bool res = false;
        //cout << "res = " << res << "\n";
        if(cordH.size() > 0){
            //cout << "entra en cordH" << "\n";
            //cout << "cordH[0] > 0 = " << (cordH[0] > 0) << "\n";
            //cout << "cordH[0] < 5 = " << (cordH[0] < 5) << "\n";
            //cout << "h[cordH[0]] = " << h[cordH[0]] << "\n";
            //cout << "h[cordH[0]-1] = " << h[cordH[0]-1] << "\n";
            //cout << "h[cordH[0]+1] = " << h[cordH[0]+1] << "\n";
            //cout << "cant_true(v) == 4 = " << (cant_true(v) == 4) << "\n";
            //cout << "cant_true(v) = = " << cant_true(v) << "\n";
            if(cordH[0] > 0 && cordH[0] < 5 && h[cordH[0]] && h[cordH[0]-1] && h[cordH[0]+1] && cant_true(v) == 4){
                //cout << "res es ahora TRUE" << "\n";
                res = true;
            }
        }
        if(cordV.size() > 0){
            if(cordV[0] > 0 && cordV[0] < 5 && v[cordV[0]] && v[cordV[0]-1] && v[cordV[0]+1] && cant_true(h) == 4){
                res = true;
            }
        }
        if(res) cout << "can fold";
        else cout << "cannot fold";
    } else if(max==4){
        if(cordH.size() > 0){
            if(cordH[0] > 0 && cordH[0] < 5 && h[cordH[0]] && h[cordH[0]-1] && h[cordH[0]+1]){
                cout << "can fold";
                return 0;
            }else{
                cout << "cannot fold";
                return 0;
            }
        }else if(cordV.size() > 0){
            if(cordV[0] > 0 && cordV[0] < 5 && v[cordV[0]] && v[cordV[0]-1] && v[cordV[0]+1]){
                cout << "can fold";
                return 0;
            }else{
                cout << "cannot fold";
                return 0;
            }
        }
    } else{
        cout << "cannot fold";
        return 0;
    }
    

    return 0;
}
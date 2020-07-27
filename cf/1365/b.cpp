/*
h3110_fr13nd,
 
AUTHOR : @sam_jn
*/
 
#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<pair<int, int>, null_type, less_equal<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define MOD 1000000007
#define pb push_back
#define ff first
#define ss second
#define in(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define ot(a, n) for(int i = 0; i < n; i++) cout << a[i] << " ";
#define ot2(a, n) for(int i = 0; i < n; i++) cout << a[i] << "\n";
ll pwr(ll a, ll b);
ll pwr(ll a, ll b, ll m);
int baap[200002];
int find(int i);  
bool Union(int x, int y);
ll inv(ll x) {return pwr(x, MOD - 2, MOD);}

//----------------------------------SOLUTION-BELOW-------------------------------------------// 

void solve(){
    int n;
    cin >> n;
    int a[n], b[n];
    in(a, n);
    in(b, n);
    int o = 0, z = 0;
    for(int i = 0; i < n; i++){
        if(b[i] == 0) z++;
        else o++;
    }
    int last = -1, flag = 1;
    if(o == 0){
        for(int i = 0; i < n; i++){
            // if(b[i] == 0){
                if(last == -1){
                    last = a[i];
                }
                if(a[i] < last){
                    flag = 0;
                    break;
                }
                else{
                    last = a[i];
                }
            // }
        }
        if(flag == 0){
            cout << "No";
            return;
        }
        cout << "Yes";        
    }
    else if(z == 0){
        flag = 1;
        last = -1;
        for(int i = 0; i < n; i++){
            // if(b[i] == 0){
                if(last == -1){
                    last = a[i];
                }
                if(a[i] < last){
                    flag = 0;
                    break;
                }
                else{
                    last = a[i];
                }
            // }
        }
        if(flag == 0){
            cout << "No";
            return;
        }
        cout << "Yes";
    }
    else cout << "Yes";
    // for(int i = 0; i < n; i++){
    //     if(b[i] == 0){
    //         if(last == -1){
    //             last = a[i];
    //         }
    //         if(a[i] < last){
    //             flag = 0;
    //             break;
    //         }
    //         else{
    //             last = a[i];
    //         }
    //     }
    // }
    // if(flag == 0){
    //     cout << "No";
    //     return;
    // }
    // flag = 1;
    // last = -1;
    // for(int i = 0; i < n; i++){
    //     if(b[i] == 1){
    //         if(last == -1){
    //             last = a[i];
    //         }
    //         if(a[i] < last){
    //             flag = 0;
    //             break;
    //         }
    //         else{
    //             last = a[i];
    //         }
    //     }
    // }
    // if(flag == 0){
    //     cout << "No";
    //     return;
    // }
    // cout << "Yes";
}
int main(){


                                                            #ifndef ONLINE_JUDGE    
                                                            freopen("/home/samyak/Desktop/CP/input.txt", "r", stdin);
                                                            freopen("/home/samyak/Desktop/CP/output2.txt", "w", stdout);
                                                            #else
                                                            // online submission
                                                            #endif
// 

    boost
    int _ = 1;
    // cout << 0 << endl;
    cin >> _;
    while(_--){
        solve();
        cout << endl;
    }
}
 
 
//--------------------------------------DEFININTIONS---------------------------------------
ll pwr(ll a, ll b){
    if(b == 0)
        return 1 ;
    ll c = pwr(a, b/2) ;
    c = c * c;
    if(b % 2)
        return c*a;
    return c ;
}
ll pwr(ll a, ll b, ll m){
    if(b == 0)
        return 1;
    ll c = pwr(a, b/2, m) % m ;
    c = (c * c) % m;    
    if(b % 2)
        return (c * a%m) % m;
    return c ;
}
int find(int i)  
{  
    if (baap[i] != i)  
        baap[i] = find(baap[i]);  
  
    return baap[i];  
}
 
bool Union(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return false;
    baap[x] = y;
    return true;
}
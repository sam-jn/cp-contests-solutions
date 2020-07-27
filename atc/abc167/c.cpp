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
#define ot1(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define ot2(a, n) for(int i = 0; i < n; i++) cout << a[i] << "\n";
ll pwr(ll a, ll b);
ll pwr(ll a, ll b, ll m);
int baap[200002];
int find(int i);  
bool Union(int x, int y);
ll inv(ll x) {return pwr(x, MOD - 2, MOD);}

//----------------------------------SOLUTION-BELOW-------------------------------------------// 

void solve(){   
    ll n, m, x;
    cin >> n >> m >> x;
    ll c[n], a[n][m];    
    for(int i = 0; i < n; i++){
        cin >> c[i];
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    ll p = pwr(2LL, n), ans = LLONG_MAX;
    for(int i = 1; i <= p; i++){
        ll num = i, j = 0;
        ll curr_cost = 0;
        ll under[m] = {0}, flag[m] = {0};
        while(num && j < n){

            ll mask = num % 2LL;
            num /= 2LL;
            if(mask){
                // cout << j << " ";
                curr_cost += c[j];
                for(int k = 0; k < m; k++){
                    // if(j < n){
                        under[k] += a[j][k];
                        if(under[k] >= x) flag[k] = 1;
                    // }
                }
            }
            j++;
        }
        bool flag2 = 1;
        for(int k = 0; k < m; k++){
            if(!flag[k]){
                flag2 = 0;
                break;
            }
        }
        if(flag2) ans = min(ans, curr_cost);

            // cout << endl;
    }
    if(ans != LLONG_MAX) cout << ans;
    else cout << -1;
}
int main(){


                                                            #ifndef ONLINE_JUDGE    
                                                            freopen("/home/samyak/Desktop/CP/input.txt", "r", stdin);
                                                            freopen("/home/samyak/Desktop/CP/output2.txt", "w", stdout);
                                                            #else
                                                            // online submission
                                                            #endif


    boost
    int _ = 1;
    // cout << 0 << endl;
    // cin >> _;
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
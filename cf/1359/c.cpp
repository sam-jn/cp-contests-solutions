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
double fun(double h, double c, ll n){
    return (n * h + (n - 1) * c) / double((2 * n - 1.0));
}
void solve(){ 
    double h, c, t;
    cin >> h >> c >> t;
    double mn = abs(t - (h + c) / 2.0);
    // cout << mn << endl;
    ll ans = 2;
    if(mn >= t){
        mn = t;
        ans = 0;
        cout << ans;
        return;
    }
    ll l = 0, r = INT_MAX;
    while (l <= r) { 
        ll m = l + (r - l) / 2; 
        double val = fun(h, c, m);

        if(abs(val - t) < mn){
            mn = abs(val - t);
            ans = 2 * m - 1;
        }
        if(abs(val - t) == mn){
            if(ans > 2 * m - 1) ans = 2 * m - 1;
        }
        if (t == val){
            mn = 0;
            ans = 2 * m - 1;
            break;
        }  
  
        if (t > val) 
            r = m - 1; 
  
        else
            l = m + 1; 
    }
    // ll a[n];
    // in(a, n);
    cout << ans;
    // cout << ans << " " << mn << " " << fun(h, c, (ans + 1) / 2);
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
    // cout << 5/(3 - 1.0);
    cin >> _;
    cout << fun(30,10,25) << endl;
    // cout << LLONG_MAX << endl;
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
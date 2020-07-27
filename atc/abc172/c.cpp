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
#define NN 1000002
#define in(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define ot(a, n) for(int i = 0; i < n; i++) cout << a[i] << " ";
#define ot2(a, n) for(int i = 0; i < n; i++) cout << a[i] << "\n";
ll pwr(ll a, ll b);
ll pwr(ll a, ll b, ll m);
int baap[200002];
int prime[NN];
int find(int i);  
bool Union(int x, int y);
ll inv(ll x) {return pwr(x, MOD - 2, MOD);}
void init();
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {-1, 1, 0, 0, 1, -1, 1, -1};
//----------------------------------SOLUTION-BELOW-------------------------------------------// 

void solve(){
    ll n, m, x, k, ans = INT_MIN;
    cin >> n >> m >> k;
    vector<ll> a, b;
    for(int i = 0; i < n; i++) {
        cin >> x;
        a.pb(x);
    }
    for(int i = 0; i < m; i++) {
        cin >> x;
        b.pb(x);
    }
    // cout << distance(b.begin(), b.end());

    for(int i = 1; i < n; i++) a[i] += a[i - 1];
    for(int i = 1; i < m; i++) b[i] += b[i - 1];
    auto v = upper_bound(b.begin(), b.end(), k);
    ll d = distance(b.begin(), v);
    // cout << i << " " << *v << " " << d << " " << endl;
    ans = max(ans, d);
    for(int i = 0; i < n; i++){
        if(a[i] <= k){
            auto v = upper_bound(b.begin(), b.end(), k - a[i]);
            ll d = distance(b.begin(), v);
            // cout << i << " " << *v << " " << d << " " << endl;
            ans = max(ans, i + 1 + d);
            // cout << *v;
        }
    }
    if(ans == INT_MIN) cout << 0;
    else cout << ans;
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
void init(){
  for(ll i = 2; i < NN; i++){
      if(prime[i]) continue;
      for(ll j = 2*i; j < NN; j += i)
          prime[j] = i;
  }
}
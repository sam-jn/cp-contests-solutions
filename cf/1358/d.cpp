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
ll nsum[1000002];
void solve(){ 
    ll n, x;
    cin >> n >> x;
    vector<ll> a;
    for(int i = 0; i < n; i++){
        ll xx;
        cin >> xx;
        a.pb(xx);
    }
    for(int i = 0; i < n; i++){
        a.pb(a[i]);
    }
    int N = (int)a.size();
    vector<ll> asum(N), presum(N) = {0};
    for(int i = 0; i < N ;i++){
        asum[i] = nsum[a[i]];
    }
    presum[0] = a[0];
    for(int i = 1; i < N; i++){
        presum[i] = presum[i - 1] + asum[i];
    }
    for(int i = 0; i < N; i++){
        ll psum = 0;
        if(i > 0) psum = presum[i - 1];
        auto lb = lower_bound(presum.begin(), presum.end(), x + psum);
        if(lb == presum.end()){
            val[i] = -1;
        }
        else{
            int j = lb - presum.begin();
            ll curr1 = presum[j - 1], curr2;
            curr1 -= presum[i];

            ll left = x - dsum[j - 1] - dsum[i];
            // currr2 = nsum[a[j]];
            if(left - )

            ans = max(ans, );
        }
    }
    // cin >> m;
    // ll a[n];
    // in(a, n);
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
    for(int i = 1; i < 1000002; i++){
        nsum[i] = nsum[i - 1] + i;
    }
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
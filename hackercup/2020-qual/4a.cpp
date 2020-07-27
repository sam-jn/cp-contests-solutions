/* 
AUTHOR : @sam_jn
*/
//lo + 1, hi, ret lo
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
ll max(ll x, ll y, ll z) {return max(x, max(y, z));}
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {-1, 1, 0, 0, 1, -1, 1, -1};
//----------------------------------SOLUTION-BELOW-------------------------------------------// 

void solve(){
    ll n, m;
    cin >> n >> m;
    ll a[n], cost[n];
    in(a, n);
    set<pair<ll, ll>> st;
    for(ll i = 0; i < n; i++){
        cost[i] = LLONG_MAX;
        st.insert({cost[i], i});
    }
    for(ll i = 0; i <= min(n - 1, m); i++){
        st.erase({cost[i], i});
        cost[i] = 0;
        st.insert({cost[i], i});
    }
    for(ll i = 0; i < n; i++){
        if(a[i] != 0){
            if(st.size() == 0){
                cout << -1;
                return;
            }
            ll y = st.begin() -> ss;
            ll x = min(cost[min(n - 1, i + m)], cost[y] + a[i]);
            st.erase({cost[min(n - 1, i + m)], min(n - 1, i + m)});
            cost[min(n - 1, i + m)] = x;
            st.insert({cost[min(n - 1, i + m)], min(n - 1, i + m)});
            
        }
        st.erase({cost[i], i});
    }
    // cout << endl;
    // for(ll i = 0; i < n; i++){
    //     cout << cost[i] << " ";
    // }
    // cout << endl;
    // cout << INT_MAX << endl;
    if(cost[n - 1] == LLONG_MAX || cost[n - 1] < 0) cout << -1;
    else cout << cost[n - 1];
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
    for(int i = 1; i <= _; i++){
        cout << "Case #" << i << ": ";
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
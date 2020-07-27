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
int baap[320002];
int prime[NN];
int find(int i);  
bool Union(int x, int y);
ll inv(ll x) {return pwr(x, MOD - 2, MOD);}
void init();
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {-1, 1, 0, 0, 1, -1, 1, -1};
//----------------------------------SOLUTION-BELOW-------------------------------------------// 
// struct fun { 
//     bool operator()(pair<int, bitset<32>> const& p1, pair<int, bitset<32>> const& p2) 
//     { 
//         // return "true" if "p1" is ordered  
//         // before "p2", for example: 
//         return p1.ff > p2.ff; 
//     } 
// }; 
void solve(){
    ll n;
    cin >> n;
    ll a[n];
    in(a, n);
    bitset<32> b[n];
    priority_queue<pair<ll, ll>> pq;
    for(int i = 0; i < n; i++){
        bitset<32> bb(a[i]);
        b[i] = bb;
        pq.push({bb.count(), i});
    }
    ll ans = 0;
    if(n == 0){
        cout << 0;
        return;
    }
    if(n == 1){
        cout << pwr(a[0], 2);
        return;
    }
    while(true){
        auto x = pq.top();
        pq.pop();
        auto y = pq.top();
        pq.pop();
        ll xx = b[x.ss].to_ulong();
        ll yy = b[y.ss].to_ulong();
        ll prev = pwr(xx, 2) + pwr(yy, 2);
        ll aa = xx | yy;
        ll bb = xx & yy;
        ll curr = pwr(aa, 2) + pwr(bb, 2);
        bitset<32> b1(aa);
        bitset<32> b2(bb);
        b[x.ss] = b1;
        b[y.ss] = b2;
        pq.push({b1.count(), x.ss});
        pq.push({b2.count(), y.ss});
        if(curr <= prev) break;
    }
    while(!pq.empty()){
        auto xx = pq.top();
        pq.pop();
        ll val = pwr(b[xx.ss].to_ulong(), 2);
        ans += val;
    }
    cout << ans;
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
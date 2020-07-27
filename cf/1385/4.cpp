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
map<pair<int, int>, ll> freq[26];
string s;
int cnt[26][200000];
ll dp(int l, int r, char c){
    if(r - l == 0) return (s[l] != c);
    else if(freq[c - 'a'].count({l, r})){
        return freq[c - 'a'][{l, r}];
    }
    else{
        int l1 = l, r1 = (l + r) / 2;
        int l2 = r1 + 1, r2 = r;
        ll dp2 = dp(l2, r2, c + 1);
        ll dp1 = dp(l1, r1, c + 1);
        // ll val1 = 0, val2 = 0;
        ll val1 = (r1 - l1 + 1) - (cnt[c - 'a'][r1] - cnt[c - 'a'][l1 - 1]) + dp2;
        ll val2 = (r2 - l2 + 1) - (cnt[c - 'a'][r2] - cnt[c - 'a'][l2 - 1]) + dp1;
        return freq[c - 'a'][{l, r}] = min(val1, val2);
    }
}
void solve(){
    s = "";
    int n;
    // string s;
    cin >> n >> s;
    s = "$" + s;
    // cout << s;
    // return;

    for(int i = 0; i < 26; i++){
        freq[i].clear();
        for(int j = 0; j <= n; j++){
            cnt[i][j] = 0;
        }
    }
    // return;
    for(int i = 1; i <= n; i++){
        cnt[s[i] - 'a'][i]++;
    }
    // return;
    for(int i = 0; i < 26; i++){
        for(int j = 1; j <= n; j++){
            cnt[i][j] += cnt[i][j - 1];
        }
    }
    // return;
    cout << dp(1, n, 'a');
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
void init(){
  for(ll i = 2; i < NN; i++){
      if(prime[i]) continue;
      for(ll j = 2*i; j < NN; j += i)
          prime[j] = i;
  }
}
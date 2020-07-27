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
vector<int> adj[50];
int ans[50][50];
int visited[50];
void dfs(int u, int p){
    visited[u] = 1;
    ans[p][u] = 1;
    for(auto i : adj[u]){
        if(!visited[i]){
            dfs(i, p);
        }
    }
}
void solve(){
    int n;
    cin >> n;
    string arr, dep;
    // in(arr, n);
    // in(dep, n);
    cin >> arr >> dep;
    for(int i = 0; i < n; i++) adj[i].clear();
    for(int i = 0; i < n; i++){
        adj[i].pb(i);
        if(dep[i] == 'Y'){
            if(i - 1 >= 0){
                if(arr[i - 1] == 'Y'){
                    adj[i].pb(i - 1);
                }
            }
            if(i + 1 < n){
                if(arr[i + 1] == 'Y'){
                    adj[i].pb(i + 1);
                }
            }
        }
    }
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 50; j++){
            ans[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) visited[j] = 0;
        dfs(i, i);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ans[i][j] == 1) cout << "Y";
            else cout << "N";
        }
        cout << endl;
    }
    // cout << n;
}
int main(){


                                                            // #ifndef ONLINE_JUDGE    
                                                            // freopen("/home/samyak/Desktop/CP/input.txt", "r", stdin);
                                                            // freopen("/home/samyak/Desktop/CP/output2.txt", "w", stdout);
                                                            // #else
                                                            // // online submission
                                                            // #endif
// 

    boost
    int _ = 1;
    // cout << 0 << endl;
    cin >> _;
    for(int i = 1; i <= _; i++){
        cout << "Case #" << i << ":\n";
        solve();
        // cout << endl;
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
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
    ll n, m, ans = INT_MIN;
    cin >> m >> n;
    string mat[m];
    in(mat, m);
    ll time[m][n];
    set<pair<ll, pair<ll, ll>>> q;

    for(ll i = 0; i < m; i++){
        for(ll j = 0; j < n; j++){
            if(mat[i][j] != '_'){
                if(mat[i][j] == '0'){
                    q.insert({0, {i, j}});
                    time[i][j] = 0;
                }
                else{
                    q.insert({INT_MAX, {i, j}});
                    time[i][j] = INT_MAX;
                }
            }
        }
    }
    if(q.size() == 0){
        cout << 0;
        return;   
    }
    if((*q.begin()).ff != 0){
        cout << -1;
        return;
    }
    // for(auto i : q){
    //     cout << i.ff << " " << i.ss.ff << " " << i.ss.ss << endl;
    // }
    // return;
    while(q.size() > 0){
        auto top = *q.begin();
        q.erase(q.begin());
        auto u = top.ss;
        ll ui = u.ff, uj = u.ss, curr = top.ff;

        for(ll ii = 0, jj = 0; ii < 4; ii++, jj++){
            ll nexti = ui + dx[ii], nextj = uj + dy[jj];
            
            if(nexti >= 0 && nexti < m && nextj >= 0 && nextj < n){
                if(mat[nexti][nextj] != '_'){
                    ll val = (mat[nexti][nextj] == '1') ? 1 : 2;
                    if(curr + val < time[nexti][nextj]){
                        q.erase({time[nexti][nextj], {nexti, nextj}});
                        time[nexti][nextj] = curr + val;
                        q.insert({time[nexti][nextj], {nexti, nextj}});
                    }
                }
            }
        }
    }
    for(ll i = 0; i < m; i++){
        for(ll j = 0; j < n; j++){
            if(mat[i][j] != '_'){
                // cout << i << " " << j << " " << time[i][j] << endl;
                ans = max(ans, time[i][j]);
            }
        }
    }
    if(ans >= INT_MAX) cout << -1;
    else cout << ans;
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
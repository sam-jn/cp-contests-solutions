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
    ll n, m, ans = 0;
    cin >> n >> m;
    ll a[m], b[m];
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
    }
    // in(a, n);
    // in(b, n);
    int taken[m] = {0};
    vector<pair<ll, pair<ll,ll>>> v;
    v.clear();
    for(int i = 0; i < m; i++){
        v.push_back({a[i], {1, i}});
        v.push_back({b[i], {0, i}});
    }
    int cnt = 0;
    sort(v.begin(), v.end(), greater<pair<ll, pair<ll,ll>>>());
    // for(auto i : v){
    //     cout << i.ff << " " << i.ss.ff << " " << i.ss.ss << endl;
    // }
    for(auto i : v){
        if(cnt == n) break;
        if(i.ss.ff == 1){
            ans += i.ff;
            // cout << i.ff << "+ ";
            cnt++;
            taken[i.ss.ss] = 1;
        }
        else{
            if(i.ss.ff == 0){
                if(taken[i.ss.ss] == 1){
                    ans += (n -cnt) * i.ff;
                    // cout << i.ff << "++ ";
                    cnt = n;
                }
                else{
                    if(cnt == n - 1){
                        continue;
                    }
                    else{
                        ans += a[i.ss.ss];
                        cnt++;
                        // cout << a[i.ss.ss] << "+ ";
                        ans += (n - cnt) * i.ff;
                        cnt = n;
                        // cout << i.ff << "++ ";  
                    }
                }
            }
        }
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
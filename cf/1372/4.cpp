/* 
AUTHOR : @sam_jn
*/
//lo + 1, hi, ret lo
#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace tgnu_pbds;
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
    int t, _ = 1;
    // cout << 0 << endl;
    cin >> t;
    while(_ <= t){
        int n, ans = 0;
        cin >> n;
        int arr[n];
        in(arr, n);
        vector<int> a;
        // int dev = 0;
        for(int i = 0; i < n; i++){
            if(i == n - 1 || arr[i] != arr[i + 1]) a.pb(arr[i]);
        }
        // for(auto i : a) cout << i << " ";
        int m = a.size();
        // for(int i = 0; i < m; i++) cout << mark[i] << " ";
        int inc = 0;
        // vector<int> temp;
        // temp.pb(a[0]);
        int sz = 1;
        if(m > 1) {
            // temp.pb(a[1]);
            if(a[0] < a[1]) inc = 1;
            sz = 2;
        }
        for(int i = 2; i < m; i++){
            if((a[i] > a[i - 1] && inc == 1) || (a[i] < a[i - 1] && inc == 0)){
                sz++;
            }
            else{
                // ans++;
                if(sz % 4) sz = sz / 4 + 1;
                else sz /= 4;
                sz--;
                ans += sz;
                sz = 1;
                if(i == n - 1) break;
                else{
                    if(a[i + 1] > a[i]) inc = 1;
                    else inc = 0;
                }       
            }
        }
        if(sz % 4) sz = sz / 4 + 1;
        else sz /= 4;
        sz--;
        ans += sz;

        cout << "Case #" << _ << ": " << ans << endl;
        _++;
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
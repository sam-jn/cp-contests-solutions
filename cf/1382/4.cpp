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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> ans;
    int val[n], x = 0;
    for(int i = 0; i < n; i++) val[i] = -1;
    for(int i = n - 1; i >= 0; i -= 2){
        val[i] = x++;
    }
    int i = 0;
    if(val[i] != -1) i++;
    for(; i < n; i += 2){
        val[i] = x++;
    }
    // for(int i = 0; i < n; i++) cout << val[i] << " ";
    int rev_cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        char xx = s[val[i]];
        if(rev_cnt % 2){
            if(xx == '0') xx = '1';
            else xx = '0';
        }
        if(xx == t[i]){
            ans.pb(1);
            // if(s[0] == '0') s[0] = '1';
            // else s[0] = '0'; 
        }
        ans.pb(i + 1);
        rev_cnt++;
        // string str = s.substr(0, i + 1);
        // for(int j = 0; j < str.size(); j++){
        //     if(str[j] == '0') str[j] = '1';
        //     else str[j] = '0';
        // }
        // reverse(str.begin(), str.end());
        // s.replace(0, i + 1, str);
    }
    cout << ans.size() << " ";
    for(auto i : ans) cout << i << " ";
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
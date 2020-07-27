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
ll kadane(ll a[], ll l, ll r){
    ll max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = l; i < r; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far;
}
ll fun(ll a[], ll n, ll l, ll r){
    if(l > r) return 0;
    ll b[(r - l + 1) / 2], val = 0;
    for(ll i = 0; i < n; i++){
        if(i % 2 == 0){
            val += a[i];
        }
    }
    for(ll i = l + 1, j = 0; i <= r; i += 2, j++){
        b[j] = a[i] - a[i - 1];
    }
    ll ans = kadane(b, 0, (r - l + 1) / 2 );
    // cout << "-" << val << endl;
    if(ans == INT_MIN) ans = 0;
    return val + ans;
}
ll fun1(ll a[], ll n, ll l, ll r){
    if(l > r) return 0;
    ll b[(r - l + 1) / 2], val = 0;
    for(ll i = 0; i < n; i++){
        if(i % 2 == 0){
            val += a[i];
        }
    }
    for(ll i = l + 1, j = 0; i <= r; i += 2, j++){
        b[j] = a[i - 1] - a[i];
    }
    ll ans = kadane(b, 0, (r - l + 1) / 2 );
    // cout << "-" << val << endl;
    if(ans == INT_MIN) ans = 0;
    return val + ans;
}

void solve(){
    string s, t;
    cin >> s >> t;
    map<char, int> mpt, flag, freq;
    int cnt = 0, start = 0, ansl = -1, ansr = -1, ans = INT_MAX;
    for(int i = 0; i < t.size(); i++) mpt[t[i]]++;
    for(auto i : mpt){
        flag[i.first] = 0;
    }

    int i = 0, m = mpt.size();
    for(; i < s.size(); i++){
        if(!mpt.count(s[i])) continue;
        if(cnt < m){
            freq[s[i]]++;
            if(freq[s[i]] >= mpt[s[i]]){
                if(flag[s[i]] == 0){
                    cnt++;
                    flag[s[i]] = 1;
                }
            }
        }
        else{
            while(cnt >= m){
                if(i - start < ans){
                    ans = min(ans, i - start);
                    ansl = start;
                    ansr = i;
                }
                if(!mpt.count(s[start])){
                    start++;
                    continue;
                }
                freq[s[start]]--;
                if(freq[s[start]] < mpt[s[start]] && flag[s[start]] == 1){
                    flag[s[start]] = 0;
                    cnt--;
                }
                start++;
            }
        }
    }
    // i--;
    cout << ans << endl;
    while(cnt >= m){
        if(i - start < ans){
            ans = min(ans, i - start);
            ansl = start;
            ansr = i;
        }
        if(!mpt.count(s[start])){
            start++;
            continue;
        }
        freq[s[start]]--;
        if(freq[s[start]] < mpt[s[start]]){
            flag[s[start]] = 0;
            cnt--;
        }
        start++;
    }
    cout << ansl << endl;
    if(ans == INT_MAX){
        cout << "";
    }
    else{
        cout << s.substr(ansl, ans);
    }
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
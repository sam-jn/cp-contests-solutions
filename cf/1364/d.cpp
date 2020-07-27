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
map<int, int> val, lru;
int cap;
void LRUCache(int capacity) {
    lru.clear();
    val.clear();
    cap = capacity;
}
int get(int key) {
    if(lru.count(key) > 0) return val[key];
    else return -1;
}
void seter(int key, int value) {
    int mn = INT_MAX, mx = -1;
    // lru[mn] = INT_MAX;
    if(lru.size() == 0){
        lru[key] = 1;
        val[key] = value;
        return;
    }
    for(auto it : lru){
        if(mn == INT_MAX) mn = it.first;
        else if(it.second < lru[mn]){
            mn = it.first;
        }
        if(mx == -1) mx = it.first;
        else if(it.second > lru[mx]){
            mx = it.first;
        }
    }
    if(lru.count(key) == 0){
        if(lru.size() == cap){
            lru.erase(mn);
            val.erase(mn);
            if(lru.size() == 0) lru[key] = 1;
            else lru[key] = lru[mx] + 1;
            val[key] = value;
        }
        else{
            lru[key] = lru[mx] + 1;
            val[key] = value;
        }
    }
    else{
        lru[key] = lru[mx] + 1;
        val[key] = value;
    }
}
void debug(){
    cout << "LRU " << endl;
    for(auto it : lru){
        cout << it.ff << "=" << it.ss << " ";
    }
    cout << endl;
    cout << "VAL" << endl;
    for(auto it : val){
        cout << it.ff << "=" << it.ss << " ";
    }
    cout << endl;
    
}   
void solve(){
    int cap, n;
    cin >> n >> cap;
    LRUCache(cap);
    int x, y;
    char ch;
    for(int i = 0; i < n; i++){
        cin >> ch;
        if(ch == 'G'){
            cin >> x;
            cout << ch << " " << x << endl;
            cout << get(x) << endl;
            debug();
        }
        else{
            cin >> x >> y;
            cout << ch << " " << x << " " << y << endl;
            seter(x, y);
            debug();
        }
        cout << "--------------" << endl;
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
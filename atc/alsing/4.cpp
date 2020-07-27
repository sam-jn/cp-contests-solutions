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
ll max(ll x, ll y, ll z) {return max(x, max(y, z));}
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {-1, 1, 0, 0, 1, -1, 1, -1};
//----------------------------------SOLUTION-BELOW-------------------------------------------// 

void solve(){
    int n, popcount = 0, popcnt;
    string x;
    cin >> n >> x;
    for(int i = 0; i < n; i++) if(x[i] == '1') popcount++;
    popcnt = popcount;
    // cout << popcount;
    for(int i = 1; i < 2; i++){
        int moves = 0;
        string curr = x;
        if(x[i] == '0') curr[i] = '1', popcnt = popcount + 1;
        else curr[i] = '0', popcnt = popcount - 1;
        cout << curr << "\n";
        while(popcnt){
            moves++;
            int xx = curr.size();
            bitset<32> div(popcnt - 1);
            string divstr = div.to_string();
            reverse(divstr.begin(), divstr.end());
            // cout << divstr << " " << curr << "\n";
            reverse(curr.begin(), curr.end());
            cout << divstr << " " << curr << "\n";
            // div = bitset<32>(divstr);
            for(int j = 0; j < xx; j++){
                if(j < 32){               
                    if(div[j] == 0){
                        curr[j] = '0';
                        // cout << "+";
                    }
                }
                else curr[j] = '0';
            }
            reverse(curr.begin(), curr.end());
            
            cout << curr << "-" << endl;
            curr.erase(0, min(curr.find_first_not_of('0'), curr.size()-1));
            cout << "new : " << curr << endl;
            popcnt = 0;
            xx = curr.size();
            cout << xx << "-"<< endl;
            for(int j = 0; j < xx; j++) if(curr[j] != '0') popcnt++;
        }
        cout << moves <<"---"<< endl;
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
    bitset<3> bs("110");
    // cout << bs[1];
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
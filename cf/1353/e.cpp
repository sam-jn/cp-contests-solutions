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
#define in(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define ot1(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define ot2(a, n) for(int i = 0; i < n; i++) cout << a[i] << "\n";
ll pwr(ll a, ll b);
ll pwr(ll a, ll b, ll m);
int baap[200002];
int find(int i);  
bool Union(int x, int y);
ll inv(ll x) {return pwr(x, MOD - 2, MOD);}

//----------------------------------SOLUTION-BELOW-------------------------------------------// 
ll fun(string s, ll m){
    ll ans = LLONG_MAX;
    // reverse(s.begin(), s.end());
    
    // cout << s << endl;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '1'){
            if(i > 0){
                s = s.substr(i);
            }
            break;
        }
    }
    for(int i = (int)s.size() - 1; i >= 0; i--){
        if(s[i] == '1'){
            if(i < (int)s.size() - 1){
                s = s.substr(0, i + 1);
            }
            break;
        }
    }
    int n = s.size();
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != '0'){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        return 0;
        // return;
    }
    if(n == 1){
        return 0;
        // return;
    }
    vector<string> parts;
    int i = 0;
    int on[m] = {0}, off[m] = {0};
    while(true){
        string str = "";
        for(int j = 0; j < m; j++){
            if(i < n){
                str += s[i];
                i++;
            }
            else break;
        }
        if((int)str.size() > 0) parts.pb(str);
        if(i >= n) break;
    }
    // for(auto i : parts) cout << i << endl;
    for(auto str : parts){
        for(int j = 0; j < (int)str.size(); j++){
            if(str[j] == '0'){
                off[j]++;
            }
            else{
                on[j]++;
            }
        }
    }
    ll onsf[m] = {0}, onsb[m] = {0}, offsf[m] = {0}, offsb[m] = {0};
    onsf[0] = on[0];
    onsb[m - 1] = on[m - 1];
    offsf[0] = off[0];
    offsb[m - 1] = off[m - 1];
    for(int i = 1; i < m; i++){
        onsf[i] = onsf[i - 1] + on[i];
        offsf[i] = offsf[i - 1] + off[i];
    }
    for(int i = m - 2; i >= 0; i--){
        onsb[i] = onsb[i + 1] + on[i];
        offsb[i] = offsb[i + 1] + off[i];
    }
    // for(auto i : on) cout << i << " ";
    //     cout << endl;
    for(int i = 0; i < m; i++){
        if(i == 0){
            ans = min(ans, (ll)(off[i] + onsb[1]));
        }
        else if(i == m - 1){
            ans = min(ans, (ll)(off[i] + onsf[m - 2]));
        }
        else ans = min(ans, (ll)(off[i] + onsf[i - 1] + onsb[i + 1]));
    }
    return ans;
}
void solve(){ 
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '1'){
            if(i > 0){
                s = s.substr(i);
            }
            break;
        }
    }
    for(int i = (int)s.size() - 1; i >= 0; i--){
        if(s[i] == '1'){
            if(i < (int)s.size() - 1){
                s = s.substr(0, i + 1);
            }
            break;
        }
    }
    n = (int)s.size();
    if(n == 1){
        cout << 0;
        return;
        // return;
    }
    ll ans2 = LLONG_MAX, ans3 = LLONG_MAX;
    if(s[(int)s.size() - 1] == '1') ans3 = 1 + fun(s.substr(0, (int)s.size() - 1), m);
    if(s[0] == '1') ans2 = 1 + fun(s.substr(1), m);

    cout << min(fun(s, m), min(ans2, ans3));
    // cout << fun("0100", 2);
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
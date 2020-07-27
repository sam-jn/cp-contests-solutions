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
int fun(string s, int i, int j, int black[]){
    int x = black[i] - black[i - j];
    return (x * (j - x));
}
int solve(string s, int k){   
    int n = s.size();
    s = '$' + s;
    // cout << s;
    int dp[n + 1][k + 1] = {0}, black[n + 1] = {0};
    for(int i = 0; i <= n; i++) for(int j = 0; j <= k; j++) dp[i][j] = 00;

    for(int i = 1; i <= n; i++){
        if(s[i] == 'B') black[i] = black[i - 1] + 1;
        else black[i] = black[i - 1];
    }
    // cout << fun(s, 2, 2, black);
    // for(int i = 1; i <= n; i++) cout << black[i] << " ";
    //     cout << endl;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= min(i, k); j++){
            if(j == 1){
                dp[i][j] = fun(s, i, i, black);
            }
            else{
                dp[i][j] = 150;
                for(int k = 1; k <= i - j + 1; k++){
                    dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + fun(s, i, k, black));
                }
            }
        }
    }
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= k; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[n][k];
}
int main(){


                                                            #ifndef ONLINE_JUDGE    
                                                            freopen("/home/samyak/Desktop/CP/input.txt", "r", stdin);
                                                            freopen("/home/samyak/Desktop/CP/output2.txt", "w", stdout);
                                                            #else
                                                            // online submission
                                                            #endif


    boost
    int _ = 1;
    // cout << 0 << endl;
    // cin >> _;
    while(_--){
        cout << solve("WBWB", 2);
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
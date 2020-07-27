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
#define ot(a, n) for(int i = 0; i < n; i++) cout << a[i] << " ";
#define ot2(a, n) for(int i = 0; i < n; i++) cout << a[i] << "\n";
ll pwr(ll a, ll b);
ll pwr(ll a, ll b, ll m);
int baap[200002];
int find(int i);  
bool Union(int x, int y);
ll inv(ll x) {return pwr(x, MOD - 2, MOD);}

//----------------------------------SOLUTION-BELOW-------------------------------------------// 
stack<int> s;
bool visited[500005] = {0};
bool visited2[500005] = {0};
bool rec[500005] = {0};

vector<int> adj[500005];

bool dfs2(int u, int p){
    if(!visited2[u]){
        visited2[u] = 1;
        rec[u] = 1;
        for(auto v : adj[u]){
            if(!visited2[v] && dfs2(v, u)) return true;
            else if(rec[v]) return true;
        }
    }
    rec[u] = 0;
    return false;
}

void dfs(int u, int p){
    visited[u] = 1;
    for(auto v : adj[u]){
        if(!visited[v] && v != p){
            dfs(v, u);
        }
    }
    s.push(u);
}
void solve(){
    int n, m, x, y;
    cin >> n >> m;
    int val[n + 1] = {0};
    vector<pair<int, int>> edges;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        edges.pb({x, y});
    }
    for(int i = 0; i < n; i++){
        cin >> x;
        val[i + 1] = x;
    }
    // for(int i = 1; i <= n; i++) cout << val[i] << " ";
    // return;
    for(auto i : edges){
        if(val[i.ff] == val[i.ss]){
            cout << -1;
            return;
        }
        else if(val[i.ff] < val[i.ss]){
            adj[i.ss].pb(i.ff);
        }
        else{
            adj[i.ff].pb(i.ss);   
        }
    }
    // return;
    for(int i = 1; i <= n; i++){
        if(!visited2[i]){
            if(!dfs2(i, i)){

            }
            else{
                cout << -1;
                return;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i, i);
        }
    }
    vector<int> ans;
    while(!s.empty()){
        ans.pb(s.top());
        s.pop();
    }
    reverse(ans.begin(), ans.end());
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
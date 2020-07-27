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
int d1[4] = {1, -1, 0, 0};
int d2[4] = {0, 0, -1, 1};
//----------------------------------SOLUTION-BELOW-------------------------------------------// 

void solve(){
    int n, m;
    cin >> n >> m;
    char mat[n][m];
    bool visited[n][m] = {0};
    int flag = 1;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> mat[i][j], visited[i][j] = 0;
    // int sum[n][m] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 'B'){
                int flag1 = 1;
                for(int k = 0; k < 4; k++){
                    int r = i + d1[k], c = j + d2[k];
                    if(r < n && c < m && r >= 0 && c >= 0){
                        if(mat[r][c] == 'G'){
                            flag1 = 0;
                        }
                        if(mat[r][c] == '.'){
                            mat[r][c] = '#';
                        }
                    }
                }
                if(!flag1){
                    flag = 0;
                    break;
                }
            }
        }
        if(!flag) break;
    }
    if(!flag){
        cout << "No";
        return;
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << mat[i][j] << " ";

    //     }
    //     cout << endl;
    // }
    queue<pair<int, int>> q;

    if(mat[n - 1][m - 1] != '#') q.push({n - 1, m - 1});
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        int ii = x.ff, jj = x.ss;
        for(int i = 0; i < 4; i++){
            int r = ii + d1[i], c = jj + d2[i];
            if(r < n && c < m && r >= 0 && c >= 0){
                if(mat[r][c] != '#'){
                    if(!visited[r][c]){ 
                        q.push({r, c});
                        visited[r][c] = 1;
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        if(mat[i][j] == 'G'){
            if(visited[i][j] == 0){
                flag = 0;
                cout << "No";
                return;
            }
        }
    }
    cout << "Yes";
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
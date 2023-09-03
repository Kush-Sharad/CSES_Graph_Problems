#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int vis[1010][1010];
void dfs(vector<vector<char>>& v, int i, int j, int n, int m){
    if(i<0 || j<0 || i>=n || j>=m || v[i][j]=='#')return;
    vis[i][j]=1;
    if(!vis[i+1][j])dfs(v,i+1,j,n,m);
    if(!vis[i-1][j])dfs(v,i-1,j,n,m);
    if(!vis[i][j+1])dfs(v,i,j+1,n,m);
    if(!vis[i][j-1])dfs(v,i,j-1,n,m);
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> a(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)cin>>a[i][j];
    }
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]=='.' && !vis[i][j]){
                dfs(a,i,j,n,m);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
int32_t main(){
    solve();
}

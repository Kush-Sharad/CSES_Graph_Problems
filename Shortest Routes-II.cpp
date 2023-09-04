#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> v(n+1,vector<int>(n+1,1e18));
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a][a]=0;
        v[b][b]=0;
        v[a][b]=min(v[a][b],c);
        v[b][a]=min(v[b][a],c);
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                v[i][j]=min(v[i][j], v[i][k]+v[k][j]);
            }
        }
    }
    for(int i=0; i<q; i++){
        int x,y;
        cin>>x>>y;
        if(v[x][y]==1e18)cout<<-1<<endl;
        else cout<<v[x][y]<<endl;
    }
}
int32_t main(){
    solve();
}

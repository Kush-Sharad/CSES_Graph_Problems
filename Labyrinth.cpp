#include <bits/stdc++.h>
using namespace std;
#define int long long
char par[1000][1000], ans[1000000];
int dist[1000][1000];
bool vis[1000][1000];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void solve(){
    int n, m;
    cin>>n>>m;
    char a[n][m];
    int s1=0,s2=0,e1=0,e2=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            if(a[i][j]=='A'){
                s1=i; s2=j;
            }
            if(a[i][j]=='B'){
                e1=i; e2=j;
            }
            if(a[i][j]=='#')vis[i][j]=true;
        }
    }
    queue<pair<int,int>> q;
    q.push({s1,s2});
    vis[s1][s2]=true;
    while(!q.empty()){
        int u=q.front().first;
        int v=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int x=u+dx[i];
            int y=v+dy[i];
            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y]){
                dist[x][y]=dist[u][v]+1;
                if(i==0)par[x][y]='D';
                if(i==1)par[x][y]='U';
                if(i==2)par[x][y]='R';
                if(i==3)par[x][y]='L';
                q.push({x,y});
                vis[x][y]=true;
            }
        }
    }
    if(!vis[e1][e2]){
        cout<<"NO"<<endl; return;
    }
    cout<<"YES"<<endl;
    int len=dist[e1][e2];
    cout<<len<<endl;
    for(int i=len; i>0; i--){
        ans[i]=par[e1][e2];
        if(ans[i]=='D')e1--;
        if(ans[i]=='U')e1++;
        if(ans[i]=='R')e2--;
        if(ans[i]=='L')e2++;
    }
    for(int i=1; i<=len; i++)cout<<ans[i];
    cout<<endl;
}
int32_t main(){
    solve();
}

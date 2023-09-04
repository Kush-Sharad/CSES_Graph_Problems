#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m;
    cin>>n>>m;
    map<int,vector<pair<int,int>>> mp;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        mp[a].push_back({b,c});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n+1,INT64_MAX);
    vector<int> vis(n+1,0);
    pq.push({0,1});    // source is 1
    dist[1]=0;
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto it:mp[u]){
            int v=it.first;
            int w=it.second;
            if(dist[u]!=INT64_MAX && dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    for(int i=1; i<n+1; i++){
        if(dist[i]==INT64_MAX)cout<<-1<<" ";
        else cout<<dist[i]<<" ";
    }
    cout<<endl;
}
int32_t main(){
    int T=1;
   // cin>>T;
    while(T--){
        solve();
    }
}

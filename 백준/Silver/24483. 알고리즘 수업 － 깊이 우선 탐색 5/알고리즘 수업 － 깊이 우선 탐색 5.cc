#include <bits/stdc++.h>
using namespace std;
int vis[100001];
long order[100001][2];
vector<int> arr[100001];
int cnt=1;
int n,m,r;
void dfs(int r,int depth) {
    
    vis[r]=1;
    order[r][0]=depth;
    order[r][1]=cnt;
    cnt++;
    for (int s:arr[r]) {
        if(vis[s]==1) continue;
        dfs(s,depth+1);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>r;
    for(int i=1;i<=n;i++) {
        order[i][0]=-1;
    }

    
    
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        sort(arr[i].begin(),arr[i].end());
    }
    dfs(r,0);
    long long ans=0;
    for(int i=1;i<=n;i++) {
        ans+=order[i][0]*order[i][1];
    }
    cout<<ans;
}
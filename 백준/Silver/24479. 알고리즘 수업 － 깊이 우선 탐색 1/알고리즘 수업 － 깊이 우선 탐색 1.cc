#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> g[100001];
int dis[100001];
int cnt=1;
void dfs(int r) {
    
    for(int i=0;i<g[r].size();i++) {
        if(!dis[g[r][i]]) {
            cnt++;
            dis[g[r][i]]=cnt;
            dfs(g[r][i]);
            
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,r;
    cin>>n>>m>>r;
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        sort(g[i].begin(),g[i].end());
    }
    
    dis[r]=cnt;
    dfs(r);
    for(int i=1;i<=n;i++) {
        cout<<dis[i]<<'\n';
    }
}
#include <bits/stdc++.h>
using namespace std;
queue<int> q;
vector<int> res;
int deg[32001];
vector<int> adj[32001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        deg[v]++;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++) 
        if(deg[i]==0)q.push(i);
    while(!q.empty()) {
        int cur=q.front();
        q.pop();
        res.push_back(cur);
        for(int nxt:adj[cur]) {
            deg[nxt]--;
            if(deg[nxt]==0) q.push(nxt);
        }
    }
    for(int s:res)
        cout<<s<<' ';
}
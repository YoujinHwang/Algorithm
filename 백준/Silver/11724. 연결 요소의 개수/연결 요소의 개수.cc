#include <bits/stdc++.h>
using namespace std;
vector<int> ve[1001];
bool vis[1001];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    int cnt=0;
    cin>>n>>m;
    while(m--) {
        int u,v;
        cin>>u>>v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        queue<int> q;
        if(!vis[i]) {
            q.push(i);
            vis[i]=true;
            cnt++;
        }
        while(!q.empty()) {
            int cur=q.front();
            q.pop();
            for(auto nxt:ve[cur]) {
                if(!vis[nxt]) {
                    q.push(nxt);
                    vis[nxt]=true;
                }
            }
        }
    }
    cout<<cnt<<'\n';
}
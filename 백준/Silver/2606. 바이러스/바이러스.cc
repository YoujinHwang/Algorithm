#include <bits/stdc++.h>
using namespace std;
vector<int> ve[101];
queue<int> q;
bool vis[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int cnt=0;
    while(m--) {
        int u,v;
        cin>>u>>v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    q.push(1);
    vis[1]=true;
    while(!q.empty()) {
        int cur=q.front();
        q.pop();
        for(int a:ve[cur]) {
            if(!vis[a]){
                q.push(a);
                vis[a]=true;
                cnt++;
            }
        }
    }
    cout<<cnt<<'\n';
}
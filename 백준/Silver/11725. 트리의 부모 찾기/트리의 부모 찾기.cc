#include <bits/stdc++.h>
using namespace std;
vector<int> ve[100001];
queue<int> q;
int p[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    q.push(1);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(auto s:ve[cur]) {
            if(s==p[cur]) continue;
            q.push(s);
            p[s]=cur;
        }
    }
    for(int i=2;i<=n;i++) {
        cout<<p[i]<<'\n';
    }
}
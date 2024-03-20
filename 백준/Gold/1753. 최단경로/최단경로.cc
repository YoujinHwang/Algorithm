#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int v,e,st;

vector<pair<int,int>> adj[20001];
const int INF=INT_MAX;
int d[20001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v,e,k;
    cin>>v>>e>>k;
    fill(d,d+v+1,INF);
    while(e--) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }
    priority_queue<pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> pq;
    d[k]=0;
    pq.push({0,k});
    while(!pq.empty()) {
        auto cur=pq.top();
        pq.pop();
        if(d[cur.Y]!=cur.X) continue; //주의
        for(auto s:adj[cur.Y]) {
            if(d[s.Y]<=d[cur.Y]+s.X) continue;
            d[s.Y]=d[cur.Y]+s.X; //주의
            pq.push({d[s.Y],s.Y});
        }
    }
    for(int i=1;i<=v;i++) {
        if(d[i]==INF) cout<<"INF\n";
        else cout<<d[i]<<'\n';
    }
    



}
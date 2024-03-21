#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[1001];
int path[1001];
int d[1001];
#define X first
#define Y second
const int INF=1e9+10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    while(m--) {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({c,v});
    }
    int st,end;
    cin>>st>>end;
    fill(d,d+n+1,INF);
    d[st]=0;
    priority_queue<pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>> pq;
    pq.push({0,st});
    while(!pq.empty()) {
        auto cur=pq.top();
        pq.pop();
        if(d[cur.Y]!=cur.X) continue;
        for(auto nxt:adj[cur.Y]) {
            if(d[nxt.Y]>d[cur.Y]+nxt.X) {
                d[nxt.Y]=d[cur.Y]+nxt.X;
                path[nxt.Y]=cur.Y;
                pq.push({d[nxt.Y],nxt.Y});
            }    
        }
    }
    cout<<d[end]<<'\n';
    stack<int> ss;
    int x=end;
    while(x!=st) {
        ss.push(x);
        x=path[x];
    }
    ss.push(st);
    cout<<ss.size()<<'\n';
    while(!ss.empty()) {
        cout<<ss.top()<<' ';
        ss.pop();
    }

}
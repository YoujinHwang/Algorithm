#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, t;
int s, g, h;
struct Edge {
    int num;
    int d;
    bool operator<(Edge right)const {
        if (d < right.d) return false;
        if (d > right.d) return true;
        return false;
    }
};
int dist[2001];
int h_g_dest[2001];
int g_h_dest[2001];

vector<Edge> v[2001];
vector<int> dest;


void dijkstra(int start,int dist[2001]) {
    priority_queue<Edge> pq;
    pq.push({start,0});
    
    for(int i=1;i<=n;i++) dist[i]=21e8;
    dist[start]=0;
    while(!pq.empty()) {
        Edge cur=pq.top();
        pq.pop();
        if(dist[cur.num]<cur.d) continue;
        for(int i=0;i<v[cur.num].size();i++) {
            Edge next=v[cur.num][i];
            int nextcost=dist[cur.num]+next.d;
            if(dist[next.num]<=nextcost) continue;
            dist[next.num]=nextcost;
            pq.push({next.num,nextcost});
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        int must; //꼭 지나는 간선 거리
        for(int j=1;j<=n;j++) v[j].clear(); //초기화 꼭 해주기!!!

        for (int j = 0; j < m; j++) {
            int a, b, d;
            cin >> a >> b >> d;
            v[a].push_back({ b,d });
            v[b].push_back({ a,d });
            if((a==g&&b==h)||(a==h&&b==g)) {
                must=d;
            }
        }
        dest.clear(); //꼭 해주기 
        for (int j = 0; j < t; j++) {
            int x;
            cin>>x;
            dest.push_back(x);
            // isPos[x]=false;
        }
        sort(dest.begin(),dest.end());

        dijkstra(s,dist);
        int gDist=dist[g];
        int hDist=dist[h];
        vector<int> Min, Min_g, Min_h;
        for(auto tmp:dest) {
            Min.push_back(dist[tmp]); //각 목적지까지의 최단경로
        }
        dijkstra(g,dist);
        for(auto tmp:dest) {
            Min_g.push_back(dist[tmp]); //g~각 목적지까지의 최단경로
        }
        dijkstra(h,dist);
        for(auto tmp:dest) {
            Min_h.push_back(dist[tmp]); //h~각 목적지까지의 최단경로
        }
        vector<int> ans;
        for(int j=0;j<Min.size();j++) {
            
            int a1=hDist+must+Min_g[j]; //s h g tmp
            
            int a2=gDist+must+Min_h[j]; //s g h tmp
            if(Min[j]==a1||Min[j]==a2) {
                ans.push_back(dest[j]);
            }

        }
        for(auto aa:ans) cout<<aa<<' ';
        cout<<"\n";
        
    }

    // for(int i=1;i<=n;i++) cout<<dist[i]<<' ';
}
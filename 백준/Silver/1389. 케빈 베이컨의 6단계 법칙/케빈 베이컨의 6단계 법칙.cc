#include <bits/stdc++.h>
using namespace std;
#include <unordered_set>
unordered_set<int> fri[101];
int num[101][101];
bool vis[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    while(m--) {
        int u,v;
        cin>>u>>v;
        fri[u].insert(v);
        fri[v].insert(u);

    }
    

    for(int i=1;i<=n;i++) {
        
        queue<int> q;
        q.push(i);
        
        while(!q.empty()) {
            int cur=q.front();
            q.pop();
            
            for(auto s:fri[cur]) {
                if (!vis[i][s]&&s!=i) {
                    q.push(s);
                    num[i][s]=num[i][cur]+1;
                    vis[i][s]=true;
                    num[s][i]=num[i][s];
                    
                }
            }
        }
        
    }

    int Min=INT_MAX;
    int ans=0;
    for(int i=1;i<=n;i++) {
        int sum=0;
        for(int j=1;j<=n;j++) {
            sum+=num[i][j];
        }
        if(sum<Min) {
            Min=sum;
            ans=i;
        }
    }
    cout<<ans<<'\n';
}
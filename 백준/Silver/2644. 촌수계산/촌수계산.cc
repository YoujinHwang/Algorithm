#include <vector>
#include <iostream>
#include <queue>
using namespace std;
vector<int> arr[101];
int vis[101];
queue<int> q;

void bfs(int a,int b) {
    q.push(a);
    while(!q.empty()) {
        int x=q.front();
        q.pop();
        for(int i=0;i<arr[x].size();i++) {
            if(!vis[arr[x][i]]) {
                q.push(arr[x][i]);
                vis[arr[x][i]]=vis[x]+1;
                if(arr[x][i]==b) {
                    cout<<vis[b]<<'\n';
                    return;
                }
            }
        }
    }
    cout<<"-1";
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    int a,b;
    cin>>n;
    cin>>a>>b;
    cin>>m;
    int x,y;
    for(int i=0;i<m;i++) {
        cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    bfs(a,b);
}
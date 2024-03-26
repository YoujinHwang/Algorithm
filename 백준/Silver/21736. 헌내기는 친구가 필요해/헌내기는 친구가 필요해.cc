#include <iostream>
#include <queue>
using namespace std;
string ss[600];
bool vis[600][600];
#define X first
#define Y second
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
queue<pair<int,int>> q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>ss[i];
    }
    bool find=false;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(ss[i][j]=='I') {
                q.push({i,j});
                find=true;
                break;
            }
                
        }
        if(find) break;
    }
    int cnt=0;
    while(!q.empty()) {
        pair<int,int> cur=q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int nx=cur.X+dx[i];
            int ny=cur.Y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(!vis[nx][ny]) {
                if(ss[nx][ny]=='P'||ss[nx][ny]=='O') {
                    if(ss[nx][ny]=='P') cnt++;
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
            
        }
    }
    if(cnt==0) cout<<"TT";
    else cout<<cnt;
}
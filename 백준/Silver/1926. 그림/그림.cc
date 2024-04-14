#include <iostream>
#include <queue>
using namespace std;
int arr[500][500];
bool vis[500][500];
queue<pair<int,int>> q;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    int num=0;
    int mx=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int tmp=0;
            if(arr[i][j]&&!vis[i][j]) {
                tmp++;
                q.push({i,j});
                vis[i][j]=1;
                num++;
            }
            while(!q.empty()) {
                pair<int,int> cur=q.front();
                q.pop();
                for(int x=0;x<4;x++) {
                    int nx=cur.X+dx[x];
                    int ny=cur.Y+dy[x];
                    if(nx<0||ny<0||nx>=n||ny>=m) continue;
                    if(!vis[nx][ny]&&arr[nx][ny]) {
                        q.push({nx,ny});
                        vis[nx][ny]=1;
                        tmp++;
                    }
                }
            }
            mx=max(mx, tmp);
        }
    }
    cout<<num<<'\n'<<mx;
}
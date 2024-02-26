#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string mm[1000];
int dis[1000][1000][2];
queue<tuple<int,int,int>> q;
#define X first
#define Y second
int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    for(int i=0;i<n;i++) 
        for(int j=0;j<m;j++) 
            dis[i][j][0]=dis[i][j][1]=-1;
    for (int i = 0; i < n; i++)
    {
        cin >> mm[i];
    }
    q.push({0,0,0});
    dis[0][0][0]=1;
    dis[0][0][1]=1;
    while(!q.empty()) {
        int x,y,z;
        tie(x,y,z)=q.front();
        if(x==n-1&&y==m-1) {
            cout<<dis[n-1][m-1][z]<<'\n';
            return 0;
        }
        q.pop();
        int nxtdis=dis[x][y][z]+1;
        for(int i=0;i<4;i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(mm[nx][ny]=='0'&&dis[nx][ny][z]==-1) {
                q.push({nx,ny,z});
                dis[nx][ny][z]=nxtdis;
            }  
            else if(mm[nx][ny]=='1'&&!z&&dis[nx][ny][1]==-1) {
                q.push({nx,ny,1});
                dis[nx][ny][1]=nxtdis;
            }                                                                                                                                                                     
        }
    }
    cout<<-1<<'\n';
}
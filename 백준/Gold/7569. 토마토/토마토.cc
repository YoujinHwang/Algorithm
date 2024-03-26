#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int arr[101][101][101];
int time[101][101][101];
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
queue<tuple<int,int,int>> ripe;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool done=true;
    int m,n,h;
    cin>>m>>n>>h;
    for(int z=0;z<h;z++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>arr[i][j][z];
                if(arr[i][j][z]==1) ripe.push({i,j,z});
                else if(arr[i][j][z]==0) done=false;
            }
        }
    }
    if(done) {
        cout<<0;
        return 0;
    }
    while(!ripe.empty()) {
        tuple<int,int,int> cur=ripe.front();
        ripe.pop();
        int x=get<0>(cur);
        int y=get<1>(cur);
        int z=get<2>(cur);

        for(int i=0;i<6;i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nz=z+dz[i];
            if(nx<0||nx>=n||ny<0||ny>=m||nz<0||nz>=h) continue;
            if(!arr[nx][ny][nz]) {
                arr[nx][ny][nz]=arr[x][y][z]+1;
                ripe.push({nx,ny,nz});
            }
        }
    }
    int Max=0;
     for(int z=0;z<h;z++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!arr[i][j][z]) {
                    cout<<-1;
                    return 0;
                }
                Max=max(Max,arr[i][j][z]);
            }
        }
     }
     cout<<Max-1;
}
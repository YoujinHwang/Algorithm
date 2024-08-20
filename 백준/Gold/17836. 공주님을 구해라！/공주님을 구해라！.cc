#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
#define Y first 
#define X second
using namespace std;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int N,M,T;
int arr[101][101];
int dist[100][100];
int dist2[100][100];
pair<int,int> gram;
bool haveGram=false;
void bfs(int y,int x,int dist[100][100]) {
    queue<pair<int,int>> q;
    q.push({y,x});
    dist[y][x]=1;

    while(!q.empty()) {
        pair<int,int> cur=q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int ny=cur.Y+dy[i];
            int nx=cur.X+dx[i];
            if(ny<0||ny>=N||nx<0||nx>=M) continue;
            if(arr[ny][nx]==1&&!haveGram) continue;
            if(dist[ny][nx]!=0) continue;
            q.push({ny,nx});
            dist[ny][nx]=dist[cur.Y][cur.X]+1; 
        }
    }
}
int bfs_to_gram() {
    queue<pair<int,int>> q;
    q.push({0,0});
    dist2[0][0]=1;

    while(!q.empty()) {
        pair<int,int> cur=q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int ny=cur.Y+dy[i];
            int nx=cur.X+dx[i];
            if(ny<0||ny>=N||nx<0||nx>=M) continue;
            if(arr[ny][nx]==1) continue; 
            if(dist2[ny][nx]!=0) continue;
            q.push({ny,nx});
            dist2[ny][nx]=dist2[cur.Y][cur.X]+1; 
            if(arr[ny][nx]==2) return dist2[ny][nx]-1;
        }
    }
    return -1;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>T;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin>>arr[i][j];

            if(arr[i][j]==2) gram={i,j};
        }
    }
    bfs(0,0,dist);
    int ans=dist[N-1][M-1]-1;
    if(ans==-1) ans=INT_MAX;
    
    // cout<<dist[N-1][M-1]-1<<'\n';
    int pos=bfs_to_gram(); //그람을 찾기까지 걸리는 최단거리
    // cout<<pos<<'\n';
    if(pos!=-1) { //그람을 얻을 수 있는 경우
        memset(dist2,0,sizeof(dist2));
        dist2[gram.Y][gram.X]=pos;
        haveGram=true;
        bfs(gram.Y,gram.X,dist2);
        ans=min(ans,dist2[N-1][M-1]-1+pos);
    }
    if(ans<=T) cout<<ans;
    else cout<<"Fail";
    // if(dist[N-1][M-1]==0||dist[N-1][M-1]-1>=T) 
    // cout<<gram.Y<<' '<<gram.X;
}
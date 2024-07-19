#include<vector>
#include <queue>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
#define X first
#define Y second
int vis[101][101];

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n=maps.size();
    int m=maps[0].size();
    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0]=1;
    while(!q.empty()) {
        pair<int,int> cur=q.front();
        q.pop();
        
        for(int i=0;i<4;i++) {
            int nx=cur.X+dx[i];
            int ny=cur.Y+dy[i];
            
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(maps[nx][ny]==0) continue; //위치 중요! 바로 윗줄이랑 순서바꼈다가 몇 개의 테스트케이스에서 segmentation fault 남
            if(vis[nx][ny]!=0) continue;
            q.push({nx,ny});
            vis[nx][ny]=vis[cur.X][cur.Y]+1;
            if(nx==n-1&&ny==m-1) {
                answer=vis[nx][ny];
                return answer;
            }
        }
    }
    answer=-1;
    
    
    return answer;
}
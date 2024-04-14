#include <string>
#include <vector>
#include <queue>

using namespace std;
pair<int,int> rob;
pair<int,int> goal;
queue<pair<int,int>> q;
#define X first
#define Y second
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int vis[100][100];
int n,m;

int bfs(vector<string> board) {
    vis[rob.X][rob.Y]++;
    q.push(rob);
    while(!q.empty()) {
        pair<int,int> cur=q.front();
        q.pop();
       
        for(int i=0;i<4;i++) {
            int nx=cur.X;
            int ny=cur.Y;
            while(1) {
                nx+=dx[i];
                ny+=dy[i];
                if(nx<0||ny<0||nx>=n||ny>=m||board[nx][ny]=='D') {
                    nx-=dx[i];
                    ny-=dy[i];
                    if(vis[nx][ny]==-1) {
                        q.push({nx,ny});
                        vis[nx][ny]=vis[cur.X][cur.Y]+1;
                        if(board[nx][ny]=='G') return vis[nx][ny]; //이 조건문의 위치가 고민됐음. q.pop() 할 때 찾는게 나을지..등
                    }
                    break;
                } 
            }
        
        }
    }
    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    n=board.size();
    m=board[0].size();
    char arr[n][m];
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(board[i][j]=='R') rob={i,j};
            else if(board[i][j]=='G') goal={i,j};
        }
    }
//     for(int i=0;i<n;i++) {
//         for(int j=0;j<m;j++) {
//             vis[i][j]=-1;
         
//         }
//     }
    for(int i=0;i<n;i++) {
        fill(vis[i],vis[i]+m,-1);
    }
    answer=bfs(board);
    
    return answer;
}
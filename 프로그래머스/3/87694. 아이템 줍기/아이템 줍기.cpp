// #include <string>
// #include <vector>
// #include <queue>
// #include <iostream>
// using namespace std;
// int map[51][51];
// int vis[51][51];
// int dx[4]={1,-1,0,0};
// int dy[4]={0,0,1,-1};
// #define X first
// #define Y second

// int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
//     int answer = 0;
//     int n=rectangle.size();
//     // int min_y=rectangle[0][1];
//     // int min_x=rectangle[0][0];
//     // int max_x=rectangle[0][2];
//     // int max_y=rectangle[0][3];
//     for(int i=0;i<n;i++) {
//         // min_y=min(rectangle[i][1],min_y);
//         // min_x=min(rectangle[i][0],min_x);
//         // max_x=max(rectangle[i][2],max_x);
//         // max_y=max(rectangle[i][3],max_y);
        
//         for(int x=rectangle[i][0];x<=rectangle[i][2];x++) { //직사각형의 아랫변
//             for(int j=0;j<n;j++) {
//                 if(i==j) continue;
//                 int y=rectangle[i][1]; //직사각형의 아랫변의 y좌표
//                 if(x>rectangle[j][0]&&x<rectangle[j][2]&&y>rectangle[j][1]&&y<rectangle[j][3]) continue;
//                 map[x][y]=1;
//             }
//         }
        
//         for(int y=rectangle[i][1];y<=rectangle[i][3];y++) { //직사각형의 오른쪽변
//             for(int j=0;j<n;j++) {
//                 if(i==j) continue;
//                 int x=rectangle[i][2]; //직사각형의 오른쪽변의 x 좌표
//                 if(y>rectangle[j][1]&&y<rectangle[j][3]&&x>rectangle[j][0]&&x<rectangle[j][2]) continue;
//                 map[x][y]=1;
//             }
//         }
       
//         for(int x=rectangle[i][0];x<=rectangle[i][2];x++) { //직사각형의 위쪽변
//             for(int j=0;j<n;j++) {
//                 if(i==j) continue;
//                 int y=rectangle[i][3]; //직사각형의 위쪽변의 y 좌표
//                 if(y>rectangle[j][1]&&y<rectangle[j][3]&&x>rectangle[j][0]&&x<rectangle[j][2]) continue;
//                 map[x][y]=1;
//             }
//         }
        
//         for(int y=rectangle[i][1];y<=rectangle[i][3];y++) { //직사각형의 왼쪽변
//             for(int j=0;j<n;j++) {
//                 if(i==j) continue;
//                 int x=rectangle[i][0]; //직사각형의 왼쪽변의 x 좌표
//                 if(y>rectangle[j][1]&&y<rectangle[j][3]&&x>rectangle[j][0]&&x<rectangle[j][2]) continue;
//                 map[x][y]=1;
//             }
//         }
        
//     }
//     for(int i=0;i<51;i++) {
//         for(int j=0;j<51;j++) {
//             cout<<map[i][j];
//         }
//     }
//     queue<pair<int,int>> q;
//     q.push({characterX, characterY});
//     vis[characterX][characterY]=1;
    
//     while(!q.empty()){
//         pair<int,int> cur=q.front();
//         q.pop();
//         for(int i=0;i<4;i++) {
//             int nx=cur.X+dx[i];
//             int ny=cur.Y+dy[i];
//             if(nx<0||nx>50||ny<0||ny>50) continue;
//             if(map[nx][ny]==0) continue;
//             if(vis[nx][ny]!=0) continue;
//             if(nx==itemX&&ny==itemY) {
//                 answer=vis[cur.X][cur.Y];
//                 return answer;
//             }
//             q.push({nx,ny});
//             vis[nx][ny]=vis[cur.X][cur.Y]+1;
//         }
//     }
    
// }


//좌표 2배로 하기 전

// #include <string>
// #include <vector>
// #include <queue>
// #include <iostream>
// using namespace std;

// int map[52][52];
// int vis[52][52];
// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};
// #define X first
// #define Y second

// int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
//     int answer = 0;
//     int n = rectangle.size();

//     // 경계선 표시
//     for(int i = 0; i < n; i++) {
//         for(int x = rectangle[i][0]; x <= rectangle[i][2]; x++) {
//             map[x][rectangle[i][1]] = 1; // 하변
//             map[x][rectangle[i][3]] = 1; // 상변
//         }
//         for(int y = rectangle[i][1]; y <= rectangle[i][3]; y++) {
//             map[rectangle[i][0]][y] = 1; // 좌변
//             map[rectangle[i][2]][y] = 1; // 우변
//         }
//     }

//     // 직사각형 내부를 0으로 초기화
//     for(int i = 0; i < n; i++) {
//         for(int x = rectangle[i][0] + 1; x < rectangle[i][2]; x++) {
//             for(int y = rectangle[i][1] + 1; y < rectangle[i][3]; y++) {
//                 map[x][y] = 0;
//             }
//         }
//     }
    
//     for(int i=0;i<10;i++) {
//         for(int j=0;j<10;j++) {
//             cout<<map[i][j]<<' ';
//         }
//         cout<<'\n';
//     }
    
//     queue<pair<int, int>> q;
//     q.push({characterX, characterY});
//     vis[characterX][characterY] = 1;
    
//     while(!q.empty()){
//         pair<int, int> cur = q.front();
//         q.pop();
//         for(int i = 0; i < 4; i++) {
//             int nx = cur.X + dx[i];
//             int ny = cur.Y + dy[i];
//             if(nx < 0 || nx >= 51 || ny < 0 || ny >= 51) continue;
//             if(map[nx][ny] == 0) continue;
//             if(vis[nx][ny] != 0) continue;
//             if(nx == itemX && ny == itemY) {
//                 answer = vis[cur.X][cur.Y];
//                 return answer;
//             }
//             q.push({nx, ny});
//             vis[nx][ny] = vis[cur.X][cur.Y] + 1;
//         }
//     }
    
//     return answer;
// }

//좌표 2배
#include <string>
#include <vector>
#include <queue>
using namespace std;

int map[102][102];
int vis[102][102];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
#define X first
#define Y second

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    int n = rectangle.size();

    // 모든 좌표를 2배로 확장
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;

    // 경계선 표시
    for(int i = 0; i < n; i++) {
        for(int x = rectangle[i][0] * 2; x <= rectangle[i][2] * 2; x++) {
            map[x][rectangle[i][1] * 2] = 1; // 하변
            map[x][rectangle[i][3] * 2] = 1; // 상변
        }
        for(int y = rectangle[i][1] * 2; y <= rectangle[i][3] * 2; y++) {
            map[rectangle[i][0] * 2][y] = 1; // 좌변
            map[rectangle[i][2] * 2][y] = 1; // 우변
        }
    }

    // 직사각형 내부를 0으로 초기화
    for(int i = 0; i < n; i++) {
        for(int x = rectangle[i][0] * 2 + 1; x < rectangle[i][2] * 2; x++) {
            for(int y = rectangle[i][1] * 2 + 1; y < rectangle[i][3] * 2; y++) {
                map[x][y] = 0;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({characterX, characterY});
    vis[characterX][characterY] = 1;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= 102 || ny < 0 || ny >= 102) continue;
            if(map[nx][ny] == 0) continue;
            if(vis[nx][ny] != 0) continue;
            if(nx == itemX && ny == itemY) {
                answer = vis[cur.X][cur.Y];
                return answer / 2; // 좌표를 2배로 확장했으므로 결과는 2로 나누어야 함
            }
            q.push({nx, ny});
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
        }
    }

   
}



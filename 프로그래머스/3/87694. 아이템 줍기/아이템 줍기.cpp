#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int map[102][102];
int vis[102][102];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
#define X first
#define Y second

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    int n=rectangle.size();
    
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    for(int i=0;i<n;i++) {
       
        
        for(int x=rectangle[i][0]*2;x<=rectangle[i][2]*2;x++) { //직사각형의 아랫변     
            bool is_border=true;
            int y=rectangle[i][1]*2; //직사각형의 아랫변의 y좌표
            for(int j=0;j<n;j++) {
                if(i==j) continue;
               
                if(x>rectangle[j][0]*2&&x<rectangle[j][2]*2&&y>rectangle[j][1]*2&&y<rectangle[j][3]*2) {
                    is_border=false;
                    break;
                }
                
            }
            if(is_border) map[x][y]=1; //위치 중요!!!!!!! 바로 위 for 문 안에 썼었음..나머지 사각형 내부에 있지 않으면 마지막에 좌표별로 한번씩만 1로 할당하면 되잖아..!!!
        }
        
        for(int y=rectangle[i][1]*2;y<=rectangle[i][3]*2;y++) { //직사각형의 오른쪽변
            bool is_border=true;
            int x=rectangle[i][2]*2; //직사각형의 오른쪽변의 x 좌표
            for(int j=0;j<n;j++) {
                if(i==j) continue;
                
                if(y>rectangle[j][1]*2&&y<rectangle[j][3]*2&&x>rectangle[j][0]*2&&x<rectangle[j][2]*2) {
                    is_border=false;
                    break;
                }
                
            }
            if(is_border) map[x][y]=1;
                
        }
       
        for(int x=rectangle[i][0]*2;x<=rectangle[i][2]*2;x++) { //직사각형의 위쪽변
            bool is_border=true;
             int y=rectangle[i][3]*2; //직사각형의 위쪽변의 y 좌표
            for(int j=0;j<n;j++) {
                if(i==j) continue;
               
                if(y>rectangle[j][1]*2&&y<rectangle[j][3]*2&&x>rectangle[j][0]*2&&x<rectangle[j][2]*2) {
                    is_border=false;
                    break;
                }
                
            }
            if(is_border) map[x][y]=1;
        }
        
        for(int y=rectangle[i][1]*2;y<=rectangle[i][3]*2;y++) { //직사각형의 왼쪽변
            bool is_border=true;
            int x=rectangle[i][0]*2; //직사각형의 왼쪽변의 x 좌표
            for(int j=0;j<n;j++) {
                if(i==j) continue;
                
                if(y>rectangle[j][1]*2&&y<rectangle[j][3]*2&&x>rectangle[j][0]*2&&x<rectangle[j][2]*2) {
                    is_border=false;
                    break;
                }
                
            }
            if(is_border) map[x][y]=1;
        }
        
    }
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            cout<<map[i][j];
        }
        cout<<'\n';
    }
    queue<pair<int,int>> q;
    q.push({characterX, characterY});
    vis[characterX][characterY]=1;
    
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int nx=cur.X+dx[i];
            int ny=cur.Y+dy[i];
            if(nx<0||nx>=101||ny<0||ny>=101) continue;
            if(map[nx][ny]==0) continue;
            if(vis[nx][ny]!=0) continue;
            if(nx==itemX&&ny==itemY) {
                answer=vis[cur.X][cur.Y];
                return answer/2;
            }
            q.push({nx,ny});
            vis[nx][ny]=vis[cur.X][cur.Y]+1;
        }
    }
    
}


// //좌표 2배로 하기 전-일부 케이스에 대해 오답, 테두리 정확히 처리 못하기 때문

// // #include <string>
// // #include <vector>
// // #include <queue>
// // #include <iostream>
// // using namespace std;

// // int map[52][52];
// // int vis[52][52];
// // int dx[4] = {1, -1, 0, 0};
// // int dy[4] = {0, 0, 1, -1};
// // #define X first
// // #define Y second

// // int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
// //     int answer = 0;
// //     int n = rectangle.size();

// //     // 경계선 표시
// //     for(int i = 0; i < n; i++) {
// //         for(int x = rectangle[i][0]; x <= rectangle[i][2]; x++) {
// //             map[x][rectangle[i][1]] = 1; // 하변
// //             map[x][rectangle[i][3]] = 1; // 상변
// //         }
// //         for(int y = rectangle[i][1]; y <= rectangle[i][3]; y++) {
// //             map[rectangle[i][0]][y] = 1; // 좌변
// //             map[rectangle[i][2]][y] = 1; // 우변
// //         }
// //     }

// //     // 직사각형 내부를 0으로 초기화
// //     for(int i = 0; i < n; i++) {
// //         for(int x = rectangle[i][0] + 1; x < rectangle[i][2]; x++) {
// //             for(int y = rectangle[i][1] + 1; y < rectangle[i][3]; y++) {
// //                 map[x][y] = 0;
// //             }
// //         }
// //     }
    
// //     for(int i=0;i<10;i++) {
// //         for(int j=0;j<10;j++) {
// //             cout<<map[i][j]<<' ';
// //         }
// //         cout<<'\n';
// //     }
    
// //     queue<pair<int, int>> q;
// //     q.push({characterX, characterY});
// //     vis[characterX][characterY] = 1;
    
// //     while(!q.empty()){
// //         pair<int, int> cur = q.front();
// //         q.pop();
// //         for(int i = 0; i < 4; i++) {
// //             int nx = cur.X + dx[i];
// //             int ny = cur.Y + dy[i];
// //             if(nx < 0 || nx >= 51 || ny < 0 || ny >= 51) continue;
// //             if(map[nx][ny] == 0) continue;
// //             if(vis[nx][ny] != 0) continue;
// //             if(nx == itemX && ny == itemY) {
// //                 answer = vis[cur.X][cur.Y];
// //                 return answer;
// //             }
// //             q.push({nx, ny});
// //             vis[nx][ny] = vis[cur.X][cur.Y] + 1;
// //         }
// //     }
    
// //     return answer;
// // }

// //좌표 2배(GPT 참고 답안)
// #include <string>
// #include <vector>
// #include <queue>
// using namespace std;

// int map[102][102];
// int vis[102][102];
// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};
// #define X first
// #define Y second

// int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
//     int answer = 0;
//     int n = rectangle.size();

//     // 모든 좌표를 2배로 확장
//     characterX *= 2;
//     characterY *= 2;
//     itemX *= 2;
//     itemY *= 2;

//     // 경계선 표시
//     for(int i = 0; i < n; i++) {
//         for(int x = rectangle[i][0] * 2; x <= rectangle[i][2] * 2; x++) {
//             map[x][rectangle[i][1] * 2] = 1; // 하변
//             map[x][rectangle[i][3] * 2] = 1; // 상변
//         }
//         for(int y = rectangle[i][1] * 2; y <= rectangle[i][3] * 2; y++) {
//             map[rectangle[i][0] * 2][y] = 1; // 좌변
//             map[rectangle[i][2] * 2][y] = 1; // 우변
//         }
//     }

//     // 직사각형 내부를 0으로 초기화
//     for(int i = 0; i < n; i++) {
//         for(int x = rectangle[i][0] * 2 + 1; x < rectangle[i][2] * 2; x++) {
//             for(int y = rectangle[i][1] * 2 + 1; y < rectangle[i][3] * 2; y++) {
//                 map[x][y] = 0;
//             }
//         }
//     }

//     queue<pair<int, int>> q;
//     q.push({characterX, characterY});
//     vis[characterX][characterY] = 1;

//     while(!q.empty()) {
//         pair<int, int> cur = q.front();
//         q.pop();
//         for(int i = 0; i < 4; i++) {
//             int nx = cur.X + dx[i];
//             int ny = cur.Y + dy[i];
//             if(nx < 0 || nx >= 102 || ny < 0 || ny >= 102) continue;
//             if(map[nx][ny] == 0) continue;
//             if(vis[nx][ny] != 0) continue;
//             if(nx == itemX && ny == itemY) {
//                 answer = vis[cur.X][cur.Y];
//                 return answer / 2; // 좌표를 2배로 확장했으므로 결과는 2로 나누어야 함
//             }
//             q.push({nx, ny});
//             vis[nx][ny] = vis[cur.X][cur.Y] + 1;
//         }
//     }

   
// }


//내가 직접 풀이한 풀이1과 같은 논리인데 좌표만 두배로 확장-정답!
// #include <string>
// #include <vector>
// #include <queue>
// using namespace std;

// int map[102][102];
// int vis[102][102];
// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};
// #define X first
// #define Y second

// int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
//     int answer = 0;
//     int n = rectangle.size();

//     // 모든 좌표를 2배로 확장
//     characterX *= 2;
//     characterY *= 2;
//     itemX *= 2;
//     itemY *= 2;

//     // 경계선 표시
//     for (int i = 0; i < n; i++) {
//         for (int x = rectangle[i][0] * 2; x <= rectangle[i][2] * 2; x++) { // 직사각형의 아랫변
//             bool is_border = true;
//             int y = rectangle[i][1] * 2; // 직사각형의 아랫변의 y좌표
//             for (int j = 0; j < n; j++) {
//                 if (i == j) continue;
//                 if (x > rectangle[j][0] * 2 && x < rectangle[j][2] * 2 && y > rectangle[j][1] * 2 && y < rectangle[j][3] * 2) {
//                     is_border = false;
//                     break;
//                 }
//             }
//             if (is_border) map[x][y] = 1;
//         }

//         for (int x = rectangle[i][0] * 2; x <= rectangle[i][2] * 2; x++) { // 직사각형의 윗변
//             bool is_border = true;
//             int y = rectangle[i][3] * 2; // 직사각형의 윗변의 y좌표
//             for (int j = 0; j < n; j++) {
//                 if (i == j) continue;
//                 if (x > rectangle[j][0] * 2 && x < rectangle[j][2] * 2 && y > rectangle[j][1] * 2 && y < rectangle[j][3] * 2) {
//                     is_border = false;
//                     break;
//                 }
//             }
//             if (is_border) map[x][y] = 1;
//         }

//         for (int y = rectangle[i][1] * 2; y <= rectangle[i][3] * 2; y++) { // 직사각형의 왼쪽변
//             bool is_border = true;
//             int x = rectangle[i][0] * 2; // 직사각형의 왼쪽변의 x 좌표
//             for (int j = 0; j < n; j++) {
//                 if (i == j) continue;
//                 if (x > rectangle[j][0] * 2 && x < rectangle[j][2] * 2 && y > rectangle[j][1] * 2 && y < rectangle[j][3] * 2) {
//                     is_border = false;
//                     break;
//                 }
//             }
//             if (is_border) map[x][y] = 1;
//         }

//         for (int y = rectangle[i][1] * 2; y <= rectangle[i][3] * 2; y++) { // 직사각형의 오른쪽변
//             bool is_border = true;
//             int x = rectangle[i][2] * 2; // 직사각형의 오른쪽변의 x 좌표
//             for (int j = 0; j < n; j++) {
//                 if (i == j) continue;
//                 if (x > rectangle[j][0] * 2 && x < rectangle[j][2] * 2 && y > rectangle[j][1] * 2 && y < rectangle[j][3] * 2) {
//                     is_border = false;
//                     break;
//                 }
//             }
//             if (is_border) map[x][y] = 1;
//         }
//     }

//     // BFS를 이용한 최단 경로 탐색
//     queue<pair<int, int>> q;
//     q.push({characterX, characterY});
//     vis[characterX][characterY] = 1;

//     while (!q.empty()) {
//         pair<int, int> cur = q.front();
//         q.pop();
//         for (int i = 0; i < 4; i++) {
//             int nx = cur.X + dx[i];
//             int ny = cur.Y + dy[i];
//             if (nx < 0 || nx >= 102 || ny < 0 || ny >= 102) continue;
//             if (map[nx][ny] == 0) continue;
//             if (vis[nx][ny] != 0) continue;
//             if (nx == itemX && ny == itemY) {
//                 answer = vis[cur.X][cur.Y];
//                 return answer / 2; // 좌표를 2배로 확장했으므로 결과는 2로 나누어야 함
//             }
//             q.push({nx, ny});
//             vis[nx][ny] = vis[cur.X][cur.Y] + 1;
//         }
//     }

//     return answer / 2;
// }



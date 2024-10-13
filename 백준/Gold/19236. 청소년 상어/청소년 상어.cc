#include <iostream>
#include <algorithm>
using namespace std;

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
#define Y first
#define X second

int Sum;
int Max;
struct Node {
    int num;
    int dir;
};
struct SS {
    pair<int, int> pos;
    int dir;
};
SS shark; // 상어 위치, 방향
pair<int, int> fish[17]; // 물고기 위치 (물고기 번호가 인덱스)
int vis[17]; // 물고기 죽음 여부
Node arr[4][4];

void FishMove(Node a[4][4], pair<int, int> fi[17],SS sh) {
    for (int i = 1; i <= 16; i++) {
        if (vis[i]) continue; // 이미 죽은 물고기는 패스
        pair<int, int> cur = fi[i];
        int arrow = a[cur.Y][cur.X].dir - 1;

        for (int ind = 0; ind < 8; ind++) {
            int newArrow = (arrow + ind) % 8;
            int ny = cur.Y + dy[newArrow];
            int nx = cur.X + dx[newArrow];

            if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue; // 경계 밖
            if (ny == sh.pos.Y && nx == sh.pos.X) continue; // 상어가 있는 위치
            a[cur.Y][cur.X].dir=newArrow+1;
            // 물고기 이동
            int tmp = a[ny][nx].num;
            if (tmp == 0) { // 빈 칸일 경우
                fi[i] = {ny, nx};
                a[ny][nx] = a[cur.Y][cur.X];
                a[cur.Y][cur.X] = {0, 0}; // 빈 칸으로 처리
                break;
            } else {
                // 물고기 교환
                fi[i] = {ny, nx};
                fi[tmp] = cur;
                swap(a[ny][nx], a[cur.Y][cur.X]);
                break;
            }
        }
    }
}

void dfs(SS sh, int tot, Node a[][4], pair<int, int> ff[17]) {
    int dd = sh.dir - 1; // 상어 방향
    pair<int, int> cur = sh.pos;

    // 현재 배열 상태 복사
    Node a2[4][4];
    pair<int, int> ff2[17];
   
   
    for (int i = 0; i < 4; i++) copy(a[i], a[i] + 4, a2[i]); //이 두줄 아래랑 순서 바꿨다가 한참 헤멤.... 상어 이동 후 
     copy(ff, ff + 17, ff2);

    FishMove(a2, ff2,sh); // 물고기 이동 //a2와 ff2는 FishMove에서만 바뀜. 그래서 변환된 상태 그대로 냅둠.
     
    
    // cout<<"fish move후\n";
    // for(int i=0;i<4;i++) {
    //     for(int j=0;j<4;j++) {
    //         cout<<a2[i][j].num<<' '<<a2[i][j].dir<<' ';
    //     }
    //     cout<<'\n';
    // }

    bool moved = false;
    // 상어가 이동할 수 있는지 확인
    for (int i = 1; i < 4; i++) {
        int ny = cur.Y + dy[dd] * i;
        int nx = cur.X + dx[dd] * i;
        if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
        if (a2[ny][nx].num == 0) continue; // 물고기가 없는 칸은 패스
        int tmp=a2[ny][nx].num; 
        moved = true;
        a2[ny][nx].num = 0; 
        vis[tmp] = 1; // 물고기 먹음 표시
        dfs({{ny, nx}, a2[ny][nx].dir}, tot + tmp, a2, ff2); // 재귀 호출
        vis[tmp] = 0; // 백트래킹 (물고기 상태 복구)
        a2[ny][nx].num=tmp;
    }

    if (!moved) { // 상어가 더 이상 이동할 수 없는 경우
        Max = max(Max, tot); // 현재까지 먹은 물고기 수의 최대값 갱신
        //cout<<"Max:"<<Max<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int n, d;
            cin >> n >> d;
            arr[i][j] = {n, d};
            fish[n] = {i, j}; // 물고기 위치 저장
        }
    }

    shark.pos = {0, 0}; // 상어 초기 위치
    shark.dir = arr[0][0].dir; // 상어가 첫 번째 물고기의 방향을 가짐
    Sum = arr[0][0].num; // 첫 번째 물고기를 먹은 상태
    vis[arr[0][0].num] = 1; // 첫 번째 물고기 먹음 표시
    arr[0][0].num=0;
    dfs(shark, Sum, arr, fish); // DFS 시작
    cout << Max; // 최대 물고기 수 출력
}

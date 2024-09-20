#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define Y first 
#define X second
using namespace std;
int vis_h[50][50];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int N, M;
string house[51];
pair<int, int> pos; //시작 위치
pair<int, int> des; //나가는 위치
vector<pair<int, int>> st; //물건들 위치 저장
int Min = INT_MAX;
int order[5]; //순서 저장
int vis[5];
int cnt;//물건 개수

int bfs(queue<pair<int, int>> q, pair<int, int> end) {
    // queue<pair<int,int>> q;
    // q.push(pos);

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
            if (house[ny][nx] == '#') continue;
            if (vis_h[ny][nx] != -1) continue;
            q.push({ ny,nx });
            vis_h[ny][nx] = vis_h[cur.Y][cur.X] + 1;
            if (ny == end.Y && nx == end.X) {
                return vis_h[ny][nx]; //다음 물건까지의 최소 거리

            }
        }
    }
}

void func(int ind) { //물건을 집는 순서의 경우의 수
    if (ind == cnt) {
        int tmp = 0;
        st.push_back(des);
        for (int i = 0; i <= cnt; i++) {
            pair<int, int> next;
            if (i == cnt) next = st[cnt];
            else next = st[order[i]];
            queue<pair<int, int>> q;
            fill(&vis_h[0][0], &vis_h[M - 1][N - 1], -1);
            if (i == 0) {
                q.push(pos);
                vis_h[pos.Y][pos.X] = 0;
            }
            else {
                q.push(st[order[i - 1]]);
                vis_h[st[order[i - 1]].Y][st[order[i - 1]].X] = 0;
            }
            tmp += bfs(q, next);

        }
        Min = min(Min, tmp);
        return;
    }
    for (int i = 0; i < cnt; i++) {
        if (vis[i] == 0) {
            order[ind] = i;
            vis[i] = 1;
            func(ind + 1);
            vis[i] = 0;
        }

    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> house[i];
        for (int j = 0; j < N; j++) {
            if (house[i][j] == 'S') {
                pos = { i,j };
            }
            else if (house[i][j] == 'E') {
                des = { i,j };
            }
            else if (house[i][j] == 'X') {
                cnt++;
                st.push_back({ i,j });
            }
        }
    }
    func(0);
    cout << Min;
}
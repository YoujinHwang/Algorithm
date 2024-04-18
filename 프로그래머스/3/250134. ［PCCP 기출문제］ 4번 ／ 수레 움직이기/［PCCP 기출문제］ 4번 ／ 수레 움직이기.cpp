#include <vector>
#include <climits>
#define X first
#define Y second

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visr[4][4]; // 방문 배열을 확장하여 빨간, 파란 구슬의 위치 모두 체크
bool visb[4][4]; 
int map[4][4];
int n, m;
int res = INT_MAX;

pair<int, int> red_st, blue_st, red_end, blue_end;

pair<int, int> getNext(pair<int, int> cur, int dir) {
    int nx = cur.X + dx[dir];
    int ny = cur.Y + dy[dir];
    return {nx, ny};
}

bool isValid(pair<int, int> p) {
    return p.X >= 0 && p.X < n && p.Y >= 0 && p.Y < m && map[p.X][p.Y] != 5;
}

void dfs(pair<int, int> red, pair<int, int> blue, int steps, bool RedSc, bool BlueSc) {
    if (RedSc && BlueSc) {
        res = min(res, steps);
        return;
    }
    if (steps >= res) return;  // 현재 찾은 해보다 더 많은 단계를 필요로 할 때는 중단
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            pair<int, int> nred = (RedSc ? red : getNext(red, i));
            pair<int, int> nblue = (BlueSc ? blue : getNext(blue, j));

            if (!isValid(nred) || !isValid(nblue) || (nred == nblue)) continue;
            if ((!RedSc&&visr[nred.X][nred.Y]) ||(!BlueSc&& visb[nblue.X][nblue.Y])) continue;  // 갱신된 방문 체크 로직
            if(nred==blue&&nblue==red) continue;

            bool newRedSc = RedSc || (nred == red_end);
            bool newBlueSc = BlueSc || (nblue == blue_end);

            visr[nred.X][nred.Y] = true;
            visb[nblue.X][nblue.Y] = true;
            dfs(nred, nblue, steps + 1, newRedSc, newBlueSc);
            visr[nred.X][nred.Y] = false;
            visb[nblue.X][nblue.Y] = false;
        }
    }
}

int solution(vector<vector<int>> maze) {
    n = maze.size();
    m = maze[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            map[i][j] = maze[i][j];
            if (maze[i][j] == 1) {
                red_st = {i, j};
                visr[i][j] = true;
            }
            else if (maze[i][j] == 2) {
                blue_st = {i, j};
                visb[i][j] = true;
            }
            else if (maze[i][j] == 3) red_end = {i, j};
            else if (maze[i][j] == 4) blue_end = {i, j};
        }
    }

    dfs(red_st, blue_st, 0, false, false);

    return (res == INT_MAX) ? 0 : res;
}

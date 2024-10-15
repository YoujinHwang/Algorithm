#include <iostream>
#include <deque>
using namespace std;
int N, M, k;

struct Shark {
	pair<int, int> pos;
	int dir;
};
struct Node {
	int num;//상어 
	int cnt; //남은 초
};
Node arr[20][20];
int dead[401];
#define Y first
#define X second

Shark cur[401];//상어 현재 위치,방향
int dy[] = {0,-1,1,0,0 }; //위 아래 왼 오
int dx[] = { 0,0,0,-1,1 };

int order[401][5][4]; //우선순위
int tot;

void sharkMove(Node map[][20]) {
	for (int i = 1; i <= M; i++) {
		if (dead[i]) continue; //죽은 상어 넘어감
		bool isMoved = false;
		pair<int, int> now = cur[i].pos;
		//cout << now.Y << ' ' << now.X << '\n';
		int dir = cur[i].dir;
		int vis[5];
		int ok = 0;
		for (int ind = 0; ind < 4; ind++) { //냄새 없는 칸
			int ny = now.Y + dy[order[i][dir][ind]];
			int nx = now.X + dx[order[i][dir][ind]];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (arr[ny][nx].cnt == 0) { //냄새 없는 칸 있으면 바로 우선 순위 가장 높은 곳으로 이동
				cur[i] = { {ny,nx},order[i][dir][ind] }; 
				if (map[ny][nx].num != 0) { //옮긴 자리에 상어 있으면 죽음
					//cout << ny << ' ' << nx << ' ' << i << "죽음\n";
					dead[i] = 1;
					tot--;
					//cout << tot << '\n';
				}
				else {
					map[ny][nx] = { i,k }; //상어 현재 위치 업데이트

				}
				isMoved = true;
				break; 
			}
		}
		if (!isMoved) { //자신의 냄새 있는 칸
			for (int ind = 0; ind < 4; ind++) { //냄새 없는 칸
				int ny = now.Y + dy[order[i][dir][ind]];
				int nx = now.X + dx[order[i][dir][ind]];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
				if (arr[ny][nx].num != i) continue;
				cur[i] = { {ny,nx},order[i][dir][ind] };
				map[ny][nx] = { i,k };
				break;
			}
		}
		
		
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j].cnt > 0) {
				arr[i][j].cnt--; //냄새 1씩 감소
				if (arr[i][j].cnt == 0) {
					arr[i][j].num = 0;
				}
			}
		}
	}
	//상어 위치 업데이트
	for (int i = 1; i <= M; i++) {
		if (dead[i]) continue;
		pair<int, int> now = cur[i].pos;
		arr[now.Y][now.X] = map[now.Y][now.X];
	}
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j].num;
			arr[i][j].cnt = 0;
			if (arr[i][j].num > 0) {
				cur[arr[i][j].num] = { {i,j},0 };
				arr[i][j].cnt = k;
				
			}
		
		}
	}
	for (int i = 1; i <= M; i++) {
		cin >> cur[i].dir;
	}
	for (int i = 1; i <= M; i++) { //상어
		for (int j = 1; j <= 4; j++) { //상어 방향
			for (int l = 0; l < 4; l ++ ) { //우선순위
				cin >> order[i][j][l];
			}
		}
	}
	int time = 0;
	tot = M;
	while (time<1000) {
		time++;
		Node map[20][20] = { {0,0} };
		sharkMove(map);
		if (tot == 1) {
			cout << time;
			return 0;
		}
	}
	cout << -1;
}
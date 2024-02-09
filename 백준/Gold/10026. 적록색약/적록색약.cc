#include <bits/stdc++.h>
using namespace std;
char arr[100][100];
int vis[100][100];
int vis_f[100][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };


int main() {
	int N;
	int cnt = 0;
	int cnt_f = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	queue<pair<int, int>> q;
	queue<pair<int, int>> q_f;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vis[i][j]) {
				q.push({ i,j });
				vis[i][j] = 1;
				cnt++;
			}
			
			while (!q.empty()) {
				pair<int, int> cur = q.front();
				int x = cur.first;
				int y = cur.second;
				q.pop();
				for (int z = 0; z < 4; z++) {
					int nx = x + dx[z];
					int ny = y + dy[z];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (!vis[nx][ny]) { //!vis[nx][ny] 이 조건 빠트리지 말기!!
						if (arr[nx][ny] == arr[x][y]) {
							q.push({ nx,ny });
							vis[nx][ny] = 1;
						}
					}


				}
			}
			if (!vis_f[i][j]) {
				q_f.push({ i,j });
				vis_f[i][j] = 1;
				cnt_f++;
			}
			while (!q_f.empty()) {
				pair<int, int> cur = q_f.front();
				int x = cur.first;
				int y = cur.second;
				q_f.pop();
				for (int z = 0; z < 4; z++) {
					int nx = x + dx[z];
					int ny = y + dy[z];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (!vis_f[nx][ny]) { //!vis[nx][ny] 이 조건 빠트리지 말기!!
						if (arr[i][j] == 'R' || arr[i][j] == 'G') {
							if (arr[nx][ny] == 'R' || arr[nx][ny] == 'G') {
								q_f.push({ nx,ny });
								vis_f[nx][ny] = 1;
							}
						}
						else {
							if (arr[nx][ny] == arr[x][y]) {
								q_f.push({ nx,ny });
								vis_f[nx][ny] = 1;
							}
						}
					}


				}
			}
		
		}
	}
	cout << cnt << ' ' << cnt_f;
}
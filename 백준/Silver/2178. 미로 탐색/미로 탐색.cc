#include <bits/stdc++.h>
using namespace std;
int arr[100][100];
int dis[100][100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	string line;
	queue<pair<int, int>> q;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> line;
		for (int j = 0; j < M; j++) {
			arr[i][j] = line[j] - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dis[i][j] = -1;
		}
	}
	dis[0][0] = 0;
	q.push({ 0,0 });
	//	cnt++;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		//		cnt++;
	
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

			if (dis[nx][ny] == -1 && arr[nx][ny]) {
				q.push({ nx,ny });
				dis[nx][ny] = dis[cur.first][cur.second] + 1;
			}
			
		}


	}
	cout << dis[N-1][M-1]+1 << '\n';

}
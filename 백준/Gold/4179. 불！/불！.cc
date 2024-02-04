#include <bits/stdc++.h>
using namespace std;

int dis[1000][1000];
int dis2[1000][1000];
string line[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int R, C;
	
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	queue <pair<int, int>> q1;
	queue <pair<int, int>> q2;

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> line[i];
		int j = 0;
		for (char c : line[i]) {
			if (c == 'J') {
				q1.push({ i,j });
			}
			else if (c == 'F') {
				q2.push({ i,j });
			}
			else if (c == '.') {
				dis[i][j] = -1;
				dis2[i][j] = -1;
			}
			j++;
		}
	}

	while (!q2.empty()) {
		pair<int, int> cur;
		cur = q2.front();
		q2.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i]; 
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
			if (line[nx][ny] == '#'||dis[nx][ny]>=0) continue;
			q2.push({ nx,ny });
			dis[nx][ny] = dis[cur.first][cur.second] + 1;
		}
	}
	while (!q1.empty()) {
		pair<int, int> cur;
		cur = q1.front();
		q1.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
				cout<<dis2[cur.first][cur.second] + 1;
				return 0;
			}
			if (line[nx][ny] == '#'||dis2[nx][ny]>=0) continue;
			dis2[nx][ny] = dis2[cur.first][cur.second] + 1;
			if (0 <= dis[nx][ny] && dis[nx][ny] <= dis2[nx][ny]) continue;
			
			q1.push({ nx,ny });
			
		}
	}
	cout << "IMPOSSIBLE\n";
	

}
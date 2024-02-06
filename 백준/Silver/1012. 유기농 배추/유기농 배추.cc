#include <bits/stdc++.h>
using namespace std;
int loc[50][50];
int vis[50][50];

int main() {
	int T,m,n,k,cnt;
	int x, y;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		cnt = 0;
		cin >> m >> n>>k;
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < m; z++) {
				loc[j][z]=0;
				vis[j][z] = 0;
			}
		}
		for (int j = 0; j < k; j++) {
			cin >> y >> x;
			loc[x][y] = 1;
		}
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < m; b++) {
				if (loc[a][b] == 0 || vis[a][b] == 1) continue;
				cnt++;
				//cout << cnt << '\n';
				queue<pair <int, int>> q;
				q.push({ a,b });
				vis[a][b] = 1;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int j = 0; j < 4; j++) {
						int nx = cur.first + dx[j];
						int ny = cur.second + dy[j];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (vis[nx][ny] == 1||loc[nx][ny]==0) continue;
						q.push({ nx,ny });
						vis[nx][ny] = 1;
					}
				}
			}
		}
		cout << cnt << '\n';
		
	}
}
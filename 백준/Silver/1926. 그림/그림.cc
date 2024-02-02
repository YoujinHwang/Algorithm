#include <bits/stdc++.h>
using namespace std;
int arr[500][500];
int vis[500][500];

int main() {
	int n, m,cnt=0, max;
	vector<int> area;
	queue<pair<int,int>> q;
	cin >> n >> m;
	int dx[4] = {1,-1,0,0};
	int dy[4] = { 0,0,1,-1 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
//	vis[0][0] = 1;
//	q.push({ 0,0 });
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
//			vis[i][j] = 1;
			if (vis[i][j]!=1 && arr[i][j] == 1) {
				cnt++;
				q.push({ i,j });
				int a = 1;
				vis[i][j] = 1;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					
					for (int i = 0; i < 4; i++) {
						int nx = cur.first + dx[i];
						int ny = cur.second + dy[i];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
//						if (arr[nx][ny]) {
							if (!vis[nx][ny]&&arr[nx][ny]) {
								q.push({ nx,ny });
								vis[nx][ny] = 1;
								a++;
							}
//						}
					}
				}
				area.push_back(a);
			}
		}
	}
	if (cnt!=0)
		max = *max_element(area.begin(), area.end());
	else max = 0;

	
	cout << cnt <<'\n'<< max<<'\n';
}
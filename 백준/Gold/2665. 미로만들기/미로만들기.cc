#include <iostream>
#include <queue>
#include <climits>
using namespace std;
int n;
string arr[50];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int dist[50][50];
struct Node {
	int y,x;
	int cost;
	bool operator<(Node right)const {
		if (cost < right.cost) return false;
		if (cost > right.cost) return true;
		return false;
	}
};

void dijkstra() {
	priority_queue<Node> pq;
	pq.push({ 0,0,0 });
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = INT_MAX;
		}
	}

	dist[0][0] = 0;
	while (!pq.empty()) {
		Node now = pq.top(); pq.pop();
		if (dist[now.y][now.x] < now.cost) continue;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			int nextcost;
			if (arr[ny][nx] == '0') {
				nextcost = dist[now.y][now.x] + 1;
			}
			else {
				nextcost = dist[now.y][now.x];
			}
			if (dist[ny][nx] <= nextcost) continue;
			dist[ny][nx] = nextcost;
			pq.push({ ny,nx,nextcost });
		}
	}
	cout << dist[n - 1][n - 1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		
		cin >> arr[i];
		
	}
	dijkstra();

}



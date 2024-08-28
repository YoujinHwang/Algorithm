#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> v[100001];
bool vis[100001];
int parent[100001][20];
int d[100001];
void dfs(int i, int depth) {
	vis[i] = true;
	d[i] = depth;
	for (int x : v[i]) {
		if (vis[x]) continue;
		parent[x][0] = i;
		dfs(x, depth + 1);
	}
}

void setParents() {
	dfs(1, 0);
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= N; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1]; //dp로 부모 배열 저장 
		}
	}
}

int lca(int a, int b) {
	if (d[a] > d[b]) {
		swap(a, b);
	}
	for (int i = 19; i >= 0; i--) {
		if (d[b] - d[a] >= (1 << i)) {
			b = parent[b][i]; //더 낮은 b를 올리기!
		}
	}
	if (a == b) return a;
	for (int i = 19; i >= 0; i--) {
		if (parent[a][i]!=parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	setParents();
	
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		cout<<lca(x, y)<<'\n';

	}
	
}
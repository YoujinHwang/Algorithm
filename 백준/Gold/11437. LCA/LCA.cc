#include <iostream>
#include <vector>
using namespace std;
int d[50001];
int parent[50001];
bool vis[50001];
int N, M;
vector<int> v[50001];

void dfs(int i, int depth) {
	vis[i] = true;
	d[i] = depth;
	for (int s : v[i]) {
		if (vis[s]) continue;
		parent[s] = i;
		dfs(s, depth + 1);
	}
}

int lca(int a, int b) {
	while (d[a] != d[b]) {
		if (d[a] > d[b]) {
			a = parent[a];
		}
		else b = parent[b];
	}
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
}

int main() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		cout<<lca(x, y)<<'\n';
	}

}
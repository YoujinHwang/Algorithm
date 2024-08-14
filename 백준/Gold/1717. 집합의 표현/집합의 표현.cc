
//#include <queue>
#include <algorithm>

#include <iostream>
#define MAX 1000001
using namespace std;

int par[MAX];
int sz[MAX];
int find(int a) {
	if (par[a] != a) {
		return par[a] = find(par[a]);
	}
	return a;
}
void Union(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (sz[pa] > sz[pb]) swap(pa, pb);
	if (pa != pb) {
		par[pa] = pb;
		sz[pb] += sz[pa];
	}
}

int main() {
	int n, m;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	//n += 1;
	for (int i = 0; i < n + 1; i++) {
		par[i] = i;
		sz[i] = 1;
	}
	int ord,a,b;
	for (int i = 0; i < m; i++) {
		cin >> ord >> a >> b;
		if (ord == 0) {
			if (a == b) continue;
			Union(a, b);
		}
		else {
			if (a == b) { cout << "YES" << '\n'; continue; }
			int pa=find(a);
			int pb = find(b);
			if (pa == pb) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}
	
}
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
int N,M;
int arr[201][201];
unordered_set<int> s;
vector<int> map[201];
int vis[201];
int par[201];
int Find(int a) {
	if (par[a] == a) return a;
	return par[a]=Find(par[a]);
}
void Union(int a, int b) {
	int pA = Find(a);
	int pB = Find(b);
	if (pA == pB) return;
	par[pB] = pA;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N>>M;
	for (int i = 1; i <= N; i++) par[i] = i;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				map[i].push_back(j);
			}
		}
	}
	int st;
	for (int i = 0; i < M; i++) {
		int city;
		cin >> city;
		if (i == 0) st = city;
		s.insert(city);
		vis[city] = 1;
	}
	int cnt = s.size()-1;
	queue<int> q;
	q.push(st);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i< map[cur].size(); i++) {
			int nxt = map[cur][i];
			int pCur = Find(cur);
			int pNxt = Find(nxt);
			if (pCur == pNxt) continue;
			Union(cur, nxt);
			q.push(nxt);
			if (vis[nxt] == 1) {
				vis[nxt] = 0;
				cnt--;
			}
			if (cnt == 0) {
				cout << "YES";
				return 0;
			}
		}

	}
	if (cnt != 0)
		cout << "NO";
	else cout << "YES";
}
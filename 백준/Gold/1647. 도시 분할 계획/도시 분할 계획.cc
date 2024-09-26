#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
int par[100001];

struct Edge {
	int a, b,c;
	bool operator< (Edge right) const {
		return c > right.c;
	}
};

int Find(int a) {
	if (par[a] == a) return a;
	return par[a]=Find(par[a]);
}
void Union(int a, int b) {
	if (b < a) swap(b, a);
	int pA = Find(a);
	int pB = Find(b);
	if (pA == pB) return;
	par[pB] = pA;
}
priority_queue<Edge> pq;

int ans = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		pq.push({ A,B,C });
	}
	for (int i = 1; i <= N; i++) {
		par[i] = i;
	}
	int cnt=0;
	while (cnt<N-1) {
		Edge cur = pq.top();
		pq.pop();
		//cout<<"par : " << par[cur.a] << ' ' << par[cur.b] << '\n';
		if (Find(cur.a) != Find(cur.b)) { //아 이거 Find()로 부모 확인 안하고 바로 par[]끼리 비교해서 디버깅이 이상하게 나왔음,,,
			Union(cur.a, cur.b);
			//cout << "after par : " << par[cur.a] << ' ' << par[cur.b] << '\n';
			cnt++;
			//cout <<cur.a<<' '<<cur.b <<' ' << cur.c << '\n';
			if (cnt == N - 1) continue;
			
			ans += cur.c;
		}
	}
	cout << ans;
}
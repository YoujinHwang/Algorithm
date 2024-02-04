#include <bits/stdc++.h>
using namespace std;
int arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	for (int i = 0; i < 100001; i++) {
		arr[i] = -1;
	}
	
	cin >> N >> K;
	arr[N] = 0;
	queue<int> q;
	q.push(N);
	
	while (arr[K]==-1) {
		int cur = q.front();
		q.pop();
	//	if (cur == K) {
	//		cout << arr[K] << '\n';
	//		return 0;
	//	}
		for (int nxt : {cur - 1, cur + 1, 2 * cur}) {
			if (nxt < 0 || nxt>100000) continue;
			if (arr[nxt] != -1) continue;
			q.push(nxt);
			arr[nxt] = arr[cur] + 1;
		}
      }
    cout << arr[K];
}
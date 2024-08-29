#include <iostream>
#include <algorithm>
using namespace std;
int M, N;
long long arr[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int st = 1;
	int en = arr[N - 1];
	int ans = -1;
	while (st <= en) {
		int mid = (st + en) / 2;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			int res = arr[i] / mid;
			cnt += res;
		}
		if (cnt >= M) {
			st = mid + 1;
			ans = mid;
		}
		else if (cnt < M) {
			en = mid - 1;
		}
	}
	if (ans == -1) cout << 0;
	else cout << ans;
}
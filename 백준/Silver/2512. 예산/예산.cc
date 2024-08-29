#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[10000];
	int N,M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> M;
	sort(arr, arr + N);
	long long st = 1;
	long long en = M;
	int ans = 0;
	while (st <= en) {
		long long mid = (st + en) / 2;
		long long tot = 0;
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] <= mid) {
				tot += arr[i];
				tmp = max(tmp, arr[i]);
			}
			else {
				tmp = mid;
				tot += mid;
			}
			
		}
		if (M < tot) {
			en = mid - 1;
		}
		else if (M == tot) {
			ans = tmp;
			break;
		}
		else {
			ans = tmp;
			st = mid + 1;
		}
	}
	cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
int mon[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	int cnt = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> mon[i];
	for (int i = n - 1; i >= 0; i--) {
		cnt += k / mon[i];
		k %= mon[i];
		if (k == 0) break;
	}
	cout << cnt << '\n';
}
#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100000];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int st=0, en = 0;
	int ans = INT_MAX;
	while (en < n) {
		int dif = a[en] - a[st];
		if (dif >= m) {
			ans = min(ans, dif);
			st++;
		}
		else en++;
	}
	cout << ans << '\n';

}
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
	int ans = INT_MAX;
	for (int i = 0; i < n-1; i++) {
		auto it = lower_bound(a, a + n, a[i] + m);
		if(it!=a+n)
			ans = min(ans, *it-a[i]);
	}
	cout << ans << '\n';
	
	
}
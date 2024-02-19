#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,m, n, x, y;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> x >> y;
		int l = lcm(m, n);
		int k = -1;
		//if (x == m) x = 0;
		if (y == n) y = 0;

		for (int j = x; j <= l; j+=m) {
			
			if (j % n == y) {
				k = j;
				cout << k << '\n';
				break;
			}
		}
		
		if (k == -1) cout << -1 << '\n';
	}
}
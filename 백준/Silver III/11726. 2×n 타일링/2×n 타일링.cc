#include <bits/stdc++.h>
using namespace std;
int d[1001];

int main() {
	int n;
	cin >> n;
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1];
		d[i] += d[i - 2];
		d[i] %= 10007;
	}
	cout << d[n] << '\n';
}
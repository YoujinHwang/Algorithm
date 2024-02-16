#include <bits/stdc++.h>
using namespace std;
int d[1000001];
int pre[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	d[1] = 0;
	pre[1] = 0;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		pre[i] = i - 1;
		if (i % 3 == 0) {
			if (d[i] > d[i / 3] + 1) {
				d[i] = d[i / 3] + 1;
				pre[i] = i / 3;
			}
		}
		if (i % 2 == 0) {
			if (d[i] > d[i / 2] + 1) {
				d[i] = d[i / 2] + 1;
				pre[i] = i / 2;
			}
		}
	}
	cout << d[n] << '\n';
	cout << n << ' ';
	int x=n;
	for (int i = d[n]; i >0; i--) {
		cout << pre[x] << ' ';
		x = pre[x];
	}
}
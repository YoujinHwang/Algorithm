#include <bits/stdc++.h>
using namespace std;
int arr[100001];
long long d[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	int i, j;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	d[1] = arr[1];
	for (int i = 2; i <= n; i++)
		d[i] = d[i - 1] + arr[i];
	for (int x = 0; x < m; x++) {
		cin >> i >> j;
		if (i > 1)
			cout << d[j] - d[i - 1]<<'\n';
		else
			cout << d[j]<<'\n';
	}
}
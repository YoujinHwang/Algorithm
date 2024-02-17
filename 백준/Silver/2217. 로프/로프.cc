#include <bits/stdc++.h>
using namespace std;
int arr[100000];
int d[100001];
bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, cmp);
	d[1] = arr[0];
	for (int i = 2; i <=n; i++) {
		d[i] = max(d[i - 1], arr[i - 1] * i);
		//cout << d[i] << '\n';
	}
	cout << d[n];
}
#include <bits/stdc++.h>
using namespace std;
int arr[1001][3];
int d[1001][3];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin>>arr[i][j];
		}
	}
	d[1][0] = arr[1][0];
	d[1][1] = arr[1][1];
	d[1][2] = arr[1][2];
	for (int i = 2; i <= n; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2])+arr[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + arr[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + arr[i][2];	
	}
	int minimum = min(min(d[n][0], d[n][1]), d[n][2]);
	cout << minimum << '\n';
}
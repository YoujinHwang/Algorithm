#include <bits/stdc++.h>
using namespace std;
long long a[100000];
long long b[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	
	
	for (int i = 0; i < m; i++) {
		int st = 0, en = n-1, mid;
		while (en >= st) {
			mid = (st + en) / 2;
			if (a[mid] == b[i]) {
				cout << 1 << '\n';
				break;
			}
			else if (a[mid] > b[i]) en = mid - 1;
			else st = mid + 1;
		}
		if (en < st) {
			cout << 0 << '\n';
		}
		
	}
	
	
}
#include <bits/stdc++.h>
using namespace std;


int main() {
	int t,n,m;
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		int a[20000];
		int b[20000];
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}
		sort(a, a + n);
		for (int j = 0; j < m; j++) {
			cin >> b[j];
		}
		sort(b, b + m);
		for (int j = 0; j < n; j++) {
			for (int x = 0; x < m; x++) {
				if (a[j] > b[x]) cnt++;
				else break;
			}
		}
		cout << cnt << '\n';
	}
}
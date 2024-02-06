#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;


int hanoi(int a,int b, int n ) {
	if (n == 1) {
		cout << a << ' ' << b << '\n';
	}
	else {
		hanoi(a, 6 - a - b, n - 1);
		cout << a << ' ' << b << '\n';
		hanoi(6 - a - b, b, n - 1);
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin >> n;
	cout << (1 << n) - 1 << '\n';
	hanoi(1, 3, n);
}
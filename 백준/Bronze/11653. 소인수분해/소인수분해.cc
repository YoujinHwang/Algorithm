#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 1) return 0;
	vector<int> a;
	int i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			a.push_back(i);
			n /= i;
		}
		else i++;
	}
	a.push_back(n);
	for (int x : a) cout << x << '\n';
}
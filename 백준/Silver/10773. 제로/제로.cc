#include <bits/stdc++.h>
using namespace std;

int main() {
	int K, n, total=0;
	stack<int> s;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> n;
		if (n == 0) {
			s.pop();
		}
		else
			s.push(n);
	}
	while (!s.empty()) {
		total += s.top();
		s.pop();
	}
	cout << total << '\n';
}
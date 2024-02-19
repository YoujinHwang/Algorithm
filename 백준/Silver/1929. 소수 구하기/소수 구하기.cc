#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int m,int n) {
	vector<int> primes;
	vector<bool> state(n + 1, true);
	state[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (!state[i])continue;
		for (int j = i * i; j <= n; j += i) {
			state[j] = false;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (state[i]&&i>=m) primes.push_back(i);
	}
	return primes;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> primes;
	int n, m;
	cin >> m>> n;
	primes = sieve(m, n);
	for (int n : primes)
		cout << n << '\n';
}
#include <bits/stdc++.h>
using namespace std;
int freq[2000001];

int main() {
	int n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		freq[x + 1000000]++;
	}
	for (int i = 0; i < 2000001; i++) {
		
		while (freq[i]) {
			cout << i-1000000 << '\n';
			freq[i]--;
		}
	}

}
#include <bits/stdc++.h>
using namespace std;
int ct[10001];



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		ct[x]++;
		
		
	}
	for (int i = 1; i <= 10000; i++) {
		while (ct[i]--) {
			cout << i << '\n';
		}

	}
	
	
}
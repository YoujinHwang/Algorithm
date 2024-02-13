#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[8];
int temp;

void seq(int x) {
	
	if (x == m) {
		for (int i = 0; i < x; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (x >= 1) {
			if (a[x-1] > i+1) continue;
		}
		
		a[x] = i+1;
		seq(x + 1);
	}
}

int main() {
	cin >> n >> m;
	seq(0);
}
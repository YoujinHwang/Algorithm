#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[8];


void seq(int x, int last) {
	if (x == m) {
		for (int i = 0; i < x; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	
	for (int i = last; i < n; i++) {
		
		arr[x] = i + 1;
		seq(x+1,i+1);
		
	}
	
}

int main() {
	cin >> n >> m;
	seq(0,0);
}
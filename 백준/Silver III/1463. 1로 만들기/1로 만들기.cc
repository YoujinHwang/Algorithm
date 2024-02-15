#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000001];


int main() {
	cin >> n;
	a[1] = 0;
	for (int i = 2; i <= n; i++) {
	
		a[i] = a[i - 1] + 1;
		if (i % 3 == 0) a[i] = min(a[i / 3] + 1, a[i]);
		if(i%2==0) a[i] = min(a[i / 2] + 1, a[i]);
	}
	cout << a[n];
}
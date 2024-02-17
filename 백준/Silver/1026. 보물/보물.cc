#include <bits/stdc++.h>
using namespace std;
int a[50];
int b[50];
bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,s=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(a, a + n,cmp);
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		s+=a[i]*b[i];
	}
	cout << s << '\n';
}
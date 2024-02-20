#include <bits/stdc++.h>
using namespace std;
int a[1000000];
vector<int> b;
int c[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c[i] = a[i];
	}
	sort(a, a + n);
	int j = 1,x;
	b.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		//x = a[i];
		if (a[i] != a[i - 1]) {
			b.push_back(a[i]);
		}
		
	}
	//for (int i = 0; i < b.size(); i++) cout << b[i] << ' ';
	for (int i = 0; i < n; i++) {
		cout<<lower_bound(b.begin(),b.end(),c[i])-b.begin()<<' ';
	}
}
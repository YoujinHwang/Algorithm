#include <bits/stdc++.h>
using namespace std;
int a[500000];
int b[500000];
int lower_ind(int target, int len) {
	int st = 0;
	int en = len;
	while (st < en) {
		int mid = (st + en) / 2;
		if (a[mid] >= target) en = mid;
		else st = mid + 1;
	}
	return st;
}

int upper_ind(int target, int len) {
	int st = 0;
	int en = len;
	while (st < en) {
		int mid = (st + en) / 2;
		if (a[mid] > target) en = mid;
		else st = mid + 1;
		
	}
	return st;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cin >> m; 
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		
		cout << upper_ind(b[i],n)-lower_ind(b[i],n) << '\n';
	}

}
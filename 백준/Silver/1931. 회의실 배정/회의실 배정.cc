#include <bits/stdc++.h>
using namespace std;
pair<int,int> p[100001];
int d[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].second;
		cin >> p[i].first;
	}
	sort(p+1, p + n+1);
	d[1] = p[1].first;
	int d_ind = 1;
	for (int i = 2; i <= n; i++) {
		if (p[i].second < d[d_ind]) continue;
		d_ind++;
		d[d_ind] = p[i].first;
		//cout << d_ind << ' ' << p[i].second << ' ' << p[i].first << '\n';
	}
	cout << d_ind << '\n';
}
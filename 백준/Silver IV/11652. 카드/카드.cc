#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> v;

int main() {
	int cnt = 0;
	long long mxval = pow(-2, 62) - 1;
	int mxcnt = 0;
	cin >> n;
	long long x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		if (i == 0) cnt = 1;
		else {
			if (v[i] == v[i - 1]) cnt++;
			else {
				long long temp = mxcnt;
				mxcnt = max(mxcnt, cnt);
				if (temp != mxcnt) mxval = v[i - 1];
				cnt = 1;
			}
		}
	}
	if (cnt > mxcnt) mxval = v[n - 1];
	cout << mxval << '\n';
}
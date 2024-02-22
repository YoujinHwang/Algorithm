#include <bits/stdc++.h>
using namespace std;
int a[100000];
bool cmp(int a, int b) {
	return b < a;
}
bool isPos;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> a[i];
	//sort(a, a + n, cmp);
	int st = 0, en = 0;
	//int cnt = 1;
	int cur = a[st];
	int ans = INT_MAX;

	while (en < n&&st<=en) {
		if (cur >= s) {
			ans = min(ans, en - st + 1);
			cur -= a[st];
			st++;
			//en=st;
			
			
			
			isPos = true;
		}
		else if (cur < s) {
			en++;
			if(en<n)
				cur += a[en];
			//cnt++;
		}	
	}
	if (!isPos) cout << 0<<'\n';
	else cout << ans << '\n';
}
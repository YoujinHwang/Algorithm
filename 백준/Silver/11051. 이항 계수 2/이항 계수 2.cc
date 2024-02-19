#include <bits/stdc++.h>
using namespace std;
int d[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	d[0][0] = 1;
	d[1][0] = 1;
	d[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) d[i][j] = 1;
			else {
				d[i][j] = d[i - 1][j - 1]%10007 + d[i - 1][j]%10007;
				d[i][j]=d[i][j] % 10007;
			}
		}
        
	}
	cout << d[n][k];
}
#include <iostream>
#include <algorithm>
using namespace std;
int M, N;
int arr[1001][1001];
int dp[1001][1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N;
	int ans = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}
	cout << ans;
}
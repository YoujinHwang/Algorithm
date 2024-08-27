#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N,K;
int Time[1001];

vector<int> v[1001];
int deg[1001];
int dp[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int ind = 0; ind < T; ind++) {
		
		cin >> N >> K;
		for (int i = 1; i <= N; i++)  {
			v[i].clear();
		}
		memset(deg, 0, sizeof(deg));
		memset(dp, 0, sizeof(dp));
		for (int j = 1; j <= N; j++) {
			cin >> Time[j];
		}
		for (int j = 0; j < K; j++) {
			int X, Y;
			cin >> X >> Y;
			v[X].push_back(Y);
			deg[Y]++;
		}
		int W;
		cin >> W;
		queue<int> q;
		for (int i = 1; i <= N; i++) {
			if (deg[i] == 0) {
				q.push(i);
			}
		}
		
		int res;
		while(!q.empty()) {
			//while (!q.empty()) {
				int cur = q.front();
				q.pop();
				dp[cur] += Time[cur];
				if (cur == W) {
					cout << dp[W] << '\n';
					break;
				}
				res = cur;
				//Max = max(Max, Time[cur]);
				for (auto s : v[cur]) {
					deg[s]--;
					dp[s] = max(dp[s],dp[cur]);
					if (deg[s] == 0) {
						q.push(s); 
						
					}
				}
			//}
		}
		
	}
	

}
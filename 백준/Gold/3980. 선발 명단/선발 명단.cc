#include <iostream>
#include <vector>
using namespace std;
int arr[12][12];
vector<int> v[12];
int vis[12];
int Max;
void dfs(int ind,int sum) {
	if (ind == 12) {
		Max = max(Max, sum);
	}
	for (int i = 0; i < v[ind].size(); i++) {
		if (vis[v[ind][i]]) continue; //v[ind][i] : 포지션, ind : 선수
		vis[v[ind][i]] = 1;
		dfs(ind + 1,sum+arr[ind][v[ind][i]]);
		vis[v[ind][i]] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int C;
	cin >> C;
	for (int t = 0; t < C; t++) {
		Max = 0;
		for (int i = 1; i <= 11; i++) v[i].clear();
		for (int i = 1; i <= 11; i++) {
			for (int j = 1; j <= 11; j++) {
				cin >> arr[i][j];
				if(arr[i][j]>0)
					v[i].push_back(j);
			}
		}
		dfs(1, 0);
		cout << Max << '\n';
	}
}
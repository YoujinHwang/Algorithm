#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
unordered_map<string, int> m;
int N,M;
string arr[1001];


vector<int> v[1001];
int degree[1001];
vector<int> child[1001]; //자식
int vis[1001];

void topological_sort() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			degree[v[cur][i]]--;
			if (degree[v[cur][i]] == 0&&vis[v[cur][i]]==0) {
				vis[v[cur][i]] = 1;
				q.push(v[cur][i]);
				child[cur].push_back(v[cur][i]);
			}
		}
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + N + 1);
	for (int i = 1; i <= N; i++) {
		m[arr[i]] = i;
	}
	cin >> M;
	
	for (int i = 0; i < M; i++) {
			string X, Y;
			cin >> X >> Y;
			degree[m[X]]++;
			v[m[Y]].push_back(m[X]);

	}
	vector<string> firsts;
	for (int i = 1; i <= N; i++) {
		if (degree[m[arr[i]]] == 0) {
			firsts.push_back(arr[i]);
			
		}
	}
	topological_sort();
	//sort(firsts.begin(), firsts.end());
	cout << firsts.size() << '\n';
	for (auto s : firsts) {
		cout << s << ' ';
	}
	cout << '\n';
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << ' '<<child[i].size()<<" ";
		sort(child[i].begin(), child[i].end());
		for (auto s : child[i]) {
			cout<<arr[s] << ' ';
		}
		cout << '\n';
	}
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	queue<int> q;
	string ord;
	int N, x;
	cin >> N;
	while (N--) {
		cin >> ord;
		if (ord == "push") {
			cin >> x;
			q.push(x);
		}
		else if (ord == "pop") {
			if (!q.empty()) {
				cout << q.front()<<'\n';
				q.pop();
			}
			else cout << -1 << '\n';
		}
		else if (ord == "size") {
			cout << q.size()<<'\n';
		}
		else if (ord == "empty") cout << q.empty() << '\n';
		else if (ord == "front") {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.front()<<'\n';
		}
		else {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
	}
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	deque<int> d;
	int N,num;
	string ord;
	cin >> N;
	while (N--) {
		cin >> ord;
		if (ord == "push_front") {
			cin >> num;
			d.push_front(num);
		}
		else if (ord == "push_back") {
			cin >> num;
			d.push_back(num);
		}
		else if (ord == "pop_front") {
			if (!d.empty()) {
				cout << d.front() << '\n';
				d.pop_front();
			}
			else cout << -1 << '\n';
		}
		else if (ord == "pop_back") {
			if (!d.empty()) {
				cout << d.back() << '\n';
				d.pop_back();
			}
			else cout << -1 << '\n';
		}
		else if (ord == "size") {
			cout << d.size() << '\n';
		}
		else if (ord == "empty") {
			cout << d.empty() << '\n';
		}
		else if (ord == "front") {
			if (!d.empty()) {
				cout << d.front() << '\n';
			}
			else cout << -1 << '\n';
		}
		else if (ord == "back") {
			if (!d.empty()) {
				cout << d.back() << '\n';
			}
			else cout << -1 << '\n';
		}
	}
}
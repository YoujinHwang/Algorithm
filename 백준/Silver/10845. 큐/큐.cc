#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>


using namespace std;
int main() {
	queue<int> q;
	string order;
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> order;
		if (order == "push") {
			cin >> num;
			q.push(num);
		}
		else if (order == "pop") {
			if (q.empty()) {
				cout << "-1" << endl;
				continue;
			}
			cout << q.front() << endl;
			q.pop();
		}
		else if (order == "size") {
			cout << q.size() << endl;
		}
		else if (order == "empty") {
			cout << q.empty() << endl;
		}
		else if (order == "front") {
			if (q.empty()) {
				cout << "-1" << endl;
				continue;
			}
			cout << q.front() << endl;
		}
		else if (order == "back") {
			if (q.empty()) {
				cout << "-1" << endl;
				continue;
			}
			cout << q.back() << endl;
		}
	}

}
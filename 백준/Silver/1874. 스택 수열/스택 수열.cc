#include <bits/stdc++.h>
using namespace std;
//int arr[100000];
//int arr2[100000];

int main() {
	int n, cnt = 0, ind = 0;
	int num = 1;
	int x = 0;
	cin >> n;
	vector<int> arr(n);
	stack<int> s;
	vector<char> oper;
//	bool isPossible = true;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		while (num <= arr[i]) {
			s.push(num++);
			oper.push_back('+');
		}
		if (s.top() == arr[i]) {
			s.pop();
			oper.push_back('-');
		}
		else {
//			isPossible = false;
			cout << "NO" << '\n';
			return 0;
		}
	}
	for (char op : oper) {
		cout << op << '\n';
	}
	return 0;
}
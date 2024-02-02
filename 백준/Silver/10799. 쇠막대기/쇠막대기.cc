#include <bits/stdc++.h>
using namespace std;

int main() {
	stack<char> s;
	string str;
	int cnt = 0;
	getline(cin, str);
	bool isLazer = true;
	for (char c : str) {
		if (c == '(') {
			s.push(c);
			isLazer = true;
			cnt++;
		}
		else {
			if (isLazer) {
				s.pop();
				cnt--;
				cnt += s.size();
			}
			else {
				s.pop();
			}
			isLazer = false;

		}
	}
	cout << cnt << '\n';
}
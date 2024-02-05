#include <bits/stdc++.h>
using namespace std;
int cnt;


int recursion(const string& s, int l, int r) {
	if (l >= r) {
		return 1;
	}
	else if (s[l] != s[r]) {
		return 0;
	}
	else {
		cnt++;
		return recursion(s, l + 1, r - 1);
	}
}

int isPalindrome(const string& s) {
	cnt = 1;
	return recursion(s, 0, s.length() - 1);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	string S;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> S;
		
		cout << isPalindrome(S) << ' ';
		cout<< cnt << '\n';
	}
	
}
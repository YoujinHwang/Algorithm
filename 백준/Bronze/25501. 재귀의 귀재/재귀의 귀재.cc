#include <bits/stdc++.h>
using namespace std;
int cnt;


int recursion(const string& s, int l, int r) { //그냥 string s으로 할 경우 시간초과. 이는 재귀 호출마다
						// 문자열의 복사본을 생성함. 따라서 큰 문자열과 깊은 재귀에 대해서는 상당한 오버헤드를 발생시킬 수 있음.
						// 문자열을 참조로 전달하여 이 문제를 해결할 수 있다.
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

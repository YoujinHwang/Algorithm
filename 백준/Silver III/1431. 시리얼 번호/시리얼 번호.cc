#include <bits/stdc++.h>
#include <cctype>
using namespace std;
int n;
string s[50];

bool cmp(const string& a, const string& b) {
	int a_sum = 0, b_sum = 0;
	if(a.length() != b.length())
		return a.length() < b.length();

	for (char c : a) {
		if (isdigit(c))
			a_sum += c - '0';
	}
	for (char c : b) {
		if (isdigit(c))
			b_sum += c - '0';
	}
	if (a_sum != b_sum) return a_sum < b_sum;
	return a < b;



}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s, s + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << s[i] << '\n';
	}
}
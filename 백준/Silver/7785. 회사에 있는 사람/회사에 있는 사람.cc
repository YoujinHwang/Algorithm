#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
bool cmp(string a, string b) {
	return a > b;
}

unordered_set<string> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string name;
	string x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> x;
		if (s.find(name) != s.end()) s.erase(name);
		else s.insert(name);

	}
	vector<string> v(s.begin(), s.end());
	sort(v.begin(),v.end(),cmp);
	for (string a : v)
		cout << a << '\n';
}
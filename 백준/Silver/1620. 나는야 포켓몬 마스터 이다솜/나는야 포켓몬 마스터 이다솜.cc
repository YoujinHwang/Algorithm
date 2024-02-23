#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<string, int> mm;
string i2s[100001];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	int i = 1;
	for (int i = 1; i <= n; i++) {
		cin >> i2s[i];
		mm[i2s[i]] = i;
	}
	while (m--) {
		string tmp;
		cin >> tmp;
		if (isdigit(tmp[0]))
			cout << i2s[stoi(tmp)] << '\n';
		else cout << mm[tmp] << '\n';
	}
}
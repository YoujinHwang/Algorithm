#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const pair<string, int>& a, const pair<string, int>& b) {
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int K, L;
	cin >> K >> L;
	unordered_map<string,int> m;
	for (int i = 0; i < L; i++) {
		string a;
		cin >> a;
		if (m.find(a) != m.end()) {
			m.erase(a);
			m.insert({a,i});
		}
		else {
			m.insert({ a,i });
		}
	}
	vector<pair<string, int>> v;
	for (auto s : m) {
		v.push_back(s);
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < min(K,(int)v.size()); i++) { //수강신청 정원보다 더 적게 신청할 수 있으므로 min 해줘야함!!
		cout << v[i].first << '\n';
	}
}

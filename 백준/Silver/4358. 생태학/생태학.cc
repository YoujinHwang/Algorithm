#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<string, double> tree;
	set<string> list;
	string name;
	int cnt = 0;
	while (getline(cin, name)) {
		if (name.empty()) break;
		cnt++;
		list.insert(name);
		if (tree.find(name) != tree.end()) {
			tree[name]++;
		}
		else tree[name] = 1;
	}
	for (auto s : list) {
		double tmp = tree[s] / cnt*100;
		/*double ans = tmp /10000;
		cout << s << ' ' << ans << '\n';*/
		cout<<s<<' ' << tmp<<'\n';
		cout << fixed;
		cout.precision(4);
		
	}
}
#include <iostream>
#include <string>
#include <set>

using namespace std;
string S, E, Q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> S >> E >> Q;
	pair<int, int> st;
	pair<int, int> en;
	pair<int, int> en_vi;
	int a = stoi(S.substr(0, 2));
	int b= stoi(S.substr(3));
	st = { a,b };
	a = stoi(E.substr(0, 2));
	b = stoi(E.substr(3));
	en = { a,b };

	a = stoi(Q.substr(0, 2));
	b = stoi(Q.substr(3));
	en_vi = { a,b };
	string line;
	set<string> list;
	int cnt = 0;
	cin.ignore();
	while (1) {
		if (!getline(cin, line)) break;
		if (line.empty()) break;
		int hr = stoi(line.substr(0, 2));
		int min = stoi(line.substr(3, 2));
		string name = line.substr(6);
		//cout << hr << ' ' << min << ' ' << name << '\n';
		if (hr < st.first) {
			list.insert(name);
		}
		else if (hr == st.first) {
			if (min <= st.second) list.insert(name);
		}
		if (hr > en.first ||(hr == en.first && min >= en.second)){
			if (hr < en_vi.first || (hr == en_vi.first && min <= en_vi.second)) {
				if (list.find(name) != list.end()) {
					cnt++;
					list.erase(name);
				}
			}
		}
	}
	cout << cnt;
}
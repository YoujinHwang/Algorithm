#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
struct Time {
	long long st, en;
	bool operator<(const Time& r) const {
		return tie(st,en) > tie(r.st,r.en);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<Time> pq1;
	priority_queue<int,vector<int>,greater<>> pq2; //min heap으로 만들기!!
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long s, t;
		cin >> s >> t;
		pq1.push({ s,t });
	}
	
	/*for (auto s : v) {
		cout << s.Y<<' '<<s.X << '\n';
	}*/
	int cnt = 0;
	while (!pq1.empty()) {
		Time nxt = pq1.top();
		pq1.pop();
		//cout << nxt.st << ' ' << nxt.en << '\n';
		if (!pq2.empty()) {
			int cur = pq2.top();
			//cout << "cur: " << cur << '\n';
			if (nxt.st >= cur) {
				pq2.pop();
				pq2.push(nxt.en);
			}
			else {
				pq2.push(nxt.en);
				cnt++;
				//cout << cnt << '\n';
			}
		}
		else {
			pq2.push(nxt.en);
			cnt++;
		}
		
	}
	
	cout << cnt;
	
}
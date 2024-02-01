#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M,x,cnt=0;
	cin >> N >> M;
	deque<int> d;
	for (int i = 1; i <= N; i++) {
		d.push_back(i);
	}
	
	while (M--) {
		cin >> x;
		int half = d.size() / 2;
		int ind = find(d.begin(), d.end(), x) - d.begin();
		//cout << ind << '\n';
		if (ind<=half) {
			while (ind--) {
				d.push_back(d.front());
				d.pop_front();
				cnt++;
			}
			d.pop_front();
			
		}
		else {
			while (d.front()!=x) {
				d.push_front(d.back());
				d.pop_back();
				cnt++;
			}
			d.pop_front();
		}
	}
	cout << cnt << '\n';
}
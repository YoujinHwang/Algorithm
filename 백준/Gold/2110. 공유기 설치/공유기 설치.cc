#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int C, N;
vector<long long> v;
typedef long long ll;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		long long x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	ll ans=0;
	ll start = 1;
	ll en = v[N-1]-v[0];
	int st;
	while (start <= en) {
		int router = 1;
		ll mid = (start + en) / 2;
		//cout << "mid : " << mid << '\n';
		st = v[0];

		for (int i = 1; i < N; i++) {
			if (v[i] - st >= mid) {
				router++;
				//cout<<st<<' ' << v[i]<< '\n';
				st = v[i];
				
			}
		}
		if (router >= C) {
			ans = max(ans, mid);
			start = mid + 1;
			//cout << "start : " << start<<" en : "<<en << '\n';
		}
		else {
			en = mid - 1;
			//cout<<"start: " << start << " en : " << en << '\n';
		}
			
			
	}
	cout << ans;
	return 0;

}
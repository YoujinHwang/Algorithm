#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n_a, n_b;
vector<int> a;
vector<int> b;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> ans;
	cin >> n_a >> n_b;
	for (int i = 0; i < n_a; i++) {
		int A;
		cin >> A;
		a.push_back(A);

	}
	for (int i = 0; i < n_b; i++) {
		int B;
		cin >> B;
		b.push_back(B);

	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i : a) {
		if (!binary_search(b.begin(), b.end(), i)) {
			ans.push_back(i);
			
		}
	}
	if (ans.size() == 0) {
		cout << 0;
	}
	else {
		cout << ans.size() << '\n';
		for (int i : ans) cout << i << ' ';
	}


}